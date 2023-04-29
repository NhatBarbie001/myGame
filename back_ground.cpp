#include "back_ground.h"


background :: background(){
    is_on_game_running_stage = 0;
    cur_pic = ibg;
}
void background :: bg_render(){
    //cout<<is_on_game_running_stage <<endl;
    if(is_on_game_running_stage){
        pics[ibg].render();
    }
    else{

    }
    return ;
}

void background :: bg_change_status(){//(SDL_Event event){
    is_on_game_running_stage ^= 1;
   // cur_pic = igameover;
    return ;
}
