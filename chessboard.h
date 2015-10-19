#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "piece.h"

class ChessBoard
{
public:
    ChessBoard();
    // ~ChessBoard();

    void FillBoard(); // Fill the chessboard with all the initial pieces

private:
    int turn;
    int winner;
    Piece *board[8][8];
};

#endif

