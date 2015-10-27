#ifndef PIECE_H
#define PIECE_H
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
private:
    int x, y;

};

#endif

