# TicTacToe

## The Game
#### Tic Tac Toe is a two player game in which the players take alternate turns placing marks on a 3x3 board. One player is assigned an ‘X’ marker; and the other player is assigned an ‘O’ marker. The objective of the game is to place three markers in a row, either horizontally, vertically, or diagonally. The first player to achieve this, wins.

## The Program
#### This program begins by prompting the user to choose between two game modes; either they can select to play versus the computer or versus a companion. Once a valid option has been selected, the game begins. Player 1 is assigned the ‘X’ marker, and always makes the first move. In the case of a player vs. computer game, a computer response to Player 1’s (X’s) move is pseudo-randomly generated. In the case of a player vs. player game, control is handed off to  Player 2 who is likewise prompted to make a move. Control continues to be toggled between both players, or the player and the computer, until either a winner is declared or all the spaces on the board are occupied (a tie). Once the game’s end is reached, the user is prompted to play again. If the user selects to play again, they are redirected to the intial game mode prompt. If not, the program is ended.

#### This program is written in C++ and uses the <iostream> library to print the game to the console; this game does not include a GUI. 
