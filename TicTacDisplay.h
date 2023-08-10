//
// Created by hacki on 8/9/2023.
//

#ifndef OIT_CHALLENGE_TICTACDISPLAY_H
#define OIT_CHALLENGE_TICTACDISPLAY_H
#include "TicTacToeBoard.h"

class TicTacDisplay {
private:
    bool playerStarts;
    bool gameOver;
    std::string winner;
    std::string getPlayerInput();
    void drawTicTacBoard();
    void gameCycle();
    void playerTurn();
    void computerTurn();
    bool checkIfGameOver();
    void gameEnd();
public:
    TicTacDisplay();
    TicTacToeBoard ticTacToeBoard;
    void startGame();
};

#endif //OIT_CHALLENGE_TICTACDISPLAY_H
