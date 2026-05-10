#pragma once
#include "Piece.h"

// ============================================================
//  Knight  —  Moves in an L-shape: 2 squares in one axis and
//             1 square in the other. Jumps over other pieces.
//
//  Symbol:  'N' (White)  /  'n' (Black)
// ============================================================
class Knight : public Piece {
public:
    Knight();
    Knight(string c);

    void   setPosition(int x, int y) override;
    int    getPositionX() override;
    int    getPositionY() override;
    string getColour()    override;
    char   getSymbol()    override;

    // Returns true if the Knight can legally move from (startX,startY) to (endX,endY)
    bool isValidMove(int startX, int startY,
        int endX, int endY,
        Board& board) override;
};
