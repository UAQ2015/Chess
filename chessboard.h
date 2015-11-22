#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "piece.h"
/**
* Base class for chessboard
*/

using namespace std;


class ChessBoard {
public:
    ChessBoard();

    ~ChessBoard();

    void FillBoard();   // Fill the chessboard with all the initial pieces
    void Draw();        // Draws the board with all the pieces
    Piece *GetPiece(string);

    bool Validate(Piece *, string);

    void TestRook();

    void TestPawn();
    
    void TestBishop();
    void TestKnight();
    void TestQueen();
    void TestKing();
private:
    int turn;
    int winner;
    PiecesArray board;

    void CleanBoard();
};

#endif

