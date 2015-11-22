#ifndef PIECE_H
#define PIECE_H

#include <string>

using namespace std;
/**
* Base class for chess pieces
*/

class Piece;
typedef Piece *PiecesArray[8][8];

class Piece
{
public:
    Piece(int player, string position, PiecesArray & );
    Piece(int player, int row, int col, PiecesArray &board );
    virtual ~Piece();
//		virtual int Move(int x, int y) = 0;
    int player;
/**
* Virtual function to draw a piece
*/
    virtual void Draw();
    virtual bool Validate(string );
    PiecesArray &board;
private: 
    int first_move;
protected:
    int r, c;

};



#endif

