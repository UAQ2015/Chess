#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:
    Piece(int, int, int);
    ~Piece();
//		virtual int Move(int x, int y) = 0;
    int player;
    virtual void Draw();
private:
    int x, y;

};

#endif

