//
// Created by nositelshtanov on 11/11/2023.
//

#include "ttt_meta.h"

void ttt_meta::step(std::size_t map_number, std::size_t field) {
    if (map_number >= map_size) throw invalid_coords_error();
    if (next_map != any_map && map_number != next_map) throw invalid_coords_error();
    if (get_winner() != nothing || is_game_end()) throw step_error{step_error::Reason::game_already_end};
    if (map[map_number].get_winner() != nothing || map[map_number].get_mark(field) != nothing) throw step_error{step_error::Reason::the_field_is_occupied};

    map[map_number].step(whose_step, field);

    if (map[map_number].is_game_end())
    {
        mark winner = map[map_number].get_winner();

        if (winner != nothing)
        {
            ttt_engine::step(whose_step, map_number);
        }
    }

    whose_step = whose_step == cross ? zero : cross;

    if (map[field].is_game_end()) { next_map = any_map; }
    else { next_map = field; }
}
