#pragma once

#include <cstdint>

const uint16_t WinningArrangements[8] = {
    0b111000000, 0b000111000, 0b000000111,
    0b100100100, 0b010010010, 0b001001001,
    0b100010001,
    0b001010100
};

#define Invalid -1

class Grid {
    public:

    Grid();
    
    int side;

    uint16_t players[2];

    bool MakeMove(int square);
    bool TakeMove(int square);
    bool IsWinnable(int _side);
    bool SetGrid(uint16_t crosses, uint16_t circles);
    bool CheckVictory();
    bool IsFilled();

    void Clear();
    void Print();
};