#include "Tank.h"

///---------------------

tank :: tank(){
    vbody_deg = vgun_deg = 0;
    mtank_vel= 0;
    mgun_deg = mbody_deg = 0;

    is_created = 0;

    retrograded = 0;
    count_frames_gun = 0;
    done_shoot = 1;
    blood_level = 0;

    is_destroyed = 0;
    last_shoot = 0;

    channel_mov = -5;
}
void tank :: tank_create(double PosX, double PosY, int body_id, int gun_id){
    mPosX = PosX;
    mPosY = PosY;
    body_index = body_id;
    gun_index  = gun_id;

    mCollider.x = PosX;
    mCollider.y = PosY;

    mCollider.h = pics[body_id].getHeight();
    mCollider.w = pics[body_id].getWidth();
    is_created = 1;

    vbody_deg = vgun_deg = 0;
    mtank_vel= 0;
    mgun_deg = mbody_deg = 0;

    //is_created = 0;

    retrograded = 0;
    count_frames_gun = 0;
    done_shoot = 1;
    blood_level = 0;

    is_destroyed = 0;
    list_flying_bullet.clear();
    list_noing_bullet.clear();
    channel_mov = -5;
    return ;
}
bool tank :: _is_created(){
    return is_created;
}
bool tank :: _is_destroyed(){
    return is_destroyed;
}
void tank :: tank_reset(){
    is_destroyed = 0;

    return ;
}
void tank :: set_channel(int tmp){
    channel_mov = tmp;
}
int tank :: get_channel(){
    return channel_mov;
}
vector<bullets>* tank :: get_list_flying_bullet(){
    return &list_flying_bullet;
}

