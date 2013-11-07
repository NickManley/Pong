#ifndef PONG_PADDLE_H
#define	PONG_PADDLE_H

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include "Constants.h"

namespace Pong {

    class Paddle {
    public:
        Paddle();
        Paddle(Sint16 width, Sint16 height,
                Sint16 posx, Sint16 posy,
                Uint8 r, Uint8 b, Uint8 g, Uint8 a);
        void setSize(Sint16 width, Sint16 height);
        void setPosition(float posx, float posy);
        void setColor(Uint8 r, Uint8 b, Uint8 g, Uint8 a);

        float getSpeed() const;
        
        /**
         * Set how fast the paddle moves.
         * @param speed
         * The number of pixels to move
         * the paddle if the arrow key is held down
         * for 1000 milliseconds.
         */
        void setSpeed(float speed);
        
        bool atEdge(WindowEdge edge) const;
        void move(float x, float y);
        void show(SDL_Surface *surface);
        SDL_Rect getRect();
        SDL_Rect getCenterRect();
        virtual ~Paddle();
    private:
        Sint16 width, height;
        float posx, posy;
        Uint8 r, g, b, a;
        float speed;
    };

}

#endif	/* PONG_PADDLE_H */

