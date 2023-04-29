#ifndef GAME_H
#define GAME_H

#include "Menu.h"
#include "Globalv.h"
#include "Libs.h"
#include "Texture.h"
#include "window.h"
#include "consts.h"
#include "Tank.h"
#include "back_ground.h"

class game{
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
        bool running;
        tank Tank[2];
        background Background;

};

#endif
