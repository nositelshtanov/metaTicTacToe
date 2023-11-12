//
// Created by nositelshtanov on 11/11/2023.
//

#include "ttt_meta_session.h"
#include "ttt_simple_session.h"

#define TTT_SMPL_VARIANT "1 - play simple tic tac toe"
#define TTT_META_VARIANT "2 - play meta (super) tic tac toe"
#define TTT_RULES "coordinate is a number from 0 to 8:\n" \
                  "(0) (1) (2)\n" \
                  "(3) (4) (5)\n" \
                  "(6) (7) (8)\n"

#define SIMPLE_TTT 1
#define META_TTT 2

void print_greeting() {
    std::cout << TTT_RULES << std::endl;
    std::cout << TTT_SMPL_VARIANT << std::endl;
    std::cout << TTT_META_VARIANT << std::endl;
}

int main() {
    print_greeting();
    try {
        int game_king;
        std::cout << "game kind:";
        std::cin >> game_king;
        if (game_king == SIMPLE_TTT) {
            ttt_simple_session game;
            game.play();
        } else if (game_king == META_TTT) {
            ttt_meta_session game;
            game.play();
        } else {
            std::cout << "unknown game type" << std::endl;
        }
    } catch (const std::exception& excp) {
        std::cout << "sorry, an error was occured\n" << excp.what() << std::endl;
        return 1;
    }
    return 0;
}