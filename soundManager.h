#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include "Libs.h"
//#include "Global_variables.h"

class Lsound{
    private:
        Mix_Music *gMusic;
        Mix_Chunk *gChunk;
    public:
        Lsound();
        void setMusic(Mix_Music *ggMusic);
        void setChunk(Mix_Chunk *ggChunk);
        int play_music(int loops = 0);
        void pause_music();
        int play_chunk(int channel = -1);
        void pause_chunk(int channel = -1);
        void _free();
};


#endif //
