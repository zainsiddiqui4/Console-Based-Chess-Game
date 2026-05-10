#include "Piece.h"

// ---- Default constructor ----
// Sets safe "not placed" defaults
Piece::Piece() {
    symbol = 'N';
    colour = "NOT SET";
    positionX = -1;
    positionY = -1;
}

// ---- Parameterised constructor ----
// Accepts colour and display symbol; position starts as unset (-1)
Piece::Piece(string c, char s) {
    symbol = s;
    colour = c;
    positionX = -1;
    positionY = -1;
}
