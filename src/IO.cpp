#include <iostream>

#include <Globals.h>

void PrintSquares(uint16_t squares) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            int square = 3 * r + c;
            std::cout << "" << GetBit(squares, square);
        }

        std::cout << std::endl;
    }
}