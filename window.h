#ifndef WINDOW_H
#define WINDOW_H

#include "Libs.h"
#include "Globalv.h"
#include "Texture.h"
#include "consts.h"

class window{
    public:
        //window();
        //~window();

        bool window_init();
        bool window_loadFromFile(string path, int id);
        void window_clearRenderer();
        void window_renderPresent();
        void window_close();

    private:
};

#endif //
