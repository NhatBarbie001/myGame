#include "Game.h"
bool game :: init(){
    running = 1;
    if(!Window.window_init()){
        cout<<"can't build window!";
        return 0;
    }
    initSprite_Wall();
    return 1;
}

bool game :: is_running(){
    return running;
}

bool game :: loadMedia(){
    bool success = true;
    if(!Window.window_loadFromFile("Tank_and_solder.png", iWelcome)){
        cout<<"Failed to load menu Tank_and_solder texture\n";
        success = 0;
    }
    if(!Window.window_loadFromFile("Tank_and_solder2.png", iWelcome2)){
        cout<<"Failed to load menu Tank_and_solder2 texture\n";
        success = 0;
    }

    if(!Window.window_loadFromFile("Tank_images/Blue_tank/Body1.png", iblue_1))
    {
        printf("Failed to load blue body tank1 texture\n");
        success = false;
    }
    if(!Window.window_loadFromFile("Tank_images/Blue_tank/Effects_shoot1.png", igun_blue_1))
    {
        printf("Failed to load blue gun tank1 texture\n");
        success = false;
    }
    if(!Window.window_loadFromFile("Tank_images/Red_tank/Body1.png", ired_1))
    {
        printf("Failed to load Red body tank texture\n");
        success = false;
    }
    if(!Window.window_loadFromFile("Tank_images/Red_tank/Effects_shoot1.png", igun_red_1))
    {
        printf("Failed to load gun red tank texture\n");
        success = false;
    }

    if(!Window.window_loadFromFile("Tank_images/Bullets/Bullet_2.png", ibullet))
    {
        printf("Failed to load gun red tank texture\n");
        success = false;
    }
    if(!Window.window_loadFromFile("bg.png", ibg))
    {
        printf("Failed to load back_ground tank texture\n");
        success = false;
    }
    if(!Window.window_loadFromFile("game_over.png", igameover))
    {
        printf("Failed to load gameover_pic tank texture\n");
        success = false;
    }
    if(!Window.window_loadFromFile("effects_shoot_bullet.png", ieffects_bullet))
    {
        printf("Failed to load effects_shoot_bullet tank texture\n");
        success = false;
    }

    if(!Window.window_loadFromFile("blood.png", iblood))
    {
        printf("Failed to load blood tank texture\n");
        success = false;
    }
    return success;
}

void game :: handleEvents(SDL_Event event){
    if(event.type == SDL_QUIT) running = 0;

    Menu.menu_handle_events(event);
    if(Menu._is_on_menu_delaying_stage()){
        if(!Tank[0]._is_created()){
            //initSprite_Wall();
            Tank[0].tank_create(100, 100, iblue_1, igun_blue_1);
            Tank[1].tank_create(double(SCREEN_WIDTH-200), 100, ired_1, igun_red_1);
            Background.bg_change_status();
        }
    }
    else if(Tank[0]._is_created()){
        if(Tank[0]._is_destroyed() || Tank[0]._is_destroyed()){

        }
        else{
            Tank[0].tank_handle_event(event, 0);
            Tank[1].tank_handle_event(event, 1);
        }
    }
    return ;
}
void game :: renderGame(){
    initSprite_Wall();
    Window.window_clearRenderer();

    Menu.menu_render();
    Menu.menu_pre_render();

    if(Tank[0]._is_created() && !Menu._is_on_menu_delaying_stage()){
        if(Tank[0]._is_destroyed() || Tank[1]._is_destroyed()){
            Background.bg_render();
            Tank[0].tank_render();
            Tank[1].tank_render();
            pics[igameover].render(300, 200);
            //cout<<"!!!!!!!!!!!!!!!!!!!" <<endl;
        }
        else{
               // cout<<"----------" <<endl;
            Background.bg_render();
            Tank[0].check_hited(Tank[1].get_list_flying_bullet());
            Tank[1].check_hited(Tank[0].get_list_flying_bullet());
            Tank[0].tank_move( Tank[1].get_mCollider());
            Tank[1].tank_move( Tank[0].get_mCollider());

            Tank[0].tank_render();
            Tank[1].tank_render();
        }
    }

    Window.window_renderPresent();
    return ;
}

void game :: close()
{
    Window.window_close();
    for(int i = 0; i < tot_pics; ++i){
        pics[i].free();
    }
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
    return ;
}
