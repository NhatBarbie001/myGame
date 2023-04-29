#include "Menu.h"


menu :: menu(){
    is_on_menu_appearing_stage = 1;
    is_on_menu_delaying_stage = 0;
    count_frames = 0;
    curently_rendering_pic = iWelcome;
}

bool menu ::  _is_on_menu_appearing_stage(){
    return is_on_menu_appearing_stage;
}

bool menu :: _is_on_menu_delaying_stage(){
    return is_on_menu_delaying_stage;
}

void menu :: menu_pre_render(){
    if(!is_on_menu_delaying_stage) return ;
    if(++count_frames > 5) curently_rendering_pic = iWelcome;
    if(count_frames > 30) is_on_menu_appearing_stage = is_on_menu_delaying_stage = 0;
    return ;
}
void menu :: menu_handle_events(SDL_Event event){
    if(is_on_menu_delaying_stage) return ;
    if(!is_on_menu_appearing_stage) return ;
    if(curently_rendering_pic == iWelcome){
        if(event.type == SDL_MOUSEBUTTONDOWN){
            int _x = event.button.x;
            int _y = event.button.y;
            if (600 <= _x && _x <= 600+240 && 550 <= _y && _y <= 550+125)  curently_rendering_pic = iWelcome2;
        }
    }
    else if(curently_rendering_pic == iWelcome2){
        if(event.type == SDL_MOUSEBUTTONUP){
            int _x = event.button.x;
            int _y = event.button.y;
            if (600 <= _x && _x <= 600+240 && 550 <= _y && _y <= 550+125){
                is_on_menu_delaying_stage = 1;
            }
            else curently_rendering_pic = iWelcome;
        }
    }
    return ;
}

void menu :: menu_render(){
    if(is_on_menu_appearing_stage) pics[curently_rendering_pic].render();
    return ;
}
