#pragma once
#include "Piece.h"

// ============================================================
//  Queen  —  Moves any number of squares in a straight line
//            or diagonally (combines Rook + Bishop movement).
//
//  Symbol:  'Q' (White)  /  'q' (Black)
// ============================================================
class Queen : public Piece {
public:
    Queen();
    Queen(string c);

    void   setPosition(int x, int y) override;
    int    getPositionX() override;
    int    getPositionY() override;
    string getColour()    override;
    char   getSymbol()    override;

    // Returns true if the Queen can legally move from (startX,startY) to (endX,endY)
    bool isValidMove(int startX, int startY,
        int endX, int endY,
        Board& board) override;
};
