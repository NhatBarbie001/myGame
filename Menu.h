
#ifndef     MENU_H
#define     MENU_H

#include "Global_variables.h"
#include "consts.h"
#include "Libs.h"
class menu{
    public:
        menu();
        void menu_handle_events(SDL_Event event, bool &menu_stage, bool &solo_game_stage, bool &tank_need_create, bool &play_with_bot_stage, bool &running);
       // void menu_handle_events2(SDL_Event event, bool &solo_game_stage);
        void menu_render(bool won = 0);
        void set_pic(indices_ id);
    private:
        indices_ cur_rendering_pic;
};

#endif //
