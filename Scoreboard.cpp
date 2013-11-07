#include "Scoreboard.h"

using namespace Pong;

Scoreboard::Scoreboard() {
    // Font: Inconsolata (Bold)
    // Color: White
    TTF_Init();
    textColor.r = textColor.g = textColor.b = 255;
    font = TTF_OpenFont("Inconsolata-Bold.ttf", SCOREBOARD_FONT_SIZE);
    
    playerScore = 0;
    computerScore = 0;
    
    // Determine the positions for the score text.
    // X position: 1/4th from left and 3/4th from left
    // Y position: 10 pixels down from the top
    playerRect.x = WINDOW_WIDTH / 4;
    playerRect.y = 10;
    computerRect.x = WINDOW_WIDTH / 4 * 3;
    computerRect.y = 10;
}

int Scoreboard::getPlayerScore() const {
    return this->playerScore;
}

void Scoreboard::setPlayerScore(Uint8 score) {
    this->playerScore = score;
}

void Scoreboard::incrementPlayerScore() {
    this->playerScore++;
}

int Scoreboard::getComputerScore() const {
    return this->computerScore;
}

void Scoreboard::setComputerScore(Uint8 score) {
    this->computerScore = score;
}

void Scoreboard::incrementComputerScore() {
    this->computerScore++;
}

void Scoreboard::show(SDL_Surface *surface) {
    // Show Player Score
    char playerStr[4];
    sprintf(playerStr, "%d", playerScore);
    playerMessage = TTF_RenderText_Blended(font, playerStr, textColor);
    SDL_BlitSurface(playerMessage, NULL, surface, &playerRect);
    SDL_FreeSurface(playerMessage);
    playerMessage = NULL;
    
    // Show Computer Score
    char computerStr[4];
    sprintf(computerStr, "%d", computerScore);
    computerMessage = TTF_RenderText_Blended(font, computerStr, textColor);
    SDL_BlitSurface(computerMessage, NULL, surface, &computerRect);
    SDL_FreeSurface(computerMessage);
    computerMessage = NULL;
}

Scoreboard::~Scoreboard() {
    TTF_CloseFont(font);
    if(playerMessage) {
        SDL_FreeSurface(playerMessage);
    }
    if(computerMessage) {
        SDL_FreeSurface(computerMessage);
    }
}
