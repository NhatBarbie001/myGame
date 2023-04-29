#ifndef CONSTANT_H
#define CONSTANT_H

#include "Libraries.h"
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;

extern SDL_Rect Sprites[20];
void initsprite();

bool checkCollision( SDL_Rect a, SDL_Rect b );
pair<double,double> next_position(double x, double y, double deg, double vel, bool is_retrograded = 0);

enum indices_tank{
    ibullet,   /// index of ..
    iblue_1 ,
    igun_blue_1,
    iblue_2,
    igun_blue_2,
    iblue_3,
    igun_blue_3,

    ired_1,
    igun_red_1,
    ired_2,
    igun_red_2,
    ired_3,
    igun_red_3,

    tot_pic
};

enum for_menu{
    iWelcome,
    iWelcome_2,
    ipregame,
    ipregame_2,
    tot_menu_pics
};
#endif //
