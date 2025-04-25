#include <iostream>

#include <Globals.h>
#include <Surch.h>

void GenerateMoves(Grid& grid, MoveList* list) {
    uint16_t empty_squares = ~(grid.players[0] | grid.players[1]);

    list->length = 0;
    
    for (int square = 0; square < 9; square++) {
        if (GetBit(empty_squares, square)) {
            list->moves[list->length] = square;
            list->length++;
        }
    }
}

// int FindOutcome(Grid& grid, int move, int side_to_move, int sign) {
    // grid.MakeMove(move);
    // //grid.Print();

    // if (grid.CheckVictory()) {
    //     grid.TakeMove(move);
    //     //grid.Print();
    //     return grid.side == side_to_move ? 1 : -1;
    // }

    // MoveList list[1];
    // GenerateMoves(grid, list);

    // int n_moves = list->length;
    // if (!n_moves) {
    //     grid.TakeMove(move);
    //     //grid.Print();
    //     return 0;
    // }

//     int outcome = -1;

//     for (int i = 0; i < n_moves; i++) {
//         int _outcome = sign * FindOutcome(grid, list->moves[i], side_to_move, -sign);

//         if (_outcome == 1) {
//             grid.TakeMove(move);
//             //grid.Print();
//             return _outcome;
//         }

//         if (_outcome > outcome) outcome = _outcome;
//     }

//     grid.TakeMove(move);
//     //grid.Print();

//     return outcome; // -1: opponent wins, 1: side to move wins, 0: draw
// }

// int Search(Grid& grid) {
//     MoveList list[1];
//     GenerateMoves(grid, list);

//     int draws[9];
//     int n_draws = 0;

//     int side_to_move = grid.side;

//     for (int i = 0; i < list->length; i++) {
//         int move = list->moves[i];

//         std::cout << "Checking move: " << move << std::endl;

//         int outcome = FindOutcome(grid, move, side_to_move, -1);

//         std::cout << "Outcome: " << outcome << std::endl;

//         if (outcome == 1) return move;

//         if (outcome == 0) {
//             draws[n_draws] = move;
//             n_draws++;
//         }
//     }

//     if (n_draws) return draws[0];
    
//     return list->moves[0];
// }

int MinMax(Grid& grid, int move, int side_to_move) {
    grid.MakeMove(move);
    //grid.Print();

    if (grid.CheckVictory()) {
        grid.TakeMove(move);
        //grid.Print();
        return grid.side == side_to_move ? 1 : -1;
    }

    MoveList list[1];
    GenerateMoves(grid, list);

    int n_moves = list->length;
    if (!n_moves) {
        grid.TakeMove(move);
        //grid.Print();
        return 0;
    }
    
    if (grid.side == side_to_move) {
        int value = -1;

        for (int i = 0; i < n_moves; i++) {
            value = std::max(value, MinMax(grid, list->moves[i], side_to_move));
            if (value == 1) {
                grid.TakeMove(move);
                return value;
            }
        }

        grid.TakeMove(move);
        return value;
    }
    else {
        int value = 1;

        for (int i = 0; i < n_moves; i++) {
            value = std::min(value, MinMax(grid, list->moves[i], side_to_move));
            if (value == -1) {
                grid.TakeMove(move);
                return value;
            }
        }

        grid.TakeMove(move);
        return value;
    }
}

int Search(Grid& grid) {
    MoveList list[1];
    GenerateMoves(grid, list);

    int draws[9];
    int n_draws = 0;

    int side_to_move = grid.side;

    for (int i = 0; i < list->length; i++) {
        int move = list->moves[i];
        int outcome = MinMax(grid, move, side_to_move);

        if (outcome == 1) return move;

        if (outcome == 0) {
            draws[n_draws] = move;
            n_draws++;
        }
    }

    if (n_draws) return draws[0];
    
    return list->moves[0];
}