//
//  main.cpp
//  TicTacToe
//
//  Created by Alessia on 9/29/22.
//

#include <iostream>
#include <random>
#include <ctime>

char BOARD[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char PLAYER = 'X';

int initPrompt() {
  int game_mode = 1;
  std::cout << "WELCOME TO TIC TAC TOE!\n";
  std::cout << "------------------------\n";
  bool invalid_response;
  do {
    try {
      std::cout << "Choose a game option:\n\t1)\tPlay vs computer\n\t2)\tTwo player game\n\n>\t";
      std::cin >> game_mode;
      if (game_mode == 1 || game_mode == 2)
        invalid_response = false;
      else {
        invalid_response = true;
        throw(game_mode);
      }
    }
    catch(...) {
      std::cout << "Error: Invalid Response\n\n";
    }
  } while (invalid_response);
    
  return game_mode;
}

void drawBoard() {
  std::cout << "\n TIC TAC TOE\n";
  std::cout << "=============";
  for (int i = 0; i < 3; i++) {
    std::cout << "\n| ";
    for (int j = 0; j < 3; j++)
      std::cout << BOARD[i][j] << " | ";
    std::cout << "\n=============";
  }
  std::cout << std::endl;
}

void togglePlayer() {
  if (PLAYER == 'X')
    PLAYER = 'O';
  else
    PLAYER = 'X';
}

int generatePlay() {
  srand(time(0));
  int play = 1 + rand() % 9;
  return play;
}

void makePlay(int game_mode) {
  int field;
  bool invalid_field;
  do {
    try {
      if (game_mode == 1 && PLAYER == 'O') {
        field = generatePlay();
      }
      else {
        std::cout << "\nPlayer " << PLAYER << " select field to play\n>\t"; std::cin >> field;
      }
      
      switch(field) {
        case 1:
          if (BOARD[0][0] == 'X' || BOARD[0][0] == 'O') {
            invalid_field = true;
            throw(field);
          }
          else {
            invalid_field = false;
            BOARD[0][0] = PLAYER;
            break;
          }
        case 2:
          if (BOARD[0][1] == 'X' || BOARD[0][1] == 'O') {
            invalid_field = true;
            throw(field);
          }
          else {
            invalid_field = false;
            BOARD[0][1] = PLAYER;
            break;
          }
        case 3:
          if (BOARD[0][2] == 'X' || BOARD[0][2] == 'O') {
            invalid_field = true;
            throw(field);
          }
          else {
            invalid_field = false;
            BOARD[0][2] = PLAYER;
            break;
          }
        case 4:
          if (BOARD[1][0] == 'X' || BOARD[1][0] == 'O') {
            invalid_field = true;
            throw(field);
          }
          else {
            invalid_field = false;
            BOARD[1][0] = PLAYER;
            break;
          }
        case 5:
          if (BOARD[1][1] == 'X' || BOARD[1][1] == 'O') {
            invalid_field = true;
            throw(field);
          }
          else {
            invalid_field = false;
            BOARD[1][1] = PLAYER;
            break;
          }
        case 6:
          if (BOARD[1][2] == 'X' || BOARD[1][2] == 'O') {
            invalid_field = true;
            throw(field);
          }
          else {
            invalid_field = false;
            BOARD[1][2] = PLAYER;
            break;
          }
        case 7:
          if (BOARD[2][0] == 'X' || BOARD[2][0] == 'O') {
            invalid_field = true;
            throw(field);
          }
          else {
            invalid_field = false;
            BOARD[2][0] = PLAYER;
            break;
          }
        case 8:
          if (BOARD[2][1] == 'X' || BOARD[2][1] == 'O') {
            invalid_field = true;
            throw(field);
          }
          else {
            invalid_field = false;
            BOARD[2][1] = PLAYER;
            break;
          }
        case 9:
          if (BOARD[2][2] == 'X' || BOARD[2][2] == 'O') {
            invalid_field = true;
            throw(field);
          }
          else {
            invalid_field = false;
            BOARD[2][2] = PLAYER;
            break;
          }
        default:
          break;
      }
    }
    catch(...) {
      if (game_mode != 1 && PLAYER != 'O')
        std::cout << "Error: Invalid play. Field occupied.\n\n";
    }
  } while (invalid_field);
  
  if (game_mode == 1 && PLAYER == 'O')
    std::cout << "\nComputer plays!\n";
}

char win() {
  // Horizontal or Vertical Win
  for (int i = 0; i < 3; i++) {
    if ((BOARD[i][0] == 'X' && BOARD[i][1] == 'X' && BOARD[i][2] == 'X') ||
        (BOARD[0][i] == 'X' && BOARD[1][i] == 'X' && BOARD[2][i] == 'X'))
      return 'X';
    else if ((BOARD[i][0] == 'O' && BOARD[i][1] == 'O' && BOARD[i][2] == 'O') ||
             (BOARD[0][i] == 'O' && BOARD[1][i] == 'O' && BOARD[2][i] == 'O'))
      return 'O';
  }
  // Diagonal Win
  if ((BOARD[0][0] == 'X' && BOARD[1][1] == 'X' && BOARD[2][2] == 'X') ||
      (BOARD[0][2] == 'X' && BOARD[1][1] == 'X' && BOARD[2][0] == 'X'))
    return 'X';
  else if ((BOARD[0][0] == 'O' && BOARD[1][1] == 'O' && BOARD[2][2] == 'O') ||
           (BOARD[0][2] == 'O' && BOARD[1][1] == 'O' && BOARD[2][0] == 'O'))
    return 'O';
  // No winner
  return '-';
}

void resetGame() {
  char reset_fields[] = {'1','2','3','4','5','6','7','8','9'};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      BOARD[i][j] = reset_fields[i * 3 + j];
  }
  PLAYER = 'X';
}

int main() {
  do {
    // Prompt user for desired game mode (vs computer || two player game)
    int game_mode = initPrompt();
    bool game_end = false;
    int play_count = 0;
    
    // Loop through the game
    while (game_end == false) {
      if (game_mode != 1 && PLAYER != 'O')
        drawBoard();
      makePlay(game_mode); play_count++;
        
      if (win() == 'X') {
        std::cout << "\n<< X WINS!!! >>\n" << std::endl;
        game_end = true;
      }
      else if (win() == 'O') {
        std::cout << "\n<< O WINS!!! >>\n" << std::endl;
        game_end = true;
      }
      else if (play_count == 9 && win() == '-') {
        std::cout << "\n<< ITS A TIE!!! >>\n" << std::endl;
        game_end = true;
      }
      
      togglePlayer();
    }
    
    // Prompt the user if they'd like to play again
    char play_again;
    bool invalid_response;
    do {
      try {
        std::cout << "Play again? [Y/N]\n>\t"; std::cin >> play_again;
        if (play_again == 'Y' || play_again == 'N')
          invalid_response = false;
        else {
          invalid_response = true;
          throw(play_again);
        }
      }
      catch(...) {
        std::cout << "Error: Invalid Response\n\n";
      }
    } while (invalid_response);
      // If no, end program
    if (play_again == 'N')
      return 0;
    
      // If yes, reset game
    resetGame();
    std::cout << std::endl;
  } while (1);
}

