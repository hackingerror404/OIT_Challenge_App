//
// Created by hacki on 8/9/2023.
//
#include <vector>
#include <random>
#include "TicTacToeBoard.h"

TicTacToeBoard::TicTacToeBoard() {
    resetTicTacToeBoard();
}

void TicTacToeBoard::resetTicTacToeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ticTacToeBoard[i][j] = '_';
        }
    }
    openSpacesLeft = 9;
}

char TicTacToeBoard::checkIfThreeInRow(char symbol1, char symbol2, char symbol3) {
    if (symbol1 == 'O' && symbol2 == 'O' && symbol3 == 'O') {
        return 'O';
    }

    else if (symbol1 == 'X' && symbol2 == 'X' && symbol3 == 'X') {
        return 'X';
    }

    else {
        return '_';
    }
}

char TicTacToeBoard::checkAllRows() {
    for (int i = 0; i < 3; i++) {
        char resultChar = checkIfThreeInRow(ticTacToeBoard[i][0], ticTacToeBoard[i][1], ticTacToeBoard[i][2]);
        // The purpose of this if statement is to stop the for loop early if it finds 3 in a row.
        if (resultChar != '_') {
            return resultChar;
        }
    }
    // If 3 in a row are not found, it returns with the '_' to indicate nothing was found.
    return '_';
}

char TicTacToeBoard::checkAllColumns() {
    for (int i = 0; i < 3; i++) {
        char resultChar = checkIfThreeInRow(ticTacToeBoard[0][i], ticTacToeBoard[1][i], ticTacToeBoard[2][i]);
        // The purpose of this if statement is to stop the for loop early if it finds 3 in a row.
        if (resultChar != '_') {
            return resultChar;
        }
    }
    // If 3 in a row are not found, it returns with the '_' to indicate nothing was found.
    return '_';
}

char TicTacToeBoard::checkDiagonals() {
    // Backslash Diagonal
    char resultChar = checkIfThreeInRow(ticTacToeBoard[0][0], ticTacToeBoard[1][1], ticTacToeBoard[2][2]);
    if (resultChar != '_') {
        return resultChar;
    }

    // Forward Slash Diagonal
    resultChar = checkIfThreeInRow(ticTacToeBoard[0][2], ticTacToeBoard[1][1], ticTacToeBoard[2][0]);
    if (resultChar != '_') {
        return resultChar;
    }

    return '_';
}

char TicTacToeBoard::checkIfWon() {
    char resultChar = checkAllRows();
    if (resultChar != '_') {
        return resultChar;
    }

    resultChar = checkAllColumns();
    if (resultChar != '_') {
        return resultChar;
    }

    resultChar = checkDiagonals();
    if (resultChar != '_') {
        return resultChar;
    }

    return '_';
}

void TicTacToeBoard::numberInputDecoder(int playerInput, int& rowNum, int& colNum) {
    switch (playerInput) {
        case 1:
            rowNum = 0;
            colNum = 0;
            break;
        case 2:
            rowNum = 0;
            colNum = 1;
            break;
        case 3:
            rowNum = 0;
            colNum = 2;
            break;
        case 4:
            rowNum = 1;
            colNum = 0;
            break;
        case 5:
            rowNum = 1;
            colNum = 1;
            break;
        case 6:
            rowNum = 1;
            colNum = 2;
            break;
        case 7:
            rowNum = 2;
            colNum = 0;
            break;
        case 8:
            rowNum = 2;
            colNum = 1;
            break;
        case 9:
            rowNum = 2;
            colNum = 2;
            break;
    }
}

bool TicTacToeBoard::placeLetterDown(int playerInput, char letter) {
    int rowNum, colNum;
    numberInputDecoder(playerInput, rowNum, colNum);

    // If this space on the tic-tac-toe board is occupied, the player cannot place a tic there. they must try again.
    if (ticTacToeBoard[rowNum][colNum] != '_') {
        return false;
    }
    // The space is not occupied, and the player's 'X' can be placed here.
    else {
        ticTacToeBoard[rowNum][colNum] = letter;
        openSpacesLeft--;
        return true;
    }
}

bool TicTacToeBoard::computerPlaceLetterDown() {
    std::vector<int> openSpots;

    // Find all open locations on the tic-tac board, add them to openSpots.
    int iterativeNum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            iterativeNum++;
            if (ticTacToeBoard[i][j] == '_') {
                openSpots.push_back(iterativeNum);
            }
        }
    }

    srand((unsigned) time(NULL));
    int randomSelection = openSpots.at(rand() % openSpots.size());
    if (!placeLetterDown(randomSelection, 'O')) {
        return false;
    }
    else {
        return true;
    }
}

char TicTacToeBoard::displayCharLetter(int rowNum, int colNum) {
    return ticTacToeBoard[rowNum][colNum];
}

int TicTacToeBoard::getOpenSpacesLeft() const {
    return openSpacesLeft;
}


