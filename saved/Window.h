#ifndef WINDOW_H
#define WINDOW_H

#include "Libraries.h"
#include "Global_variables.h"

class window{
    public:
        window();
        ~window();

        bool window_init();

        SDL_Texture* window_loadFromFile(std::string path);
        void window_clearRenderer();
        void window_renderPresent();
        void window_close();

    private:
};

#endif //
