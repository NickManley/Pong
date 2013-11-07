#ifndef PONG_CONSTANTS_H
#define	PONG_CONSTANTS_H

#include <SDL/SDL.h>

namespace Pong {
    const char WINDOW_TITLE[] = "Pong";
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;
    const int SCOREBOARD_FONT_SIZE = 32;
    const int PADDLE_WIDTH = 15;
    const int PADDLE_HEIGHT = 100;
    const int PADDLE_SPEED = 300;
    const int MAX_FRAME_RATE = 120;
    const int PADDLE_CENTER = WINDOW_HEIGHT / 2 - PADDLE_HEIGHT /2;
    const int BALL_WIDTH = 12;
    const int BALL_HEIGHT = 12;
    const int BALL_CENTER_X = WINDOW_WIDTH / 2 - BALL_WIDTH / 2;
    const int BALL_CENTER_Y = WINDOW_HEIGHT / 2 - BALL_HEIGHT / 2;
    const int BALL_SPEED_X = -450;
    const int BALL_MIN_SPEED_Y = -50;
    const int BALL_MAX_SPEED_Y = 50;
    const float BALL_BOUNCE_ANGLE = 15.0;
    
    enum WindowEdge { TOP, BOTTOM, LEFT, RIGHT };
}

#endif	/* PONG_CONSTANTS_H */

