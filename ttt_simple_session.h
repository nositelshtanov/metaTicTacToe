//
// Created by nositelshtanov on 11/11/2023.
//

#ifndef TTT_TTT_SIMPLE_SESSION_H
#define TTT_TTT_SIMPLE_SESSION_H

#include "ttt_simple.h"

#define SMPL_INVITATION_X "step X:"
#define SMPL_INVITATION_O "step O:"

#define SMPL_WIN_PHRASE_X "win X!!!"
#define SMPL_WIN_PHRASE_O "win O!!!"
#define SMPL_DRAW_PHRASE "draw!!!"

#define SMPL_NOTHING_CELL "( )"
#define SMPL_CROSS_CELL " X "
#define SMPL_ZERO_CELL " O "

#define SMPL_INVALID_COORDS_HNDL "Invalid coords. Try arain"
#define SMPL_FIELD_IS_OCCUPIED_HNDL "The field is already occupied"

class ttt_simple_session {
    ttt_simple game;
public:
    void play();
    void draw_map();
};


#endif //TTT_TTT_SIMPLE_SESSION_H
