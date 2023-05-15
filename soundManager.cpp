#include "soundManager.h"

Lsound :: Lsound(){
    gMusic = NULL;
    gChunk = NULL;
}
void  Lsound :: setMusic(Mix_Music *ggMusic){
    gMusic = ggMusic;
    return ;
}
void Lsound :: setChunk(Mix_Chunk *ggChunk){
    gChunk = ggChunk;
    return ;
}
int Lsound :: play_music(int loops){
    return Mix_PlayMusic(gMusic, loops);
}
void Lsound :: pause_music(){

}
int Lsound :: play_chunk(int channel){
    return Mix_PlayChannel( channel, gChunk, 0 );
}

void Lsound :: pause_chunk(int channel){
    Mix_HaltChannel(channel);
}
void Lsound :: _free(){
    Mix_FreeChunk( gChunk );
    gChunk = NULL;
	//Free the music
	Mix_FreeMusic( gMusic );
	gMusic = NULL;
	return ;
}
