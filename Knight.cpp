#include "Knight.h"
#include "Board.h"

// ---- Constructors ----
Knight::Knight() : Piece() {}
Knight::Knight(string c) : Piece(c, (c == "White") ? 'N' : 'n') {}

// ---- Getters / Setters ----
string Knight::getColour() { return colour; }
int    Knight::getPositionX() { return positionX; }
int    Knight::getPositionY() { return positionY; }
void   Knight::setPosition(int x, int y) { positionX = x; positionY = y; }
char   Knight::getSymbol() { return symbol; }

// ---- Move Validation ----
// Knight moves in an L-shape: (2,1) or (1,2) in absolute distances.
// Knights jump over pieces, so no path-blocking check is needed.
// Cannot land on a square occupied by a friendly piece.
bool Knight::isValidMove(int startX, int startY, int endX, int endY, Board& board) {
    int dx = abs(endX - startX);
    int dy = abs(endY - startY);

    // Must be a valid L-shape: (2,1) or (1,2)
    if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) return false;

    // Cannot capture own piece
    Piece* target = board.getPiece(endX, endY);
    if (target != nullptr && target->getColour() == this->colour) return false;

    return true; // Knights jump, so no path check required
}