bool tank :: is_moving(){
    return mtank_vel > 0;
}
///---------------------
void tank :: tank_handle_event(SDL_Event e, bool flag){
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        if(!flag)
            switch( e.key.keysym.sym )
            {
                case SDLK_UP:
                    mtank_vel = min(tank_vel, mtank_vel + tank_vel);
                    retrograded = 0;
                break;
                case SDLK_DOWN:
                    mtank_vel = min(tank_vel, mtank_vel + tank_vel);
                    retrograded = 1;
                break;

                case SDLK_LEFT: vbody_deg -= body_vel_deg; break;
                case SDLK_RIGHT: vbody_deg += body_vel_deg; break;
                case SDLK_KP_1: vgun_deg -= gun_vel_deg; break;
                case SDLK_KP_2:
                    {
                        Uint32 cur_time = SDL_GetTicks();
                        if(cur_time-last_shoot < 1000) break;

                        last_shoot = cur_time;
                        done_shoot = 0;
                        count_frames_gun = 0;

                        bullets tmp(mPosX, mPosY, mgun_deg);
                        list_flying_bullet.push_back(tmp);

                        sounds[i_shoot].play_chunk();

                        break;
                    }
                case SDLK_KP_3: vgun_deg += gun_vel_deg; break;
            }
        else
            switch( e.key.keysym.sym ){
                case SDLK_w:
                    mtank_vel = min(tank_vel, mtank_vel + tank_vel);
                    retrograded = 0;
                break;
                case SDLK_s:
                    mtank_vel = min(tank_vel, mtank_vel + tank_vel);
                    retrograded = 1;
                break;

                case SDLK_a: vbody_deg -= body_vel_deg; break;
                case SDLK_d: vbody_deg += body_vel_deg; break;
                case SDLK_g: vgun_deg -= gun_vel_deg; break;
                case SDLK_h:
                    {
                        Uint32 cur_time = SDL_GetTicks();
                        if(cur_time-last_shoot < 1000) break;

                        last_shoot = cur_time;
                        done_shoot = 0;
                        count_frames_gun = 0;

                        bullets tmp(mPosX, mPosY, mgun_deg);
                        list_flying_bullet.push_back(tmp);

                        sounds[i_shoot].play_chunk();

                        break;
                    }
                case SDLK_j: vgun_deg += gun_vel_deg; break;
            }
    }
        else if( e.type == SDL_KEYUP )
        {
            //Adjust the velocity
            if(!flag)
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                        if(mtank_vel != 0) mtank_vel -= tank_vel;
                        retrograded = 0;
                    break;
                    case SDLK_DOWN:
                        if(mtank_vel != 0) mtank_vel -= tank_vel;
                        retrograded = 0;
                    break;

                    case SDLK_LEFT: vbody_deg += body_vel_deg; break;
                    case SDLK_RIGHT: vbody_deg -= body_vel_deg; break;
                    case SDLK_KP_1: vgun_deg += gun_vel_deg; break;
                    case SDLK_KP_3: vgun_deg -= gun_vel_deg; break;
                }
            else
                switch( e.key.keysym.sym )
                {
                    case SDLK_w:
                        if(mtank_vel != 0) mtank_vel -= tank_vel;
                        retrograded = 0;
                    break;
                    case SDLK_s:
                        if(mtank_vel != 0) mtank_vel -= tank_vel;
                        retrograded = 0;
                    break;

                    case SDLK_a: vbody_deg += body_vel_deg; break;
                    case SDLK_d: vbody_deg -= body_vel_deg; break;
                    case SDLK_g: vgun_deg += gun_vel_deg; break;
                    case SDLK_j: vgun_deg -= gun_vel_deg; break;
                }
        }
    return ;
}
SDL_Rect tank :: get_mCollider(){
    return mCollider;
}
///---------------------
void tank :: tank_move( SDL_Rect other_mCollision, SDL_Rect other_2, bool flag){


    SDL_Rect tmp;
    if(mtank_vel != 0){
        pair<double,double> new_Pos = next_position(mPosX, mPosY, mbody_deg, mtank_vel, retrograded);


        bool ok = 1;
        mPosX = new_Pos.first;
        mPosX = max(mPosX, double(0));
        mPosX = min(mPosX, double(SCREEN_WIDTH - mCollider.w));
        mCollider.x = (int)mPosX;

        mPosY = new_Pos.second;
        mPosY = max(mPosY, double(0));
        mPosY = min(mPosY, double(SCREEN_HEIGHT - mCollider.h));
        mCollider.y = (int)mPosY;

        tmp = mCollider;
        tmp.x += 48;
        tmp.y += 36;
        tmp.h = tmp.w = 35;
        ok &= checkCollision(tmp, other_mCollision);
        for(int i = 0; i < tot_wall; ++i){
            ok &= checkCollision(tmp, Walls[i]);
        }
        if(!ok){
            new_Pos = next_position(mPosX, mPosY, mbody_deg, mtank_vel, 1-retrograded);
            mPosX = new_Pos.first;
            mCollider.x = (int)mPosX;
            mPosY = new_Pos.second;
            mCollider.y = (int)mPosY;
        }
    }

	mgun_deg += vgun_deg;
	if(mgun_deg > 360) mgun_deg -= 360;
	if(mgun_deg < 0)   mgun_deg += 360;
	mbody_deg += vbody_deg;
	if(mbody_deg > 360) mbody_deg -= 360;
	if(mbody_deg < 0)   mbody_deg += 360;

	if(done_shoot) count_frames_gun = 0;
    else{
        if(++count_frames_gun == 5*8){
            count_frames_gun = 0;
            done_shoot = 1;
        }
    }

    if(flag){
        other_mCollision.x += 39;
        other_mCollision.y += 32;
        other_mCollision.w = 49;
        other_mCollision.h = 65;
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
        is_ok &= checkCollision(other_2, tmp_rect);

        if(!checkCollision(other_mCollision, tmp_rect))  sounds[i_explode].play_chunk();
        if(!checkCollision(other_2, tmp_rect))  sounds[i_explode].play_chunk();
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

void tank :: check_hited( vector<bullets> *other_list_flying_bullet){
    for(bullets &it : *other_list_flying_bullet) if(!it.is_counted){
        pair<double, double> tmp_next = next_position((it).x, (it).y, (it).deg, bullet_vel);
        pair<double,double> bullet_rect = xoay(tmp_next.fi+64, tmp_next.sc+16, tmp_next.fi + 64, tmp_next.sc+64, (it).deg);
        SDL_Rect tmp_rect;
        tmp_rect.x = bullet_rect.fi-16;
        tmp_rect.y = bullet_rect.sc-16;
        tmp_rect.w = 32;
        tmp_rect.h = 32;

        SDL_Rect tmp = mCollider;
        tmp.x += 39;
        tmp.y += 32;
        tmp.w = 49;
        tmp.h = 65;

        if(!checkCollision(tmp_rect, tmp)){
            if(++blood_level > 6) is_destroyed = 1;
            it.is_counted = 1;
            break;
        }

    }
    return ;
}
///---------------------

void tank :: tank_render(){
    if(is_destroyed) pics[i_surr_flag].render(mPosX, mPosY);
    pics[body_index].render( (int)mPosX, (int)mPosY, NULL, mbody_deg);
    pics[iblood].render( (int)mPosX, (int)mPosY, &Sprites[blood_level]);
    if(done_shoot){
        pics[gun_index].render( (int)mPosX, (int)mPosY, &Sprites[0], mgun_deg);
    }
    else{
        pics[gun_index].render( (int)mPosX, (int)mPosY, &Sprites[count_frames_gun/5], mgun_deg);
    }
    for(bullets it : list_flying_bullet){
        pics[ibullet].render((it).x, (it).y, NULL, (it).deg);
    }
    for(bullets it : list_noing_bullet)  pics[ieffects_bullet].render((it).x, (it).y, &Sprites[(it).count_frames/5], (it).deg);
    if(is_destroyed) pics[i_surr_flag].render(mPosX, mPosY);
    return ;
}

