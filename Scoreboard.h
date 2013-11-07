#ifndef PONG_SCOREBOARD_H
#define	PONG_SCOREBOARD_H

#include <cstdlib>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Constants.h"

namespace Pong {

    class Scoreboard {
    public:
        Scoreboard();
        int getPlayerScore() const;
        void setPlayerScore(Uint8 score);
        void incrementPlayerScore();
        int getComputerScore() const;
        void setComputerScore(Uint8 score);
        void incrementComputerScore();
        void show(SDL_Surface *surface);
        virtual ~Scoreboard();
    private:
        Uint8 playerScore;
        Uint8 computerScore;
        SDL_Surface *playerMessage;
        SDL_Surface *computerMessage;
        TTF_Font *font;
        SDL_Color textColor;
        SDL_Rect playerRect;
        SDL_Rect computerRect;
    };

}

#endif	/* PONG_SCOREBOARD_H */
