#include "Game.h"

// ---- Constructor ----
// White always moves first; game starts as active
Game::Game() {
    isWhiteTurn = true;
    gameOver = false;
}

// ---- startGame ----
// Main game loop:
//   1. Display board
//   2. Prompt the current player for a move in algebraic notation (e.g. "e2 e4")
//   3. Parse and validate input
//   4. Validate move with the piece's isValidMove()
//   5. Execute move; check for King capture (win condition)
//   6. Switch turns and repeat
void Game::startGame() {
    board.initializeBoard();
    board.setBoardWhite();
    board.setBoardBlack();

    while (!gameOver) {
        board.displayBoard();

        if (isWhiteTurn) cout << "White's turn: " << endl;
        else             cout << "Black's turn: " << endl;

        string start, end;
        cin >> start >> end;

        // Allow players to quit at any time
        if (start == "quit" || end == "quit") { gameOver = true; break; }

        // Basic input format check
        if (start.size() < 2 || end.size() < 2) {
            cout << "Invalid input format. Use e.g. e2 e4" << endl;
            continue;
        }

        // Convert algebraic notation to grid indices
        // Column: 'a'=0 … 'h'=7  |  Row: '8'=0 … '1'=7
        int startCol = start[0] - 'a';
        int startRow = 8 - (start[1] - '0');
        int endCol = end[0] - 'a';
        int endRow = 8 - (end[1] - '0');

        // Bounds check on converted indices
        if (startCol < 0 || startCol > 7 || startRow < 0 || startRow > 7 ||
            endCol < 0 || endCol   > 7 || endRow < 0 || endRow   > 7) {
            cout << "Coordinates out of bounds!" << endl;
            continue;
        }

        Piece* piece = board.getPiece(startRow, startCol);

        // Ensure a piece exists at the source square
        if (piece == nullptr) {
            cout << "No piece at selected position!" << endl;
            continue;
        }

        // Ensure the player is moving their own piece
        if (isWhiteTurn && piece->getColour() != "White") {
            cout << "Wrong piece! Try again." << endl;
            continue;
        }
        if (!isWhiteTurn && piece->getColour() != "Black") {
            cout << "Wrong piece! Try again." << endl;
            continue;
        }

        // Validate and execute the move
        if (piece->isValidMove(startRow, startCol, endRow, endCol, board)) {

            // Check if the destination holds a King (win condition)
            Piece* target = board.getPiece(endRow, endCol);
            bool kingCaptured = (target != nullptr &&
                (target->getSymbol() == 'K' || target->getSymbol() == 'k'));

            board.movePiece(startRow, startCol, endRow, endCol);
            isWhiteTurn = !isWhiteTurn; // switch turns

            // Announce winner if a King was captured
            if (kingCaptured) {
                board.displayBoard();
                cout << (isWhiteTurn ? "Black" : "White") << " wins!" << endl;
                gameOver = true;
            }
        }
        else {
            cout << "Invalid move! Try again." << endl;
        }
    }
}
