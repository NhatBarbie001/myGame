#ifndef GAME_H
#define GAME_H

#include "Menu.h"
#include "Global_variables.h"
#include "Libs.h"
#include "Texture.h"
#include "window.h"
#include "consts.h"
#include "Tank.h"
#include "menu_gameover1.h"
#include "loadMedia.h"
#include "soundManager.h"
#include "boss.h"

class game : public loadMedia_er{
    public:
        bool init();
        bool loadMedia();
        void close();
        void renderGame();
        void handleEvents(SDL_Event event);
        bool is_running();

    private:
        window Window;
        menu Menu;
        tank Tank[2], Tank3;
        boss Bot[2];

        menu_back_s menuGameover1;

        bool running;
        bool menu_stage;

        bool tank_need_create;
        bool solo_game_stage;
        bool gameover1_stage;

        bool playw_bot_stage;
        bool bot_menu_stage;
        bool playw_bot_win;

};

#endif
