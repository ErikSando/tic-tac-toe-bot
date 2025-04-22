#include <iostream>

#include <Grid.h>

int main(int argc, char* argv[]) {
    Grid grid;

    uint16_t crosses = 0b101000010;
    uint16_t circles = 0b010011000;

    bool s = grid.SetGrid(crosses, circles);

    grid.Print();

    return 0;
}