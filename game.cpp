#include "Game.h"
bool game :: init(){
    running = 1;
    menu_stage = 1;
    solo_game_stage = 0;
    tank_need_create = 0;
    gameover1_stage = 0;
    playw_bot_stage = 0;
    bot_menu_stage = 0;
    playw_bot_win = 0;

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
    if(!loadPicFromFile("menu_images/start3.png", istart3))
    {
        printf("Failed to load blue image start3 texture\n");
        success = false;
    }
    if(!loadPicFromFile("menu_images/start2.png", istart1))
    {
        printf("Failed to load blue image start1 texture\n");
        success = false;
    }
    if(!loadPicFromFile("menu_images/start1.png", istart2))
    {
        printf("Failed to load blue image start2 texture\n");
        success = false;
    }
    if(!loadPicFromFile("menu_images/sbb0.png", ioption))
    {
        printf("Failed to load blue option texture\n");
        success = false;
    }
    if(!loadPicFromFile("menu_images/sbb1.png", ioption1))
    {
        printf("Failed to load blue option1 texture\n");
        success = false;
    }
    if(!loadPicFromFile("menu_images/sbb2.png", ioption2))
    {
        printf("Failed to load blue option2 texture\n");
        success = false;
    }
    if(!loadPicFromFile("menu_images/sbb3.png", ioption3))
    {
        printf("Failed to load blue option3 texture\n");
        success = false;
    }

    if(!loadPicFromFile("Tank_images/Blue_tank/Body1.png", iblue_1))
    {
        printf("Failed to load blue body tank1 texture\n");
        success = false;
    }
    if(!loadPicFromFile("Tank_images/Blue_tank/Effects_shoot1.png", igun_blue_1))
    {
        printf("Failed to load blue gun tank1 texture\n");
        success = false;
    }
    if(!loadPicFromFile("Tank_images/Red_tank/Body1.png", ired_1))
    {
        printf("Failed to load Red body tank texture\n");
        success = false;
    }
    if(!loadPicFromFile("Tank_images/Red_tank/Effects_shoot1.png", igun_red_1))
    {
        printf("Failed to load gun red tank texture\n");
        success = false;
    }

    if(!loadPicFromFile("Tank_images/Bullets/Bullet_2.png", ibullet))
    {
        printf("Failed to load gun red tank texture\n");
        success = false;
    }
    if(!loadPicFromFile("something/bg.png", ibg))
    {
        printf("Failed to load back_ground tank texture\n");
        success = false;
    }

    if(!loadPicFromFile("something/effects_shoot_bullet.png", ieffects_bullet))
    {
        printf("Failed to load effects_shoot_bullet tank texture\n");
        success = false;
    }

    if(!loadPicFromFile("something/blood.png", iblood))
    {
        printf("Failed to load blood tank texture\n");
        success = false;
    }

    if(!loadPicFromFile("something/pause1.png", i_gameover1))
    {
        printf("Failed to load pause1 tank texture\n");
        success = false;
    }
    if(!loadPicFromFile("something/pause2.png", i_gameover2))
    {
        printf("Failed to load pause2 tank texture\n");
        success = false;
    }
    if(!loadPicFromFile("something/pause3.png", i_gameover3))
    {
        printf("Failed to load pause3 tank texture\n");
        success = false;
    }

    if(!loadPicFromFile("something/bg2.png", i_bg2))
    {
        printf("Failed to load bg2\n");
        success = false;
    }
    if(!loadPicFromFile("something/shoot_boss0.png", i_effectshoot1))
    {
        printf("Failed to load effectshoot1\n");
        success = false;
    }
     if(!loadPicFromFile("something/shoot_boss1.png", i_effectshoot2))
    {
        printf("Failed to load effectshoot2\n");
        success = false;
    }
     if(!loadPicFromFile("something/surr.png", i_surr))
    {
        printf("Failed to load surrender pic\n");
        success = false;
    }
     if(!loadPicFromFile("something/surr_flag.png", i_surr_flag))
    {
        printf("Failed to load surrender flag pic\n");
        success = false;
    }
     if(!loadPicFromFile("something/win.png", i_win))
    {
        printf("Failed to load win pic\n");
        success = false;
    }

    ///------
    if(!loadWavFromFile("sounds/click_button.wav", i_button)){
        printf("Failed to load button sound\n");
        success = false;
    }
    if(!loadMusFromFile("sounds/MDP.mp3", i_solo)){
        printf("Failed to load music ground solo\n");
        success = false;
    }

    if(!loadMusFromFile("sounds/game_over.mp3", i_gameover)){
        printf("Failed to load music gameover\n");
        success = false;
    }
    if(!loadMusFromFile("sounds/surrender!.mp3", i_surrender)){
        printf("Failed to load music surrender\n");
        success = false;
    }
    if(!loadWavFromFile("sounds/sound_effect_shoot3.wav", i_shoot)){
        printf("Failed to load sound effect shoot \n");
        success = false;
    }
    if(!loadWavFromFile("sounds/moving_sound.wav", i_moving_sound)){
        printf("Failed to load moving sound \n");
        success = false;
    }
    if(!loadWavFromFile("sounds/Explode.wav", i_explode)){
        printf("Failed to explode sound effect sound\n");
        success = false;
    }
    return success;
}
/// 853 585 100 100
void game :: handleEvents(SDL_Event event){
    if(event.type == SDL_QUIT) running = 0;
    Menu.menu_handle_events(event, menu_stage, solo_game_stage, tank_need_create, playw_bot_stage, running);
    if(solo_game_stage){
        if(tank_need_create){
            tank_need_create = 0;
            Tank[0].tank_create(100, 100, iblue_1, igun_blue_1);
            Tank[1].tank_create(int(SCREEN_WIDTH-200), 100, ired_1, igun_red_1);
            sounds[i_solo].play_music(-1);
        }
        Tank[0].tank_handle_event(event, 0);
        Tank[1].tank_handle_event(event, 1);
    }
    else

    if(gameover1_stage){
        menuGameover1.handle_event(event, gameover1_stage, solo_game_stage, tank_need_create, menu_stage, bot_menu_stage, playw_bot_stage);
        if(!gameover1_stage) Mix_HaltMusic();
        if(solo_game_stage){
            Tank[0].tank_reset();
            Tank[1].tank_reset();
        }
        if(menu_stage) Menu.set_pic(ioption);
    } else

    if(playw_bot_stage){
        Tank3.tank_handle_event(event, 0);
    } else

    if(bot_menu_stage){
        menuGameover1.handle_event(event, gameover1_stage, solo_game_stage, tank_need_create, menu_stage, bot_menu_stage, playw_bot_stage);
        if(playw_bot_stage){
            Tank3.tank_reset();
            Bot[0].resett();
            Bot[1].resett();
        }
    }
    return ;
}
void game :: renderGame(){
    Window.window_clearRenderer();

    if(playw_bot_stage){
        pics[i_bg2].render();
        if(!Bot[0]._is_created() || !Bot[1]._is_created()){
            Bot[0].boss_create(1250, 154, i_effectshoot1);
            Bot[1].boss_create(1134, 476, i_effectshoot2);
            Tank3.tank_create(100, 350, iblue_1, igun_blue_1);
            playw_bot_win = 0;
        }

        if(!Bot[0]._is_destroyed()) Bot[0].check_hited(Tank3.get_list_flying_bullet(), 0);
        if(!Bot[1]._is_destroyed()) Bot[1].check_hited(Tank3.get_list_flying_bullet(), 0);
        //Bot[0].check_hited(Tank3.get_list_flying_bullet(), 0);
        //Bot[1].check_hited(Tank3.get_list_flying_bullet(), 0);
        Tank3.check_hited(Bot[0].get_list_flying_bullet());
        Tank3.check_hited(Bot[1].get_list_flying_bullet());

        if(!Bot[0]._is_destroyed()) Bot[0].boss_move(Tank3.get_mCollider());
        if(!Bot[1]._is_destroyed()) Bot[1].boss_move(Tank3.get_mCollider());
        Tank3.tank_move(Bot[0].get_mCollider(),Bot[1].get_mCollider() , 0);

        Tank3.tank_render();
        Bot[0].boss_render();
        if(Bot[1]._is_destroyed()) pics[i_surr].render(1250, 456);
        Bot[1].boss_render();
        if(Bot[0]._is_destroyed()) pics[i_surr].render(1116, 32);

        if(Tank3.is_moving()){
            if(!Mix_Playing(4)) sounds[i_moving_sound].play_chunk(4);
        }
        else if(Mix_Playing(4)) sounds[i_moving_sound].pause_chunk(4);

        if((Bot[0]._is_destroyed() && Bot[1]._is_destroyed() ) || Tank3._is_destroyed()){
            if(!Tank3._is_destroyed()) playw_bot_win = 1;
            bot_menu_stage = 1;
            playw_bot_stage = 0;
        }

    }

    if(bot_menu_stage){
        pics[i_bg2].render();
        Tank3.tank_render();
        Bot[0].boss_render();
        if(Bot[0]._is_destroyed()) pics[i_surr].render(1116, 32);
        Bot[1].boss_render();
        if(Bot[1]._is_destroyed()) pics[i_surr].render(1250, 456);
        menuGameover1.pre_render();
        menuGameover1.render(playw_bot_win);
        if(Mix_Playing(4)) sounds[i_moving_sound].pause_chunk(4);
    }
    if(menu_stage) Menu.menu_render();
    if(solo_game_stage){
        pics[ibg].render();

        Tank[0].check_hited(Tank[1].get_list_flying_bullet());
        Tank[1].check_hited(Tank[0].get_list_flying_bullet());
        Tank[0].tank_move( Tank[1].get_mCollider());
        Tank[1].tank_move( Tank[0].get_mCollider());

        Tank[0].tank_render();
        Tank[1].tank_render();


        ///sound of moving
        if(Tank[0].is_moving()){
            if(!Mix_Playing(4)) sounds[i_moving_sound].play_chunk(4);
        }
        else if(Mix_Playing(4)) sounds[i_moving_sound].pause_chunk(4);


        if(Tank[1].is_moving()){
            if(!Mix_Playing(5)) sounds[i_moving_sound].play_chunk(5);
        }
        else if(Mix_Playing(5)) sounds[i_moving_sound].pause_chunk(5);



        if(Tank[0]._is_destroyed() || Tank[1]._is_destroyed()){

            if(Mix_Playing(4)) sounds[i_moving_sound].pause_chunk(4);
            if(Mix_Playing(5)) sounds[i_moving_sound].pause_chunk(5);

            solo_game_stage = 0;
            gameover1_stage = 1;
            Mix_HaltMusic();
            sounds[i_gameover].play_music();
        }
    }
    if(gameover1_stage){
        pics[ibg].render();
        Tank[0].tank_render();
        Tank[1].tank_render();

        menuGameover1.pre_render();
        menuGameover1.render();
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
    for(int i = 0; i < tot_sound; ++i){
        sounds[i]._free();
    }
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
    return ;
}
