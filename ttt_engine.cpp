//
// Created by nositelshtanov on 11/11/2023.
//

#include "ttt_engine.h"

ttt_engine::ttt_engine() : map{
        nothing, nothing, nothing,
        nothing, nothing, nothing,
        nothing, nothing, nothing
    },
    winner(nothing),
    step_count(0),
    win_combinations{
           0, 1, 2,
           3, 4, 5,
           6, 7, 8,
           0, 3, 6,
           1, 4, 7,
           2, 5, 8,
           2, 4, 6,
           0, 4, 8
    } {}

void ttt_engine::step(mark whose_step, std::size_t field_num) {
    if (winner != nothing || is_game_end()) throw step_error{"game is end", step_error::Reason::game_already_end};
    if (map[field_num] != nothing) throw step_error{step_error::Reason::the_field_is_occupied};
    if (field_num > 8) throw invalid_coords_error();

    map[field_num] = whose_step;
    ++step_count;

    winner = who_is_winner();
    if (winner != nothing) whose_step = nothing;
}

mark ttt_engine::who_is_winner() const {
    for (combination comb : win_combinations) {
        if (is_same_marks(map[comb[0]], map[comb[1]], map[comb[2]]) && map[comb[0]] != nothing) {
            return map[comb[0]];
        }
    }
    return nothing;
}