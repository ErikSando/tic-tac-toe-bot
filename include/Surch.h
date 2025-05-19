#pragma once

#include "Grid.h"

typedef struct {
    int moves[9];
    int length;

} MoveList;

extern int Search(Grid& grid);