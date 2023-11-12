//
// Created by nositelshtanov on 11/11/2023.
//

#include "ttt_meta_session.h"

void ttt_meta_session::play() {
    draw_map();

    while (!game.is_game_end()) {
        size_t x, y;
        mark whose_step = game.get_whose_step();
        size_t map_number = game.get_next_map_number();

        try {
            if (map_number == ttt_meta::any_map) {
                std::cout << (whose_step == zero ? META_O_INVITATION_TWO_PARAMS : META_X_INVITATION_TWO_PARAMS);
                std::cin >> x >> y;
                game.step(x, y);
            }
            else {
                std::cout << (whose_step == zero ? META_O_INVITATION_ONE_PARAM : META_X_INVITATION_ONE_PARAM);
                std::cin >> x;
                game.step(game.get_next_map_number(), x);
            }
        } catch (const invalid_coords_error&) {
            std::cout << META_INVALID_COORS_HNDL << std::endl;
            continue;
        } catch (const step_error& err) {
            if (err.get_reason() == step_error::Reason::the_field_is_occupied) std::cout << META_FIELD_IS_OCCUPIED_HNDL << std::endl;
            else throw;
        }

        draw_map();
    }

    mark winner = game.get_winner();

    if (winner == nothing) { std::cout << META_DRAW << std::endl; }
    else if (winner == cross) { std::cout << META_CROSS_WIN << std::endl; }
    else { std::cout << META_ZERO_WIN << std::endl; }
}

void ttt_meta_session::draw_map() {
    std::size_t i = 0;

    print_devider();

    while (i < ttt_meta::map_size) {
        print_ln(i);
        if ((i + 1) % 3 == 0) { print_devider(); }
        ++i;
    }
}

void ttt_meta_session::print_ln(std::size_t fields_row) {
    const std::size_t mapIdxStart   = 3 * (fields_row / 3);
    const std::size_t mapIdxEnd     = mapIdxStart + 3;
    const std::size_t fieldIdxStart = (3 * fields_row) % 9;
    const std::size_t fieldIdxEnd   = fieldIdxStart + 3;

    std::cout << META_MAP_BORDER;

    for (std::size_t i{ mapIdxStart }; i < mapIdxEnd; ++i) {
        for (std::size_t j{ fieldIdxStart }; j < fieldIdxEnd; ++j) {

            mark cur_mark = game.get_mark(i, j);
            mark winner   = game.get_mark(i).get_winner();

            if (winner == nothing) {
                std::cout << (
                        cur_mark == cross ?
                        META_MAP_CROSS :
                        cur_mark == zero ?
                        META_MAP_ZERO :
                        i == game.get_next_map_number() || game.get_next_map_number() == ttt_meta::any_map ?
                        META_MAP_MAY_SELECT:
                        META_MAP_NOTHING
                );
            }
            else if (winner == cross) {
                std::cout << META_CROSS_FILL;
            }
            else {
                std::cout << META_ZERO_FILL;
            }
        }
        std::cout << META_MAP_BORDER;
    }
    std::cout << std::endl;
}