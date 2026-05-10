#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

// Forward declaration so Piece can reference Board without a circular include
class Board;

// ============================================================
//  Piece  —  Abstract base class for all chess pieces
//
//  Holds common data: position (row/col), colour, display symbol.
//  Every concrete piece must override all pure-virtual methods.
//
//  Grid convention used throughout the project:
//    grid[x][y]  where x = row (0 = top / Black side, 7 = bottom / White side)
//                      y = column (0 = 'a' … 7 = 'h')
// ============================================================
class Piece {
protected:
    int positionX;   // row on the board (0–7)
    int positionY;   // column on the board (0–7)
    string colour;   // "White" or "Black"
    char symbol;     // single character shown on the board (e.g. 'K', 'q', 'P')

public:
    // Default constructor
    Piece();

    // Parameterised constructor
    Piece(string c, char s);

    // Virtual destructor — needed for correct polymorphic deletion
    virtual ~Piece() {}

    // --- Pure virtual interface (every piece must implement) ---
    virtual int    getPositionX() = 0;
    virtual int    getPositionY() = 0;
    virtual void   setPosition(int x, int y) = 0;
    virtual string getColour() = 0;
    virtual char   getSymbol() = 0;
    virtual bool   isValidMove(int startX, int startY,
        int endX, int endY,
        Board& board) = 0;
};
