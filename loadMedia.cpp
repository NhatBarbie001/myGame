#include "loadMedia.h"
bool loadMedia_er :: loadPicFromFile(string path, indices_ id){
    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
        printf("Failed to load %s img, error: %s", path.c_str(), IMG_GetError());
    else
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 255, 255));
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL) printf("Failed to create texture %s, error: %s\n", path.c_str(), SDL_GetError());
        else{
            pics[id].set_mTextureWH(newTexture, (loadedSurface ->w), loadedSurface->h);
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture != NULL;
}
bool loadMedia_er :: loadWavFromFile(string path, indices_sound id){
     Mix_Chunk *tmpChunk =  Mix_LoadWAV( path.c_str() );
     sounds[id].setChunk(tmpChunk);
     return tmpChunk != NULL;
}
bool loadMedia_er :: loadMusFromFile(string path, indices_sound id){
    Mix_Music *tmpMusic = Mix_LoadMUS( path.c_str() );
     sounds[id].setMusic(tmpMusic);
     return tmpMusic != NULL;
}
