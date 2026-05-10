#pragma once
#include "Piece.h"

// ============================================================
//  Bishop  —  Moves any number of squares diagonally.
//
//  Symbol:  'B' (White)  /  'b' (Black)
// ============================================================
class Bishop : public Piece {
public:
    Bishop();
    Bishop(string c);

    void   setPosition(int x, int y) override;
    int    getPositionX() override;
    int    getPositionY() override;
    string getColour()    override;
    char   getSymbol()    override;

    // Returns true if the Bishop can legally move from (startX,startY) to (endX,endY)
    bool isValidMove(int startX, int startY,
        int endX, int endY,
        Board& board) override;
};
