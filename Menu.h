
#ifndef     MENU_H
#define     MENU_H

#include "Globalv.h"
#include "consts.h"
#include "Libs.h"
class menu{
    public:
        menu();
        void menu_set_pics(SDL_Texture *Texture);

        void menu_render();
        void menu_handle_events(SDL_Event event);
        void menu_close();
        void menu_pre_render();
        bool _is_on_menu_appearing_stage();

        void set_delaying_status();
        bool _is_on_menu_delaying_stage();
    private:
        bool is_on_menu_appearing_stage;
        int  count_frames;

        bool is_on_menu_delaying_stage;
        int curently_rendering_pic;
};

#endif //
