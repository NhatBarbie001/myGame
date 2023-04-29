#include "consts.h"

SDL_Rect Sprites[20];
void initSprite(){
    Sprites[0].x = Sprites[0].y = 0;
    Sprites[0].w = Sprites[0].h = 128;

    for(int i = 1; i <= 10; ++i){
        Sprites[i] = Sprites[i-1];
        Sprites[i].w += 128;
    }
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
    if( bottomA <= topB ) return 0;

    if( topA >= bottomB ) return 0;

    if( rightA <= leftB ) return 0;

    if( leftA >= rightB ) return 0;

    //If none of the sides from A are outside B
    return true;
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
