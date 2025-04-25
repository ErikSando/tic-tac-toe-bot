#pragma once

#include <cassert>
#include <cstdint>

#define GetBit(_int, bit) ((_int >> bit) & (1))
#define SetBit(_int, bit) ((_int) |= ((1) << (bit)))
#define ClearBit(_int, bit) ((_int) &= ~((1) << (bit)))

extern void PrintSquares(uint16_t squares);