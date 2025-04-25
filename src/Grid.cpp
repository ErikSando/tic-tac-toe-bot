#include <iostream>

#include <Globals.h>
#include <Grid.h>

Grid::Grid() {
    Clear();
}

// Brian Kernighan's algorithm
inline int NumberOfBits(int n) {
    int count = 0;
    
    while (n != 0) {
        n &= (n - 1);
        count++;
    }

    return count;
}

bool Grid::CheckVictory() {
    uint16_t arrangement = players[side ^ 1];

    for (uint16_t wa : WinningArrangements) {
        if ((arrangement & wa) == wa) return true;
    }

    return false;
}

bool Grid::IsFilled() {
    uint16_t empty_squares = ~(players[0] | players[1] | 0b1111111000000000);

    if (!empty_squares) return true;
    return false;
}

bool Grid::MakeMove(int square) {
    if (GetBit(players[0], square) || GetBit(players[1], square)) return false;

    SetBit(players[side], square);
    side ^= 1;

    return true;
}

bool Grid::TakeMove(int square) {
    if (!GetBit(players[0], square) && !GetBit(players[1], square)) return false;

    side ^= 1;
    ClearBit(players[side], square);

    return true;
}

bool Grid::IsWinnable(int side) {


    return false;
}

bool Grid::SetGrid(uint16_t crosses, uint16_t circles) {
    if (crosses & circles != 0) {
        std::cout << "Overlap between circles and crosses, can not set grid" << std::endl;
        return false;
    }

    int n_crosses = NumberOfBits(crosses);
    int n_circles = NumberOfBits(circles);

    int _side = (n_crosses - n_circles) + 1;

    if (_side != 1 && _side != 2) {
        std::cout << "Invalid number of crosses/circles, can not set grid" << std::endl;
        return false;
    }

    side = _side - 1;

    players[0] = crosses;
    players[1] = circles;

    return true;
}

void Grid::Clear() {
    side = 0;
    players[0] = (uint16_t) 0;
    players[1] = (uint16_t) 0;
}

char characters[4] = { '.', 'x', 'o', '?' };

void Grid::Print() {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint16_t square = 3 * r + c;

            int charIndex = GetBit(players[0], square) + 2 * GetBit(players[1], square);

            std::cout << " " << characters[charIndex];
        }

        std::cout << std::endl;
    }
}