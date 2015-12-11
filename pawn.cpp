#include "pawn.h"
#include <iostream>


Pawn::Pawn(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board) {
        pawn_type = true;//        std::cout<<"Creating a pawn :p\n";
}

Pawn::~Pawn() {
         //       std::cout<<"Killing a pawn Meh!\n";
}

void Pawn::Draw() {
   if(player == 1)
	cout <<BOLDGREEN;
   else
	cout <<BOLDRED;
	std::cout << "p";
	cout <<BLACK;

}

Pawn::Pawn(int _player, string _position, PiecesArray &_board) : Piece(_player, _position, _board) {
  pawn_type=false;
}

bool Pawn::Validate(string dest)
{
	int cd = (int) (dest[0] - 'a'); // letters are the columns
   	int rd = (int) 8 - (dest[1] - '0'); // numbers are rows
	 if (player==1)
        {
                if (c == cd)
                {
			if((r==1&&rd==3)||(rd==r+1))
			{
				if(board[rd][c]==NULL && board[r+1][c]==NULL)
						return true;
			}
		}
		if((c+1 ==cd)||(c-1==cd))
			if(r+1==rd && board[rd][cd]->player==2)
				return true;

	}

	 if (player==2)
        {
                if (c == cd)
                {
                        if((r==6 && rd==4)||(rd==r-1))
                        {
				if(board[rd][c]==NULL && board[r-1][c]==NULL)
						return true;
                        }
                }
                if((c+1 ==cd)||(c-1==cd))
			if(r-1==rd && board[rd][cd]->player==1)
                                return true;

        }
	return false;
}
