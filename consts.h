#ifndef CONSTS_H
#define CONSTS_H

#include "Libs.h"
#include "Texture.h"

extern LTexture pics[20];

extern SDL_Rect Sprites[20];


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
enum indices_tank{
    ibullet,   /// index of ..
    iblue_1 ,
    igun_blue_1,
    iblue_2,
    igun_blue_2,

    ired_1,
    igun_red_1,
    ired_2,
    igun_red_2,

    iWelcome,
    iWelcome2,

    ibg,
    igameover,

    ieffects_bullet,

    iblood,
    tot_pics
};

#endif //
