#ifndef TEMPLATE_TEXTURE_H
#define TEMPLATE_TEXTURE_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
///#include <SDL_ttf.h>

#include <stdio.h>
#include <string>
#include<iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <numeric>
#include <chrono>
#include <random>
#include <functional>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <array>
#include <bitset>
#include <unordered_map>

using namespace std;
extern SDL_Renderer *gRenderer;

class LTexture
{
	public:
		LTexture();
		~LTexture();


		#if defined(SDL_TTF_MAJOR_VERSION)
		bool loadFromRenderedText(string textureText, SDL_Color textColor );
		#endif

		void free();
		void setColor( Uint8 red, Uint8 green, Uint8 blue );
		void setBlendMode( SDL_BlendMode blending );
		void setAlpha( Uint8 alpha );

		void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		int getWidth();
		int getHeight();

	private:
		SDL_Texture* mTexture;
		int mWidth;
		int mHeight;
};

#endif //
