#include "boss.h"



boss :: boss(){
    /*
    mgun_deg = 0;
    is_created = 0;
    count_frames_gun = 0;
    done_shoot = 1;
    blood_level = 0;

    is_destroyed = 0;
    last_shoot = 0;
    */
}
double boss :: find_enemy(double x, double y, double a, double b){
    double rt;
    if(a >= x){
        if(b == y) rt = 270;
        else if(b > y) rt = 360-atan((a-x)/(b-y)) * 180.0 / M_PI;
        else rt = 270-atan((y-b)/(a-x)) * 180.0 / M_PI;
    }
    else{
        if(b == y) rt = 90;
        else if(b > y) rt = atan((x-a)/(b-y)) * 180.0 / M_PI;
        else rt = 90+atan((y-b)/(x-a)) * 180.0 / M_PI;
    }
    return rt;
}
void boss :: boss_create(double mX, double mY, int gun_id){
    mPosX = mX;
    mPosY = mY;
    gun_index = gun_id;
    next_gap = 5000;
    is_created = 1;
    //list_flying_bullet.clear();
    //list_noing_bullet.clear();
    last_shoot = SDL_GetTicks();
    done_shoot = 1;
    blood_level = 0;
    is_destroyed = 0;
    count_frames_gun = 0;
    mgun_deg = 0;

    mCollider.x = mX;
    mCollider.y = mY;
    mCollider.w = mCollider.h = 128;
    list_flying_bullet.clear();
    list_noing_bullet.clear();
    return ;
}
void boss :: resett(){
    is_created = 0;
    is_destroyed = 0;
}
void boss :: check_hited( vector<bullets> *other_list_flying_bullet, bool flag){
    for(bullets &it : *other_list_flying_bullet) if(!it.is_counted){
        pair<double, double> tmp_next = next_position((it).x, (it).y, (it).deg, bullet_vel);
        pair<double,double> bullet_rect = xoay(tmp_next.fi+64, tmp_next.sc+16, tmp_next.fi + 64, tmp_next.sc+64, (it).deg);
        SDL_Rect tmp_rect;
        tmp_rect.x = bullet_rect.fi-16;
        tmp_rect.y = bullet_rect.sc-16;
        tmp_rect.w = 32;
        tmp_rect.h = 32;

        SDL_Rect tmp = mCollider;
        if(flag){
            tmp.x += 39;
            tmp.y += 32;
            tmp.w = 49;
            tmp.h = 65;
        }
      //  cout<<"here" <<endl;
        if(!checkCollision(tmp_rect, tmp)){

            if(++blood_level > 6){
                sounds[i_surrender].play_music(0);
                is_destroyed = 1;
            }
            it.is_counted = 1;

            break;
        }
    }
    return ;
}
void boss :: boss_move(SDL_Rect other_mCollision){

    other_mCollision.x += 39;
    other_mCollision.y += 32;
    other_mCollision.w = 49;
    other_mCollision.h = 65;

    Uint32 cur_time = SDL_GetTicks();
    if(!is_destroyed && cur_time-last_shoot >= 3000+next_gap){

        mgun_deg = find_enemy(double(other_mCollision.x+25), double(other_mCollision.y+32), double(mPosX+64), double(mPosY+64));

        next_gap = 1000*((rand()*5+rand()+rand()+rand()+100)%3 );
        last_shoot = cur_time;
        done_shoot = 0;
        count_frames_gun = 0;

        bullets tmp(mPosX, mPosY, mgun_deg);
        list_flying_bullet.push_back(tmp);
        count_frames_gun = 1;
        sounds[i_shoot].play_chunk();
    }


    pair<double, double> bullet_rect;
    SDL_Rect tmp_rect;
    for(vector< bullets >::iterator it = list_flying_bullet.begin(); it != list_flying_bullet.end();){
        pair<double, double> tmp = next_position((*it).x, (*it).y, (*it).deg, bullet_vel);

        double new_X = tmp.first;
        double new_Y = tmp.second;
        bool is_ok = 1;
        if(new_X < 0 || new_X+pics[ibullet].getWidth() > SCREEN_WIDTH) is_ok = 0;
        if(new_Y < 0 || new_Y+pics[ibullet].getHeight() > SCREEN_HEIGHT) is_ok = 0;

        bullet_rect = xoay(new_X+64, new_Y+16, new_X + 64, new_Y+64, (*it).deg);
        tmp_rect.x = bullet_rect.fi-16;
        tmp_rect.y = bullet_rect.sc-16;
        tmp_rect.w = 32;
        tmp_rect.h = 32;

        is_ok &= checkCollision(other_mCollision, tmp_rect);
        if(!checkCollision(other_mCollision, tmp_rect))  sounds[i_explode].play_chunk();
        for(int i = 0; i < tot_wall; ++i){
            is_ok &= checkCollision(tmp_rect, Walls[i]);
        }

        (*it).x = new_X;
        (*it).y = new_Y;
        if(is_ok){
            ++it;
        }
        else{
            list_noing_bullet.push_back((*it));
            it = list_flying_bullet.erase(it);
        }
    }
    for(vector< bullets >::iterator it = list_noing_bullet.begin(); it != list_noing_bullet.end();){
        if(++(*it).count_frames > 35) it = list_noing_bullet.erase(it);
        else ++it;
    }
    return ;
}

void boss :: boss_render(){
    if(count_frames_gun != 0){
        if(++count_frames_gun > 35) count_frames_gun = 0;
    }
    pics[iblood].render( (int)mPosX, (int)mPosY, &Sprites[blood_level]);

    if(done_shoot){
        pics[gun_index].render( (int)mPosX, (int)mPosY, &Sprites[0], mgun_deg);
    }
    else{
        pics[gun_index].render( (int)mPosX, (int)mPosY, &Sprites[count_frames_gun/5], mgun_deg);
    }
    if(!is_destroyed){
        for(bullets it : list_flying_bullet){
            pics[ibullet].render((it).x, (it).y, NULL, (it).deg);
        }
        for(bullets it : list_noing_bullet)  pics[ieffects_bullet].render((it).x, (it).y, &Sprites[(it).count_frames/5], (it).deg);
    }
    return ;
}
vector<bullets>* boss :: get_list_flying_bullet(){
    return &list_flying_bullet;
}
bool boss ::  _is_destroyed(){
    return is_destroyed;
}
bool boss ::  _is_created(){
    return is_created;
}
SDL_Rect boss :: get_mCollider(){
    return mCollider;
}

