#ifndef KING_H
#define KING_H

#include "piece.h"

/**
* Base class for king
*/
class King : public Piece {
public:
    King(int player, int row, int col, PiecesArray &board);
    King(int player, string position, PiecesArray &board);

    ~King();

    void Draw();

	
    bool Validate(string);
};

#endif


