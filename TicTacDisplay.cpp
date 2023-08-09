//
// Created by hacki on 8/9/2023.
//

#include <stdlib.h>
#include <iostream>
#include "TicTacDisplay.h"

using namespace std;

TicTacDisplay::TicTacDisplay() {
    playerStarts = true;
}

string TicTacDisplay::getPlayerInput() {
    cout << "Please type your input here: ";

    string playerInput;
    getline(cin, playerInput);
    return playerInput;
}

void TicTacDisplay::drawTicTacBoard() {

    system("cls");
    cout << "                   TIC-TAC-TOE" << endl;
    cout << "           Game Board      Position Number" << endl;


    cout << "            " << ticTacToeBoard.displayCharLetter(0, 0) << "  ";
    cout << ticTacToeBoard.displayCharLetter(0, 1) << "  ";
    cout << ticTacToeBoard.displayCharLetter(0, 2) << "            1  2  3" << endl;
    cout << "            " << ticTacToeBoard.displayCharLetter(1, 0) << "  ";
    cout << ticTacToeBoard.displayCharLetter(1, 1) << "  ";
    cout << ticTacToeBoard.displayCharLetter(1, 2) << "            4  5  6" << endl;
    cout << "            " << ticTacToeBoard.displayCharLetter(2, 0) << "  ";
    cout << ticTacToeBoard.displayCharLetter(2, 1) << "  ";
    cout << ticTacToeBoard.displayCharLetter(2, 2) << "            7  8  9" << endl;
    cout << "\n\n";
}

void TicTacDisplay::startGame() {
    cout << "Hello, welcome to a game of Tic-Tac-Toe! You will play against the computer!" << endl;
    cout << "Decide who will play first by inputting either of the words into the console: ME or COMPUTER" << endl;

    bool acceptedInput = false;
    while (!acceptedInput) {
        string playerInput = getPlayerInput();
        if (playerInput == "ME") {
            playerStarts = true;
            acceptedInput = true;
        }
        else if (playerInput == "COMPUTER") {
            playerStarts = false;
            acceptedInput = true;
        }
        else {
            cout << "\nINPUT ERROR. Enter either ME or COMPUTER to decide who goes first." << endl;
        }
    }
    gameCycle();
    gameEnd();
}

void TicTacDisplay::gameCycle() {
    if (!playerStarts) {
        computerTurn();
    }

    while (!gameOver) {
        drawTicTacBoard();
        playerTurn();
        computerTurn();
    }
}

void TicTacDisplay::playerTurn() {
    cout << "\nYOUR TURN! Please the enter the number where you'd like to place your X. " << endl;
    cout << "Use the example numbers on the right to know the location you want." << endl;

    bool acceptedInput = false;
    while (!acceptedInput) {
        string playerInput = getPlayerInput();
        int playerNum = stoi(playerInput);
        if (playerNum >= 1 && playerNum <= 9) {
            if (ticTacToeBoard.placeLetterDown(playerNum, 'X')) {
                acceptedInput = true;
            }
            else {
                cout << "\nPLAY ERROR. This space has already been taken. Please choose an empty spot." << endl;
            }
        }
        else {
            cout << "\nINPUT ERROR. Enter a number between 1 and 9." << endl;
        }
    }

    if (checkIfGameOver()) {
        gameOver = true;
    }
}

void TicTacDisplay::computerTurn() {
    ticTacToeBoard.computerPlaceLetterDown();
    if (checkIfGameOver()) {
        gameOver = true;
    }
}

bool TicTacDisplay::checkIfGameOver() {
    char charResult = ticTacToeBoard.checkIfWon();
    if (charResult == 'X') {
        winner = "PLAYER";
        return true;
    }
    else if (charResult == 'O') {
        winner = "COMPUTER";
        return true;
    }

    if (ticTacToeBoard.getOpenSpacesLeft() <= 0) {
        winner = "TIE";
        return true;
    }

    return false;
}

void TicTacDisplay::gameEnd() {
    drawTicTacBoard();

    if (winner == "PLAYER") {
        cout << "Congrats, you won!" << endl;
    }
    else if (winner == "COMPUTER") {
        cout << "What a shame, you lost! This is so tragic..." << endl;
    }
    else if (winner == "TIE") {
        cout << "Wow, it ended in a tie!" << endl;
    }

    cout << "Want to play again? If so, type YES. If not, type NO." << endl;
    string playerInput = getPlayerInput();
    if (playerInput == "YES") {
        startGame();
    }
    else {
        cout << "Thanks for playing! Goodbye." << endl;
        system("pause");
    }
}








