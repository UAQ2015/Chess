#ifndef PIECE_H
#define PIECE_H
#define BLACK "\033[30m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"
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

    void Move(int i, int i1);
    int r, c;
    bool king_type;
    bool pawn_type;
private:
    int first_move;

};



#endif

