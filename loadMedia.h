#ifndef LOADMEDIA_H
#define LOADMEDIA_H

#include "Libs.h"
#include "Global_variables.h"
#include "consts.h"
#include "Texture.h"
#include "soundManager.h"


class loadMedia_er{
    private:


    public:
        bool loadPicFromFile(string path, indices_ id);
        bool loadWavFromFile(string path, indices_sound id);
        bool loadMusFromFile(string path, indices_sound id);
};
#endif //
