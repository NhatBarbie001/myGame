#include "Menu.h"

menu :: menu(){
    is_on_menu_appearing_stage = 1;
    curently_rendering_pic = iWelcome;
}

void menu :: menu_handle_events(SDL_Event event){
    if(curently_rendering_pic == iWelcome){
        if(event.type == SDL_MOUSEBUTTONDOWN){
            int _x = event.button.x;
            int _y = event.button.y;
            if (372 <= _x && _x <= 685 && 372 <= _y && _y <= 500) curently_rendering_pic = ipregame;
        }
    }
    else if(curently_rendering_pic == ipregame){
            is_on_menu_appearing_stage = 0;
    }
    else is_on_menu_appearing_stage = 0;
    return ;
}

void menu :: menu_render(){
    if(is_on_menu_appearing_stage) menu_pics[curently_rendering_pic].render(0, 0);
    return ;
}
void menu :: menu_close(){
    for(int i = 0; i < tot_menu_pics; ++i){
        menu_pics[i].free();
       // menu_pics[i] = NULL;
    }
    return ;
}

menu :: ~menu(){
    menu_close();
}
