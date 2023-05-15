#ifndef CONSTS_H
#define CONSTS_H

#include "Libs.h"
#include "Texture.h"
#include "soundManager.h"

extern LTexture pics[50];
extern SDL_Rect Sprites[50];
extern Lsound sounds[50];
extern SDL_Rect empty_sprite;

extern SDL_Rect Walls[20];
extern int tot_wall;
void initSprite_Wall();

bool checkCollision( SDL_Rect a, SDL_Rect b );
pair<double,double> next_position(double x, double y, double deg, double vel, bool is_retrograded = 0);

pair<double, double> xoay(double x, double y, double a, double b, double deg);

class bullets{
    public:
        bullets(double _x, double _y, double _deg);
        double x, y, deg;
        int count_frames;
        bool is_counted;
};
enum indices_{
    ibullet,   /// index of ..
    iblue_1 ,
    igun_blue_1,
    iblue_2,
    igun_blue_2,

    ired_1,
    igun_red_1,
    ired_2,
    igun_red_2,

    ibg,
    ieffects_bullet,

    iblood,

    istart1,
    istart2,
    istart3,
    ioption,
    ioption1,
    ioption2,
    ioption3,

    i_gameover1,
    i_gameover2,
    i_gameover3,


    i_bg2,
    i_effectshoot1,
    i_effectshoot2,
    i_surr,
    i_surr_flag,
    i_win,
    tot_pics
};
enum indices_sound{
    i_button,
    i_solo,
    i_boss,
    i_gameover,
    i_shoot,
    i_moving_sound,
    i_explode,
    i_surrender,
    tot_sound
};

#endif //
