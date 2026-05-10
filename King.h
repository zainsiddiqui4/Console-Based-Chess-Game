#pragma once
#include "Piece.h"

// ============================================================
//  King  —  Moves exactly one square in any direction.
//
//  Symbol:  'K' (White)  /  'k' (Black)
// ============================================================
class King : public Piece {
public:
    King();
    King(string c);

    void   setPosition(int x, int y) override;
    int    getPositionX() override;
    int    getPositionY() override;
    string getColour()    override;
    char   getSymbol()    override;

    // Returns true if the King can legally move from (startX,startY) to (endX,endY)
    bool isValidMove(int startX, int startY,
        int endX, int endY,
        Board& board) override;
};
