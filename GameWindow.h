#ifndef PONG_GAMEWINDOW_H
#define	PONG_GAMEWINDOW_H

#include <string>
#include <SDL/SDL.h>
#include "Paddle.h"
#include "Ball.h"
#include "Scoreboard.h"

namespace Pong {

    class GameWindow {
    public:
        GameWindow();
        void show();
        void onKeyboardEvent(SDL_KeyboardEvent &kbEvent);
        virtual ~GameWindow();
    private:
        void update();
        Sint16 ballPaddleOffset(Ball &ball, Paddle &paddle);
        SDL_Surface *screen;
        Paddle leftPaddle;
        Paddle rightPaddle;
        Scoreboard scoreboard;
        Ball ball;
        bool downKeyPressed, upKeyPressed;
        Uint16 frameRate;
        Uint32 frameCount;
    };

}

#endif	/* PONG_GAMEWINDOW_H */

