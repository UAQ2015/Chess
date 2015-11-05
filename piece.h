#ifndef PIECE_H
#define PIECE_H

#include <string>

using namespace std;
/**
* Base class for chess pieces
*/
class Piece
{
public:
    Piece(int, int, int);
    ~Piece();
//		virtual int Move(int x, int y) = 0;
    int player;
/**
* Virtual function to draw a piece
*/
    virtual void Draw();
    virtual bool Validate(string );
	Piece ***board;
protected:
    int r, c;

};

#endif

