//
// Created by hacki on 8/9/2023.
//

#ifndef OIT_CHALLENGE_TICTACTOEBOARD_H
#define OIT_CHALLENGE_TICTACTOEBOARD_H

#include <string>

class TicTacToeBoard {
private:
    char ticTacToeBoard[3][3];
    int openSpacesLeft;
    static char checkIfThreeInRow(char symbol1, char symbol2, char symbol3);
    char checkAllRows();
    char checkAllColumns();
    char checkDiagonals();
    void numberInputDecoder(int playerInput, int& rowNum, int& colNum);
public:
    TicTacToeBoard();
    void resetTicTacToeBoard();
    char checkIfWon();
    bool placeLetterDown(int playerInput, char letter);
    bool computerPlaceLetterDown();
    char displayCharLetter(int rowNum, int colNum);
    int getOpenSpacesLeft() const;
};


#endif //OIT_CHALLENGE_TICTACTOEBOARD_H
