#include "Ball.h"
#include <cstdlib>
#include <ctime>
#include "Constants.h"

using namespace Pong;

Ball::Ball() {
    this->width = BALL_WIDTH;
    this->height = BALL_HEIGHT;
    this->posx = BALL_CENTER_X;
    this->posy = BALL_CENTER_Y;
    this->speedx = BALL_SPEED_X;
    srand(time(NULL));
    this->speedy = rand() % (BALL_MAX_SPEED_Y - BALL_MIN_SPEED_Y) 
            + BALL_MIN_SPEED_Y;
}

Ball::Ball(const Ball& orig) {
    this->width = orig.width;
    this->height = orig.height;
    this->posx = orig.posx;
    this->posy = orig.posy;
    this->speedx = orig.speedx;
    this->speedy = orig.speedy;
}

void Ball::show(SDL_Surface *surface) {

    boxRGBA(
        surface,
        this->posx, this->posy,
        this->posx + this->width,
        this->posy + this->height,
        255, 255, 255, 255);
}

SDL_Rect Ball::getRect() {
    SDL_Rect rect;
    rect.x = posx;
    rect.y = posy;
    rect.w = width;
    rect.h = height;
    return rect;
}

SDL_Rect Ball::getCenterRect() {
    SDL_Rect rect;
    rect.x = posx + width / 2;
    rect.y = posy + height / 2;
    rect.w = width;
    rect.h = height;
    return rect;
}

void Ball::setPosition(float x, float y) {
    this->posx = x;
    this->posy = y;
}

float Ball::getSpeedX() const {
    return this->speedx;
}

void Ball::setSpeedX(float speed) {
    this->speedx = speed;
}

float Ball::getSpeedY() const {
    return this->speedy;
}

void Ball::setSpeedY(float speed) {
    this->speedy = speed;
}

void Ball::setRandomSpeedY() {
    this->speedy = rand() % (BALL_MAX_SPEED_Y - BALL_MIN_SPEED_Y) 
            + BALL_MIN_SPEED_Y;
}

void Ball::move(float x, float y) {
    this->posx += x;
    this->posy += y;
}

bool Ball::isTouching(SDL_Rect rect) {
    // If any one of the following conditions are true,
    // then the rectangles do NOT overlap

    // Condition 1: Ball bottom edge is higher than Paddle top edge
    const Sint16 ballBottomEdge = this->getRect().y + this->getRect().h;
    const Sint16 paddleTopEdge = rect.y;
    if (ballBottomEdge < paddleTopEdge) {
        return false;
    }

    // Condition 2: Ball top edge is lower than Paddle bottom edge
    const Sint16 ballTopEdge = this->getRect().y;
    const Sint16 paddleBottomEdge = rect.y + rect.h;
    if (ballTopEdge > paddleBottomEdge) {
        return false;
    }

    // Condition 3: Ball left edge is to the right of Paddle right edge
    const Sint16 ballLeftEdge = this->getRect().x;
    const Sint16 paddleRightEdge = rect.x + rect.w;
    if (ballLeftEdge > paddleRightEdge) {
        return false;
    }

    // Condition 4: Ball right edge is to the left of Paddle left edge
    const Sint16 ballRightEdge = this->getRect().x + this->getRect().w;
    const Sint16 paddleLeftEdge = rect.x;
    if (ballRightEdge < paddleLeftEdge) {
        return false;
    }

    return true;
}

bool Ball::atEdge(WindowEdge edge) {
    Sint16 top = this->getRect().y;
    Sint16 bottom = this->getRect().y + this->getRect().h;
    Sint16 left = this->getRect().x;
    Sint16 right = this->getRect().x + this->getRect().w;
    
    if(edge == TOP && top <= 0) {
        return true;
    } else if(edge == BOTTOM && bottom >= WINDOW_HEIGHT) {
        return true;
    } else if(edge == LEFT && left <= 0) {
        return true;
    } else if(edge == RIGHT && right >= WINDOW_WIDTH) {
        return true;
    }
    return false;
}

Ball::~Ball() {
}
