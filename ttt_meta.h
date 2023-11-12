//
// Created by nositelshtanov on 11/11/2023.
//

#ifndef TTT_TTT_META_H
#define TTT_TTT_META_H

#include "ttt_engine.h"

class ttt_meta: public ttt_engine {
public:
    enum {
        map_size = 9,
        any_map  = map_size
    };
private:
    std::array<ttt_engine, map_size> map;
    mark whose_step;
    std::size_t next_map;
public:
    explicit ttt_meta(mark whose_step_first) : whose_step(whose_step_first), next_map(any_map) {}
    ttt_meta() : ttt_meta(cross) {}

    mark get_mark(std::size_t map_number, std::size_t field) const { return map[map_number].get_mark(field); }
    const ttt_engine& get_mark(std::size_t map_number) const { return map[map_number]; }

    mark get_whose_step() const { return whose_step; }

    void step(std::size_t map_number, std::size_t field);

    std::size_t get_next_map_number() const { return next_map; }
};


#endif //TTT_TTT_META_H
