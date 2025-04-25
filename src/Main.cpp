#include <iostream>
#include <string>
#include <bitset>

#include <Globals.h>
#include <Surch.h>

int main(int argc, char* argv[]) {
    Grid grid;

    // uint16_t crosses = 0b101000010;
    // uint16_t circles = 0b010011000;

    //bool s = grid.SetGrid(crosses, circles);

    std::string input;

    for (;;) {
        bool valid_input = false;

        for (;;) {
            input = "";
            std::cout << "Enter side (0 for crosses, 1 for circles): ";
            std::cin >> input;

            if (input == "0") break;

            if (input == "1") {
                std::cout << "Computer is making a move" << std::endl;

                int move = Search(grid);
                grid.MakeMove(move);

                break;
            }
        }

        grid.Print();

        for (;;) {
            input = "";
            std::cout << "Enter square: ";
            std::cin >> input;
            //std::cout << input << std::endl;
            
            int user_move = -1;

            try {
                user_move = std::stoi(input);
            }
            catch (...) {
                std::cout << "Invald input" << std::endl;
                continue;
            }

            if (user_move < 0 || user_move > 8) {
                std::cout << "Invalid square" << std::endl;
                continue;
            }

            grid.MakeMove(user_move);
            grid.Print();

            if (grid.CheckVictory()) {
                std::cout << "You win!" << std::endl;
                break;
            }
            
            if (grid.IsFilled()) {
                std::cout << "Draw." << std::endl;
                break;
            }

            std::cout << "Computer is making a move" << std::endl;

            int move = Search(grid);
            grid.MakeMove(move);
            grid.Print();

            if (grid.CheckVictory()) {
                std::cout << "Computer wins." << std::endl;
                break;
            }
            
            if (grid.IsFilled()) {
                std::cout << "Draw." << std::endl;
                break;
            }
        }

        input = "";
        std::cout << "Play again? (y/n): ";
        std::cin >> input;

        if (input != "y" || input != "Y") break;
    }

    return 0;
}