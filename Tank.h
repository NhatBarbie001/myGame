#ifndef     TANK_H
#define     TANK_H


#include "consts.h"
#include "Globalv.h"
#include "Libs.h"
#include "Texture.h"
#include "window.h"

class tank{
    public:
        const double tank_vel = 3;
        const double bullet_vel = 7;
        const double gun_vel_deg = 2;
        const double body_vel_deg = 3;

        tank();
        void tank_create(double mPosX, double mPosY, int body_id, int gun_id);
        void tank_handle_event(SDL_Event e, bool flag);
        void tank_render();
        void tank_move(SDL_Rect other_);
        bool _is_created();
        bool _is_destroyed();

        void check_hited( vector<bullets> *bullet_list_other);

        vector<bullets>* get_list_flying_bullet();
        SDL_Rect get_mCollider();
 private:

        bool is_created;
        int body_index, gun_index;

		int count_frames_gun;
		bool done_shoot;

		double mPosX, mPosY;
		double mtank_vel;
		//
		bool retrograded;
        double vbody_deg, vgun_deg;
        double mbody_deg, mgun_deg;

        int blood_level;
        bool is_destroyed;

		SDL_Rect mCollider;
		vector< bullets > list_flying_bullet; /// x, y, deg;
		vector< bullets > list_noing_bullet; /// x, y, deg, cout_frames
};

#endif //
