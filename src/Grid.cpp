#include <iostream>

#include <Globals.h>
#include <Grid.h>

uint16_t one = 1;

#define GetBit(_int, bit) ((_int >> bit) & (one))
#define SetBit(_int, bit) ((_int) |= ((one) << (bit)))

Grid::Grid() {
    side = 0;
    // players[0] = (uint16_t) 0;
    // players[1] = (uint16_t) 0;
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

bool Grid::CheckVictory(int _side) {
    // I could program an algorithm, but it may be faster to hard code the winning arrangements and perform for each one:
    // arranagement & victory arrangement == victory arrangement
    // victory arrangements:
    // three 1s in a row (if the first bit index is a multiple of 3 plus 1) 111000000 000111000 000000111
    // three 1s seperated by 2 bits e.g. 100100100 010010010 001001001
    // three 1s seperated by 3 bits e.g. 100010001
    // three 1s seperated by 1 bit, starting at the 3rd bit e.g. 001010100
    // 8 total winning arrangements of bits
    // i might test the speed of both techniques, if i ever get around to actually creating the algorithm

    assert(side == 0 || side == 1);

    //if (!_side) _side = side; // use the current side if it is not specified
    //if (_side != 0 && _side != 1) return false;

    uint16_t arrangement = players[_side];

    for (uint16_t wa : WinningArrangements) {
        if ((arrangement & wa) == wa) return true;
    }

    return false;
}

bool Grid::MakeMove(int square) {
    if (GetBit(players[0], square) || GetBit(players[1], square)) return false;

    SetBit(players[side], square);
    side ^= one;

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

    if (n_crosses != n_circles && n_crosses != n_circles + 1) {
        std::cout << "Invalid number of crosses/circles, can not set grid" << std::endl;
        return false;
    }

    players[0] = crosses;
    players[1] = circles;

    return true;
}

char characters[4] = { '.', 'x', 'o', '?' };

void Grid::Print() {
    uint16_t empty = !(players[0] | players[1]);

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            uint16_t square = 3 * r + c;

            // I used log base 2 to get the index, but I completely missed that I can just multiply each bit by the character index
            // int charIndex = (int) std::log2(1 + GetBit(empty, square) | (GetBit(players[0], square) << 1) | (GetBit(players[1], square) << 2));

            int charIndex = GetBit(players[0], square) + 2 * GetBit(players[1], square);

            std::cout << " " << characters[charIndex];
        }

        std::cout << std::endl;
    }
}