#include "GameWindow.h"
#include "Constants.h"

using namespace Pong;

GameWindow::GameWindow() {
    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(
            WINDOW_WIDTH, WINDOW_HEIGHT, 32,
            SDL_SWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(WINDOW_TITLE, 0);
    
    leftPaddle.setPosition(10, PADDLE_CENTER);
    rightPaddle.setPosition(WINDOW_WIDTH - PADDLE_WIDTH - 10,
            PADDLE_CENTER);
    downKeyPressed = false;
    upKeyPressed = false;
    frameRate = MAX_FRAME_RATE;
    frameCount = 0;
}

void GameWindow::show() {
    // Start timer to determine how long this frame takes to draw
    Uint32 start = SDL_GetTicks();
    this->update();
    Uint32 finish = SDL_GetTicks();
    Uint32 time = finish - start;
    
    // It's possible that a frame renders in under 1 ms,
    // thus making time = 0 and causing DivByZero.
    // To avoid this, just set FPS to 1000.
    if(time == 0) {
        frameRate = 1000;
    } else {
        frameRate = 1000 / time;
    }
}

void GameWindow::onKeyboardEvent(SDL_KeyboardEvent &kbEvent) {
    std::string keyName = SDL_GetKeyName(kbEvent.keysym.sym);
    if(keyName == "up") {
        upKeyPressed = kbEvent.state == SDL_PRESSED;
    }
    if(keyName == "down") {
        downKeyPressed = kbEvent.state == SDL_PRESSED;
    }
}

GameWindow::~GameWindow() {
    SDL_FreeSurface(screen);
    SDL_Quit();
}

void GameWindow::update() {
    // Clear the screen.
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
    
    Ball prevBall = ball; // keep a copy of the old ball before the move,
    
    // Move Ball
    ball.move(
        ball.getSpeedX() / frameRate,
        ball.getSpeedY() / frameRate);
    
    // move AI paddle in response to ball
    if(ballPaddleOffset(ball, rightPaddle) > 20 &&
            !rightPaddle.atEdge(BOTTOM)) {
        rightPaddle.move(0, rightPaddle.getSpeed() / frameRate);
    } else if(ballPaddleOffset(ball, rightPaddle) < 20 &&
            !rightPaddle.atEdge(TOP)) {
        rightPaddle.move(0, -rightPaddle.getSpeed() / frameRate);
    } else {
        rightPaddle.move(0, 0);
    }
    
    // collision with paddles
    if(ball.isTouching(leftPaddle.getRect())) {
        ball = prevBall; // back out of the move
        ball.setSpeedX(-ball.getSpeedX());
        ball.setSpeedY(ballPaddleOffset(ball, leftPaddle) * BALL_BOUNCE_ANGLE);
    } else if(ball.isTouching(rightPaddle.getRect())) {
        ball = prevBall; // back out of the move
        ball.setSpeedX(-ball.getSpeedX());
        ball.setSpeedY(ballPaddleOffset(ball, rightPaddle) * BALL_BOUNCE_ANGLE);
    }

    // collision with edges
    if (ball.atEdge(TOP)) {
        ball.setSpeedY(-ball.getSpeedY());
    } else if (ball.atEdge(BOTTOM)) {
        ball.setSpeedY(-ball.getSpeedY());
    } else if(ball.atEdge(LEFT)) {
        scoreboard.incrementComputerScore();
        ball.setPosition(BALL_CENTER_X, BALL_CENTER_Y);
        ball.setSpeedX(BALL_SPEED_X);
        ball.setRandomSpeedY();
        leftPaddle.setPosition(10, PADDLE_CENTER);
        rightPaddle.setPosition(
                WINDOW_WIDTH - PADDLE_WIDTH - 10,
                PADDLE_CENTER);
    } else if(ball.atEdge(RIGHT)) {
        scoreboard.incrementPlayerScore();
        ball.setPosition(BALL_CENTER_X, BALL_CENTER_Y);
        ball.setSpeedX(BALL_SPEED_X);
        ball.setRandomSpeedY();
        leftPaddle.setPosition(10, PADDLE_CENTER);
        rightPaddle.setPosition(
                WINDOW_WIDTH - PADDLE_WIDTH - 10,
                PADDLE_CENTER);
    }
    
    // Move paddles
    if(upKeyPressed && !downKeyPressed && !leftPaddle.atEdge(TOP)) {
        leftPaddle.move(0, -leftPaddle.getSpeed() / frameRate);
    }
    if(downKeyPressed && !upKeyPressed && !leftPaddle.atEdge(BOTTOM)) {
        leftPaddle.move(0, leftPaddle.getSpeed() / frameRate);
    }
    
    // Draw objects
    leftPaddle.show(screen);
    rightPaddle.show(screen);
    scoreboard.show(screen);
    ball.show(screen);
    
    // print FPS
    if(frameCount % MAX_FRAME_RATE == 0) {
        printf("FPS: %d\n", frameRate);
    }
    frameCount++;

    // Update screen
    SDL_Flip(screen);
    // Add delay (milliseconds)
    SDL_Delay(1000 / MAX_FRAME_RATE);
}

Sint16 GameWindow::ballPaddleOffset(Ball& ball, Paddle& paddle) {
    Sint16 ball_center = ball.getRect().y + ball.getRect().h / 2;
    Sint16 paddle_center = paddle.getRect().y + paddle.getRect().h / 2;
    return ball_center - paddle_center;
}
