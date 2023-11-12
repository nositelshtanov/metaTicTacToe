//
// Created by nositelshtanov on 11/11/2023.
//

#ifndef TTT_TTT_ENGINE_H
#define TTT_TTT_ENGINE_H

#include <array>
#include <stdexcept>

enum mark {
    nothing,
    zero,
    cross
};

class invalid_coords_error: public std::runtime_error {
public:
    invalid_coords_error(): std::runtime_error("") {}
    explicit invalid_coords_error(const char* msg): std::runtime_error(msg) {}
};

class step_error: public std::runtime_error {
public: enum Reason {
    game_already_end,
    the_field_is_occupied
};
private:
    Reason reason;
public:
    explicit step_error(Reason reason): std::runtime_error(""), reason(reason) {}
     step_error(const char* msg, Reason reason): std::runtime_error(msg), reason(reason) {}
    Reason get_reason() const { return reason; }
};

class ttt_engine {
    std::array<mark, 9> map;
    mark winner;
    int step_count;
public:
    using combination = std::array<std::size_t, 3>;
    const std::array<combination, 8> win_combinations;

    ttt_engine();

    mark get_mark(std::size_t field) const { return map[field]; }
    mark get_winner() const { return winner; }

    void step(mark whose_step, std::size_t field_num);

    bool is_game_end() const { return step_count >= 9 || winner != nothing; }

protected:
    static bool is_same_marks(mark m1, mark m2, mark m3) { return m1 == m2 && m1 == m3 && m2 == m3; }
    mark who_is_winner() const;
};


#endif //TTT_TTT_ENGINE_H
