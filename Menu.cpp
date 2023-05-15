#include "Menu.h"


menu :: menu(){
    cur_rendering_pic = istart1;
}
void menu :: set_pic(indices_ id){
    cur_rendering_pic = id;
}
void menu :: menu_handle_events(SDL_Event event, bool &menu_stage, bool &solo_game_stage, bool &tank_need_create, bool &play_with_bot_stage, bool &running){
    if(!menu_stage) return ;
    int _x, _y;
    Uint32 mouseState = SDL_GetMouseState(&_x, &_y);

    switch(cur_rendering_pic){
        case istart1:
            if (588 <= _x && _x <= 588+222 && 600 <= _y && _y <= 600+73) cur_rendering_pic = istart2;
            else{
                if(853 <= _x && _x <= 853+100 && 585 <= _y && _y <= 585+100 ) cur_rendering_pic = istart3;
            }
            break;
        case istart2:
            if ( !(588 <= _x && _x <= 588+222 && 600 <= _y && _y <= 600+73))  cur_rendering_pic = istart1;
            else{
                if(event.type == SDL_MOUSEBUTTONDOWN){
                    cur_rendering_pic = ioption;
                    sounds[i_button].play_chunk();
                }
            }
            break;
        case istart3:
            if ( 853 <= _x && _x <= 853+100 && 585 <= _y && _y <= 585+100){
                if(event.type == SDL_MOUSEBUTTONDOWN) running = 0;
               // sounds[i_button].play_chunk();
               // else cur_rendering_pic = istart1;
            }
            else cur_rendering_pic = istart1;
            break;
        case ioption:
            if (555 <= _x && _x <= 555+250 && 172 <= _y && _y <= 272) cur_rendering_pic = ioption1;
            else if(555 <= _x && _x <= 555+250 && 300 <= _y && _y <= 400) cur_rendering_pic = ioption2;
            else if(555 <= _x && _x <= 555+250 && 440 <= _y && _y <= 540) cur_rendering_pic = ioption3;
            break;
        case ioption1:
            if(550 <= _x && _x <= 550+260 && 165 <= _y && _y <= 165+110){
                if(event.type == SDL_MOUSEBUTTONDOWN){
                    menu_stage = 0;
                    solo_game_stage = 1;
                    tank_need_create = 1;

                    sounds[i_button].play_chunk();
                }
            }
            else cur_rendering_pic = ioption;
            break;
        case ioption2:
            if(550 <= _x && _x <= 550+260 && 300 <= _y && _y <= 300+110){
                 if(event.type == SDL_MOUSEBUTTONDOWN){
                    sounds[i_button].play_chunk();
                    menu_stage = 0;
                    play_with_bot_stage = 1;
                 }
            }
            else cur_rendering_pic = ioption;
            break;
        case ioption3:
            if(550 <= _x && _x <= 550+260 && 435 <= _y && _y <= 435+110){
                 if(event.type == SDL_MOUSEBUTTONDOWN){
                    //menu_stage = 0;
                    cur_rendering_pic = istart1;
                    sounds[i_button].play_chunk();
                 }
            }
            else cur_rendering_pic = ioption;
            break;
    }

    return ;
}

void menu :: menu_render(bool won){
    if(won) pics[i_win].render();
    pics[cur_rendering_pic].render();
    //pics[istart3].render();
    //cout<<istart3 <<endl;
    return ;
}
