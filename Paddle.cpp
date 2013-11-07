#include "Paddle.h"
#include "Constants.h"

using namespace Pong;

Paddle::Paddle() {
    this->width = PADDLE_WIDTH;
    this->height = PADDLE_HEIGHT;
    this->posx = 10;
    this->posy = 10;
    this->r = 255;
    this->g = 255;
    this->b = 255;
    this->a = 255;
    this->speed = PADDLE_SPEED;
}

Paddle::Paddle(Sint16 width, Sint16 height,
                Sint16 posx, Sint16 posy,
                Uint8 r, Uint8 b, Uint8 g, Uint8 a) {
    this->width = width;
    this->height = height;
    this->posx = posx;
    this->posy = posy;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
    this->speed = PADDLE_SPEED;
}

void Paddle::setSize(Sint16 width, Sint16 height) {
    this->width = width;
    this->height = height;
}

void Paddle::setPosition(float posx, float posy) {
    this->posx = posx;
    this->posy = posy;
}

void Paddle::setColor(Uint8 r, Uint8 b, Uint8 g, Uint8 a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

float Paddle::getSpeed() const {
    return this->speed;
}

void Paddle::setSpeed(float speed) {
    this->speed = speed;
}

bool Paddle::atEdge(WindowEdge edge) const {
    Sint16 top = this->posy;
    Sint16 bottom = this->posy + this->height;
    
    if(edge == TOP && top <= 0) {
        return true;
    }
    if(edge == BOTTOM && bottom >= WINDOW_HEIGHT) {
        return true;
    }
    return false;
}

void Paddle::move(float x, float y) {
    this->posx += x;
    this->posy += y;
}

void Paddle::show(SDL_Surface *surface) {
    boxRGBA(
        surface,
        this->posx, this->posy,
        this->posx + this->width,
        this->posy + this->height,
        this->r, this->g, this->b, this->a);
}

SDL_Rect Paddle::getRect() {
    SDL_Rect rect;
    rect.w = width;
    rect.h = height;
    rect.x = posx;
    rect.y = posy;
    return rect;
}

SDL_Rect Paddle::getCenterRect() {
    SDL_Rect rect;
    rect.x = posx + width / 2;
    rect.y = posy + height / 2;
    rect.w = width;
    rect.h = height;
    return rect;
}

Paddle::~Paddle() {
    
}

