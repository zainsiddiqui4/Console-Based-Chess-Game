#pragma once
#include "Piece.h"

// ============================================================
//  Pawn  —  Moves forward 1 square (or 2 from starting row).
//           Captures diagonally forward only.
//
//  White pawns start on row 6 and move toward row 0 (direction = -1).
//  Black pawns start on row 1 and move toward row 7 (direction = +1).
//
//  Symbol:  'P' (White)  /  'p' (Black)
// ============================================================
class Pawn : public Piece {
public:
    Pawn();
    Pawn(string c);

    void   setPosition(int x, int y) override;
    int    getPositionX() override;
    int    getPositionY() override;
    string getColour()    override;
    char   getSymbol()    override;

    // Returns true if the Pawn can legally move from (startX,startY) to (endX,endY)
    bool isValidMove(int startX, int startY,
        int endX, int endY,
        Board& board) override;
};
