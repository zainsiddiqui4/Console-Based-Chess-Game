#include "King.h"
#include "Board.h"

// ---- Constructors ----
King::King() : Piece() {}
King::King(string c) : Piece(c, (c == "White") ? 'K' : 'k') {}

// ---- Getters / Setters ----
string King::getColour() { return colour; }
int    King::getPositionX() { return positionX; }
int    King::getPositionY() { return positionY; }
void   King::setPosition(int x, int y) { positionX = x; positionY = y; }
char   King::getSymbol() { return symbol; }

// ---- Move Validation ----
// King moves exactly 1 square in any direction (dx <= 1 && dy <= 1)
// Cannot move to a square occupied by a friendly piece
bool King::isValidMove(int startX, int startY, int endX, int endY, Board& board) {
    int dx = abs(endX - startX);
    int dy = abs(endY - startY);

    // Must move at least one square
    if (dx == 0 && dy == 0) return false;

    // Cannot move more than one square in any direction
    if (dx > 1 || dy > 1) return false;

    // Cannot capture own piece
    Piece* target = board.getPiece(endX, endY);
    if (target != nullptr && target->getColour() == this->colour) return false;

    return true;
}
