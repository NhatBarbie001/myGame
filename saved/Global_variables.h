#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H
#include "Libraries.h"
#include "templateTexture.h"
#include "consts.h"

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;

SDL_Texture *loadFromFile(string path);

#endif //
