//
// Created by nositelshtanov on 11/11/2023.
//

#ifndef TTT_TTT_SIMPLE_H
#define TTT_TTT_SIMPLE_H

#include "ttt_engine.h"

class ttt_simple: public ttt_engine {
    mark whose_step;
public:
    explicit ttt_simple(mark who_step_first) : whose_step(who_step_first) {}
    ttt_simple() : ttt_simple(cross) {}
    mark get_whose_step() const { return whose_step; }
    void step(std::size_t field_num) {
        ttt_engine::step(whose_step, field_num);
        whose_step = whose_step == cross ? zero : cross;
    }
};

#endif //TTT_TTT_SIMPLE_H
