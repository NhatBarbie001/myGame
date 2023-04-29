#ifndef     BACK_GROUND_H
#define     BACK_GROUND_H
#include "Libs.h"
#include "consts.h"
#include "Globalv.h"
#include "Texture.h"

class background{
    public:
        void bg_render();
        void bg_change_status();//(SDL_Event event);
        background();
    private:
        bool is_on_game_running_stage;
        int cur_pic;

};

#endif //
