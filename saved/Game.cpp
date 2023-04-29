#include "Game.h"
/*
bool game :: init(){
    running = 1;
    if(!Window.window_init()){
        cout<<"can't build window!";
        return 0;
    }
    return 1;
}
*/
bool game :: is_running(){
    return running = 0;
}
/*
bool game :: loadMedia(){
    bool success = true;
    menu_pics[iWelcome] = loadFromFile("Menu_images/Tank_and_solder");
    if(!menu_pics[iWelcome] == NULL){
        cout<<"Failed to load menu Tank_and_solder texture\n";
        success = 0;
    }
    /*
    tank_pics[iblue_1] = loadFromFile("Tank_images/Blue_tank/body1.png");
    if (tank_pics[iblue_1] == NULL)
    {
        printf("Failed to load blue body tank1 texture\n");
        success = false;
    }
    tank_pics[igun_blue_1] = loadFromFile("Tank_images/Blue_tank/Effects_shoot1.png");
    if (tank_pics[igun_blue_1] == NULL)
    {
        printf("Failed to load blue gun tank1 texture\n");
        success = false;
    }

    tank_pics[ired_1] = loadFromFile("Tank_images/Red_tank/Body1.png");
    if (tank_pics[ired_1] == NULL)
    {
        printf("Failed to load red body tank1 texture\n");
        success = false;
    }
    tank_pics[igun_red_1] = loadFromFile("Tank_images/Red_tank/Effects_shoot1.png");
    if (tank_pics[igun_red_1] == NULL)
    {
        printf("Failed to load red gun tank1 texture\n");
        success = false;
    }
    tank_pics[ibullet] = loadFromFile("Tank_images/Bullets/Bullet_2.png");
    if (tank_pics[ibullet] == NULL)
    {
        printf("Failed to load bullet_tank texture\n");
        success = false;
    }
    */
    /*
    return success;
}

void game :: handleEvents(SDL_Event event){
    Menu.menu_handle_events(SDL_Event event);
    return ;
}
void game :: rederGame(){
    Menu.menu_render();
    return ;
}
void game :: close()
{
    Window.window_close();
    Menu.menu_close();
    SDL_Quit();
    IMG_Quit();
    //TTF_Quit();
    Mix_Quit();
    return ;
}
*/
