#pragma once
#include "Piece.h"

// ============================================================
//  Rook  —  Moves any number of squares horizontally or vertically.
//
//  Symbol:  'R' (White)  /  'r' (Black)
// ============================================================
class Rook : public Piece {
public:
    Rook();
    Rook(string c);

    void   setPosition(int x, int y) override;
    int    getPositionX() override;
    int    getPositionY() override;
    string getColour()    override;
    char   getSymbol()    override;

    // Returns true if the Rook can legally move from (startX,startY) to (endX,endY)
    bool isValidMove(int startX, int startY,
        int endX, int endY,
        Board& board) override;
};
