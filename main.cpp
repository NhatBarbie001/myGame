#include "game.h"

int main(int argc, char *argv[])
{
    game mGame;
    if(!mGame.init())
    {
        printf("Failed to init\n");
    }
    else
    {
        if(!mGame.loadMedia()) printf("Failed to load media\n");
        else
        {
            SDL_Event event;
            while(mGame.is_running())
            {
                while(SDL_PollEvent(&event)) mGame.handleEvents(event);
                mGame.renderGame();
            }
        }

    }
    mGame.close();

    return 0;
}

