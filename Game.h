#pragma once
#include "Board.h"

// ============================================================
//  Game  —  Controls the overall flow of a chess match.
//
//  Responsibilities:
//    - Tracks whose turn it is (White / Black)
//    - Reads and validates player input (algebraic notation e.g. "e2 e4")
//    - Delegates move validation to each Piece
//    - Detects King capture and declares the winner
// ============================================================
class Game {
private:
    Board board;       // The board and all pieces
    bool  isWhiteTurn; // true = White's turn, false = Black's turn
    bool  gameOver;    // true when the game has ended

public:
    // Constructor: sets up a fresh game (White moves first)
    Game();

    // Main game loop — runs until a King is captured or "quit" is entered
    void startGame();
};
