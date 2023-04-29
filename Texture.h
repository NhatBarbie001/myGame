#ifndef    TEXTURE_H
#define    TEXTURE_H

#include "Libs.h"
#include "Globalv.h"

class LTexture
{
	public:
		LTexture();
		~LTexture();


		#if defined(SDL_TTF_MAJOR_VERSION)
		bool loadFromRenderedText(string textureText, SDL_Color textColor );
		#endif

		void free();
		void set_mTextureWH(SDL_Texture* Texture, int mW, int mH);
		void setColor( Uint8 red, Uint8 green, Uint8 blue );
		void setBlendMode( SDL_BlendMode blending );
		void setAlpha( Uint8 alpha );

		void render(int x = 0, int y = 0, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		int getWidth();
		int getHeight();
		SDL_Texture *getTexture();

	private:
		SDL_Texture* mTexture;
		int mWidth;
		int mHeight;
};

#endif //

