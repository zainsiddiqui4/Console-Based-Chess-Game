#pragma once
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

// ============================================================
//  Board  —  Owns the 8x8 grid and all pieces on it.
//
//  Grid layout:
//    grid[0][0..7] = Black's back rank (row 8 in chess notation)
//    grid[7][0..7] = White's back rank (row 1 in chess notation)
//    Columns 0..7 map to files a..h
// ============================================================
class Board {
    Piece* grid[8][8]; // 8x8 grid of piece pointers (nullptr = empty square)

public:
    // Constructor: initialises all squares to nullptr
    Board();

    // Destructor: deletes all remaining pieces on the board
    ~Board();

    // Sets every square to nullptr
    void initializeBoard();

    // Places White pieces in their starting positions (rows 6–7)
    void setBoardWhite();

    // Places Black pieces in their starting positions (rows 0–1)
    void setBoardBlack();

    // Prints the current board state to the console
    void displayBoard();

    // Returns the piece at (x, y), or nullptr if empty / out-of-bounds
    Piece* getPiece(int x, int y);

    // Moves the piece from (startX,startY) to (endX,endY);
    // captures the target piece if present and enemy
    void movePiece(int startX, int startY, int endX, int endY);
};
