#include "Rook.h"
#include "Board.h"

// ---- Constructors ----
Rook::Rook() : Piece() {}
Rook::Rook(string c) : Piece(c, (c == "White") ? 'R' : 'r') {}

// ---- Getters / Setters ----
string Rook::getColour() { return colour; }
int    Rook::getPositionX() { return positionX; }
int    Rook::getPositionY() { return positionY; }
void   Rook::setPosition(int x, int y) { positionX = x; positionY = y; }
char   Rook::getSymbol() { return symbol; }

// ---- Move Validation ----
// Rook moves in a straight line only (dx == 0 XOR dy == 0).
// Path must be clear; cannot capture own piece.
bool Rook::isValidMove(int startX, int startY, int endX, int endY, Board& board) {
    int dx = endX - startX;
    int dy = endY - startY;

    // Must actually move
    if (dx == 0 && dy == 0) return false;

    // Must move in a straight line (not diagonal)
    if (dx != 0 && dy != 0) return false;

    // Determine step direction for path traversal
    int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
    int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);

    // Check every square along the path (excluding destination)
    int x = startX + stepX, y = startY + stepY;
    while (x != endX || y != endY) {
        if (board.getPiece(x, y) != nullptr) return false; // path blocked
        x += stepX;
        y += stepY;
    }

    // Cannot capture own piece
    Piece* target = board.getPiece(endX, endY);
    if (target != nullptr && target->getColour() == this->colour) return false;

    return true;
}
