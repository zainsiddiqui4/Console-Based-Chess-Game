#include "Queen.h"
#include "Board.h"

// ---- Constructors ----
Queen::Queen() : Piece() {}
Queen::Queen(string c) : Piece(c, (c == "White") ? 'Q' : 'q') {}

// ---- Getters / Setters ----
string Queen::getColour() { return colour; }
int    Queen::getPositionX() { return positionX; }
int    Queen::getPositionY() { return positionY; }
void   Queen::setPosition(int x, int y) { positionX = x; positionY = y; }
char   Queen::getSymbol() { return symbol; }

// ---- Move Validation ----
// Queen moves in a straight line (horizontal/vertical) OR diagonally,
// any number of squares. Path must be clear; cannot capture own piece.
bool Queen::isValidMove(int startX, int startY, int endX, int endY, Board& board) {
    int dx = endX - startX;
    int dy = endY - startY;

    // Must actually move
    if (dx == 0 && dy == 0) return false;

    // Must be straight line OR diagonal
    bool straight = (dx == 0 || dy == 0);
    bool diagonal = (abs(dx) == abs(dy));
    if (!straight && !diagonal) return false;

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
