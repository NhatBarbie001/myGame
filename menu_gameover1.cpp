#include "menu_gameover1.h"

menu_back_s :: menu_back_s(){
    cur_pic = i_gameover1;
}

void menu_back_s :: handle_event(SDL_Event event, bool &gameover1_stage, bool &solo_game_stage, bool &tank_need_create, bool &menu_stage, bool &bot_menu_stage, bool &playw_bot_stage){
    int _x, _y;
    Uint32 mouseState = SDL_GetMouseState(&_x, &_y);
    if(event.type == SDL_MOUSEBUTTONDOWN){
        if(500+130 <= _x && _x <= 500+130+136 && 100+233 <= _y && _y <= 100+233+50){
            cur_pic = i_gameover2;
            sounds[i_button].play_chunk();
            if(bot_menu_stage){
                bot_menu_stage = 0;
                playw_bot_stage = 1;
            }
            else{
                gameover1_stage = 0;
                solo_game_stage = 1;
                tank_need_create = 1;
            }
        }
        else{
            if(500+130 <= _x && _x <= 500+130+136 && 100+320 <= _y && _y <= 100+320+50){
                cur_pic = i_gameover3;
                sounds[i_button].play_chunk();

                gameover1_stage = 0;
                bot_menu_stage = 0;
                menu_stage = 1;
            }
        }

    }
    return ;
}
void menu_back_s :: pre_render(){
    int _x, _y;
    Uint32 mouseState = SDL_GetMouseState(&_x, &_y);
    if (500+130 <= _x && _x <= 500+130+136 && 100+233 <= _y && _y <= 100+233+50) cur_pic = i_gameover2;
    else
    if (500+130 <= _x && _x <= 500+130+136 && 100+320 <= _y && _y <= 100+320+50) cur_pic = i_gameover3;
    else cur_pic = i_gameover1;

    return;
}
void menu_back_s :: render(bool flag){
    pics[cur_pic].render(500, 100);
    if(flag) pics[i_win].render(500+32, 100+32);

    return ;
}
