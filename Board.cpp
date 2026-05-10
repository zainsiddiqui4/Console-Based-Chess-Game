#include "Board.h"

// ---- Constructor ----
// Delegates to initializeBoard() to zero out the grid
Board::Board() { initializeBoard(); }

// ---- Destructor ----
// Releases memory for every piece still on the board
Board::~Board() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (grid[i][j]) { delete grid[i][j]; grid[i][j] = nullptr; }
}

// ---- getPiece ----
// Returns piece pointer at (x,y); nullptr if out of bounds or square empty
Piece* Board::getPiece(int x, int y) {
    if (x < 0 || x >= 8 || y < 0 || y >= 8) return nullptr;
    return grid[x][y];
}

// ---- initializeBoard ----
// Clears all squares to nullptr (no pieces)
void Board::initializeBoard() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            grid[i][j] = nullptr;
}

// ---- setBoardWhite ----
// Places White's back rank (row 7) and pawns (row 6) in starting positions
void Board::setBoardWhite() {
    grid[7][0] = new Rook("White");
    grid[7][1] = new Knight("White");
    grid[7][2] = new Bishop("White");
    grid[7][3] = new Queen("White");
    grid[7][4] = new King("White");
    grid[7][5] = new Bishop("White");
    grid[7][6] = new Knight("White");
    grid[7][7] = new Rook("White");
    for (int j = 0; j < 8; j++) grid[6][j] = new Pawn("White");

    // Set internal position data for each placed piece
    for (int j = 0; j < 8; j++) {
        grid[7][j]->setPosition(7, j);
        grid[6][j]->setPosition(6, j);
    }
}

// ---- setBoardBlack ----
// Places Black's back rank (row 0) and pawns (row 1) in starting positions
void Board::setBoardBlack() {
    grid[0][0] = new Rook("Black");
    grid[0][1] = new Knight("Black");
    grid[0][2] = new Bishop("Black");
    grid[0][3] = new Queen("Black");
    grid[0][4] = new King("Black");
    grid[0][5] = new Bishop("Black");
    grid[0][6] = new Knight("Black");
    grid[0][7] = new Rook("Black");
    for (int j = 0; j < 8; j++) grid[1][j] = new Pawn("Black");

    // Set internal position data for each placed piece
    for (int j = 0; j < 8; j++) {
        grid[0][j]->setPosition(0, j);
        grid[1][j]->setPosition(1, j);
    }
}

// ---- displayBoard ----
// Renders the board to stdout with rank numbers and file letters
void Board::displayBoard() {
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
        cout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            char s = (grid[i][j] == nullptr) ? ' ' : grid[i][j]->getSymbol();
            cout << "| " << s << " ";
        }
        cout << "|" << endl;
    }
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    cout << "    a   b   c   d   e   f   g   h" << endl << endl;
}

// ---- movePiece ----
// Moves piece from source to destination.
// Deletes the captured piece if the destination holds an enemy.
// Does nothing if coordinates are out of bounds, source is empty,
// or destination holds a friendly piece.
void Board::movePiece(int startX, int startY, int endX, int endY) {
    if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 ||
        endX < 0 || endX >= 8 || endY < 0 || endY >= 8) return;

    Piece* movingPiece = grid[startX][startY];
    if (movingPiece == nullptr) return;

    // Do not allow moving onto a friendly piece
    if (grid[endX][endY] != nullptr &&
        grid[endX][endY]->getColour() == movingPiece->getColour()) return;

    // Capture enemy piece if present
    if (grid[endX][endY] != nullptr) delete grid[endX][endY];

    // Execute the move
    grid[endX][endY] = movingPiece;
    grid[startX][startY] = nullptr;
    movingPiece->setPosition(endX, endY);
}
