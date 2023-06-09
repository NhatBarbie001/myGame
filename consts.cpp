#include "Consts.h"

LTexture pics[50];
Lsound sounds[50];
SDL_Rect Sprites[50];
SDL_Rect Walls[20];
SDL_Rect empty_sprite;

int tot_wall;
void initSprite_Wall(){
    empty_sprite = {0, 0, 0, 0};
    Sprites[0].x = Sprites[0].y = 0;
    Sprites[0].w = Sprites[0].h = 128;
    for(int i = 1; i <= 20; ++i){
        Sprites[i] = Sprites[i-1];
        Sprites[i].x += 128;
    }
    Walls[0].x = 205;
    Walls[0].y = 116;
    Walls[0].w = 80;
    Walls[0].h = 80;

    Walls[3].x = 1024;
    Walls[3].y = 113;
    Walls[3].w = 85;
    Walls[3].h = 85;

    Walls[1].x = 621;
    Walls[1].y = 247;
    Walls[1].w = 121;
    Walls[1].h = 46;

    Walls[2].x = 602;
    Walls[2].y =  300;
    Walls[2].w = 135;
    Walls[2].h = 70;

    Walls[4].x = 627;
    Walls[4].y = 484;
    Walls[4].w = 100;
    Walls[4].h = 78;


    tot_wall = 5;

    return ;
}

bool checkCollision( SDL_Rect a, SDL_Rect b ){
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB ) return 1;

    if( topA >= bottomB ) return 1;

    if( rightA <= leftB ) return 1;

    if( leftA >= rightB ) return 1;

    //If none of the sides from A are outside B
    return 0;
}
pair<double,double> next_position(double x, double y, double deg, double vel, bool is_retrograded){
    double rad = (deg/ 180) * M_PI;
    double new_X = x + sin(rad) * vel;
    double new_Y = y - cos(rad) * vel;
    if(is_retrograded){
         new_X = x*2 - new_X;
         new_Y = y*2 - new_Y;
    }
    return make_pair(new_X, new_Y);
}
pair<double, double> xoay(double x, double y, double a, double b, double deg){
    double rad = deg/180 * M_PI;
    double _x = a + (x-a)*cos(rad) - (y-b)*sin(rad);
    double _y = b + (x-a)*sin(rad) + (y-b)*cos(rad);
    return mp(_x, _y);
}

bullets :: bullets (double _x, double _y, double _deg){
    x = _x;
    y = _y;
    deg = _deg;
    count_frames = -1;
    is_counted = 0;
}
