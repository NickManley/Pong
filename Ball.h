#ifndef PONG_BALL_H
#define	PONG_BALL_H

#include "Constants.h"
#include <SDL/SDL_gfxPrimitives.h>

namespace Pong {

    class Ball {
    public:
        Ball();
        Ball(const Ball &orig);
        void show(SDL_Surface *surface);
        SDL_Rect getRect();
        SDL_Rect getCenterRect();
        void setPosition(float x, float y);
        float getSpeedX() const;
        void setSpeedX(float speed);
        float getSpeedY() const;
        void setSpeedY(float speed);
        void setRandomSpeedY();
        void move(float x, float y);
        bool isTouching(SDL_Rect rect);
        bool atEdge(WindowEdge edge);
        virtual ~Ball();
    private:
        Sint16 width, height;
        float posx, posy;
        float speedx, speedy;
    };

}

#endif	/* PONG_BALL_H */

