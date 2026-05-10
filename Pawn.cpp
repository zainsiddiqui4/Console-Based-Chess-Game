#include "Pawn.h"
#include "Board.h"

// ---- Constructors ----
Pawn::Pawn() : Piece() {}
Pawn::Pawn(string c) : Piece(c, (c == "White") ? 'P' : 'p') {}

// ---- Getters / Setters ----
string Pawn::getColour() { return colour; }
int    Pawn::getPositionX() { return positionX; }
int    Pawn::getPositionY() { return positionY; }
void   Pawn::setPosition(int x, int y) { positionX = x; positionY = y; }
char   Pawn::getSymbol() { return symbol; }

// ---- Move Validation ----
// White moves "up" the board => decreasing X (from row 6 toward row 0)
// Black moves "down" the board => increasing X (from row 1 toward row 7)
bool Pawn::isValidMove(int startX, int startY, int endX, int endY, Board& board) {
    int direction = (colour == "White") ? -1 : 1;  // movement direction along X axis
    int startRow = (colour == "White") ? 6 : 1; // starting row for double-move

    int dx = endX - startX;
    int dy = endY - startY;

    Piece* target = board.getPiece(endX, endY);

    // Case 1: Forward move by 1 square — destination must be empty
    if (dy == 0 && dx == direction && target == nullptr)
        return true;

    // Case 2: Forward move by 2 squares from starting row —
    //         both the intermediate and destination squares must be empty
    if (dy == 0 && dx == 2 * direction && startX == startRow &&
        target == nullptr &&
        board.getPiece(startX + direction, startY) == nullptr)
        return true;

    // Case 3: Diagonal capture — one square forward-diagonal,
    //         destination must hold an enemy piece
    if (abs(dy) == 1 && dx == direction &&
        target != nullptr && target->getColour() != this->colour)
        return true;

    return false;
}
