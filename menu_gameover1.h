#ifndef     MENU_GAMEOVER1_H
#define     MENU_GAMEOVER1_H

#include "Libs.h"
#include "Global_variables.h"
#include "consts.h"
#include "Texture.h"


class menu_back_s{
    private:
        indices_ cur_pic;
    public:
        menu_back_s();
        void handle_event(SDL_Event event, bool &gameover1_stage, bool &solo_game_stage, bool &tank_need_create, bool &menu_stage, bool &bot_menu_stage, bool &playw_bot_stage);
       //void handle_event2(SDL_Event event, bool &bot_menu_stage, bool &solo_game_stage, bool &tank_need_create, bool &menu_stage);
        void pre_render();
        void render(bool flag = 0);
};

#endif //
