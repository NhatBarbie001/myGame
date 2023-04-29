#ifndef MENU_H
#define MENU_H

#include "Global_variables.h"
#include "templateTexture.h"
class menu{
    public:
        menu();
        ~menu();

        bool menu_loadMedia();
        void menu_render();
        void menu_handle_events(SDL_Event event);
        void menu_close();
    private:
        bool is_on_menu_appearing_stage;
        int curently_rendering_pic;
        LTexture menu_pics[10];
};

#endif //
