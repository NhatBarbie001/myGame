#ifndef BOSS_H
#define BOSS_H

#include "consts.h"
#include "Global_variables.h"
#include "Libs.h"
#include "Texture.h"
#include "window.h"


class boss{
    public:
        const double bullet_vel = 10;

        double find_enemy(double x, double y, double a, double b);
        boss();
        void boss_create(double mX, double mY, int gun_id);

        void boss_move(SDL_Rect other_);
        void boss_render();

        bool _is_created();
        bool _is_destroyed();

        void check_hited( vector<bullets> *bullet_list_other, bool flag = 1);

        vector<bullets>* get_list_flying_bullet();
        SDL_Rect get_mCollider();
        void resett();


    private:

        Uint32 next_gap;
        int gun_index;
        int count_frames_gun;
		bool done_shoot;
        double mPosX, mPosY;

        double mgun_deg;

        int blood_level;
        bool is_destroyed, is_created;

        Uint32 last_shoot;

		SDL_Rect mCollider;
		vector< bullets > list_flying_bullet; /// x, y, deg;
		vector< bullets > list_noing_bullet; /// x, y, deg, count_frames
};

#endif //
