//
// Created by nositelshtanov on 11/11/2023.
//

#ifndef TTT_TTT_META_SESSION_H
#define TTT_TTT_META_SESSION_H

#include <iostream>
#include "ttt_meta.h"

#define META_X_INVITATION_TWO_PARAMS "X step (write two coordinates):"
#define META_O_INVITATION_TWO_PARAMS "O step (write two coordinates):"
#define META_X_INVITATION_ONE_PARAM "X step (write a coordinate):"
#define META_O_INVITATION_ONE_PARAM "O step (write a coordinate):"

#define META_INVALID_COORS_HNDL "Invalid coordinates"
#define META_FIELD_IS_OCCUPIED_HNDL "the field is alredy occupied"

#define META_CROSS_WIN "X wins!!!"
#define META_ZERO_WIN "Draw!!!"
#define META_DRAW "Draw!!!"

#define META_DEVIDER " --------- --------- --------- \n"
#define META_MAP_BORDER "|"
#define META_MAP_CROSS " X "
#define META_MAP_ZERO " O "
#define META_MAP_NOTHING "   "
#define META_MAP_MAY_SELECT "( )"
#define META_CROSS_FILL "XXX"
#define META_ZERO_FILL "OOO"

class ttt_meta_session {
    ttt_meta game;
public:
    void play();
    void draw_map();
private:
    static void print_devider() {
        std::cout << META_DEVIDER;
    }
    void print_ln(std::size_t fields_row);
};


#endif //TTT_TTT_META_SESSION_H
