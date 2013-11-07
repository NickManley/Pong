#include <SDL/SDL.h>
#include <string>
#include "GameWindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    Pong::GameWindow pongWindow;
    SDL_Event event;
    bool gameRunning = true;
    
    // Main event loop
    while(gameRunning) {
        if (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT: 
                    gameRunning = false;
                    break;
                case SDL_KEYDOWN:
                case SDL_KEYUP:
                    pongWindow.onKeyboardEvent(event.key);
                    break;
                default: break;
            }
        }
        pongWindow.show();
    }

    return 0;
}
