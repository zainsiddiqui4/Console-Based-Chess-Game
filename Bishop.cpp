#include "Bishop.h"
#include "Board.h"

// ---- Constructors ----
Bishop::Bishop() : Piece() {}
Bishop::Bishop(string c) : Piece(c, (c == "White") ? 'B' : 'b') {}

// ---- Getters / Setters ----
string Bishop::getColour() { return colour; }
int    Bishop::getPositionX() { return positionX; }
int    Bishop::getPositionY() { return positionY; }
void   Bishop::setPosition(int x, int y) { positionX = x; positionY = y; }
char   Bishop::getSymbol() { return symbol; }

// ---- Move Validation ----
// Bishop moves diagonally only (|dx| == |dy|).
// Path must be clear; cannot capture own piece.
bool Bishop::isValidMove(int startX, int startY, int endX, int endY, Board& board) {
    int dx = endX - startX;
    int dy = endY - startY;

    // Must actually move
    if (dx == 0 && dy == 0) return false;

    // Must be a diagonal move
    if (abs(dx) != abs(dy)) return false;

    // Determine diagonal step direction
    int stepX = (dx > 0 ? 1 : -1);
    int stepY = (dy > 0 ? 1 : -1);

    // Check every square along the diagonal (excluding destination)
    int x = startX + stepX, y = startY + stepY;
    while (x != endX) {
        if (board.getPiece(x, y) != nullptr) return false; // path blocked
        x += stepX;
        y += stepY;
    }

    // Cannot capture own piece
    Piece* target = board.getPiece(endX, endY);
    if (target != nullptr && target->getColour() == this->colour) return false;

    return true;
}
