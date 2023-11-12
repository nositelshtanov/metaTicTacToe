//
// Created by nositelshtanov on 11/11/2023.
//

#include <iostream>
#include "ttt_simple_session.h"

void ttt_simple_session::play() {
    mark winner;
    while ((winner = game.get_winner()) == nothing && !game.is_game_end()) {
        size_t field_num;
        mark whose_step = game.get_whose_step();
        draw_map();
        if (whose_step == cross) {
            std::cout << SMPL_INVITATION_X;
        }
        else {
            std::cout << SMPL_INVITATION_O;
        }
        std::cin >> field_num;
        try {
            game.step(field_num);
        } catch (const invalid_coords_error& err) {
            std::cout << SMPL_INVALID_COORDS_HNDL << std::endl;
        } catch (const step_error& err) {
            if (err.get_reason() == step_error::Reason::the_field_is_occupied) std::cout << SMPL_FIELD_IS_OCCUPIED_HNDL << std::endl;
            else throw;
        }
    }
    draw_map();
    if (winner == cross) {
        std::cout << SMPL_WIN_PHRASE_X << std::endl;
    }
    else if (winner == zero) {
        std::cout << SMPL_WIN_PHRASE_O << std::endl;
    }
    else {
        std::cout << SMPL_DRAW_PHRASE << std::endl;
    }
}

void ttt_simple_session::draw_map() {
    for (std::size_t i{0}; i < 9; ++i) {
        mark cur = game.get_mark(i);
        std::cout << (cur == cross ? SMPL_CROSS_CELL : cur == zero ? SMPL_ZERO_CELL : SMPL_NOTHING_CELL );
        if ((i+1) % 3 == 0) std::cout << std::endl;
    }
}