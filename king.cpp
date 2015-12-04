#include "king.h"
#include <iostream>
#include <math.h>
King::King(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board)
{
	king_type = true;	
//        std::cout<<"Creating a King\n";
}

King::~King()
{
//        std::cout<<"Killing a King?\n";
}

void King::Draw()
{
if(player == 1)
        cout <<BOLDGREEN;
   else
        cout <<BOLDRED;
        std::cout << "K";
        cout <<BLACK;
}


King::King(int _player, string _position, PiecesArray &_board): Piece(_player, _position, _board) {

}

bool King::Validate(string dest)
{
        bool V= false;
        int cd = (int) (dest[0] - 'a'); // letters are the columns
        int rd = (int) 8 - (dest[1] - '0'); // numbers are rows
        int i=1, flag=0;
 	if(player==1)               
		if (sqrt((cd-c)*(cd-c)+(rd-r)*(rd-r)) <2)
		      	if(board[rd][cd]==NULL || board[rd][cd]->player==2)
				return true;
	if(player==2)	
		if (sqrt((cd-c)*(cd-c)+(rd-r)*(rd-r)) <2)
                        if(board[rd][cd]==NULL ||board[rd][cd]->player==1)
                                return true;
	return false;
}
