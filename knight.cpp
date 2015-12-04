#include "knight.h"
#include <iostream>

Knight::Knight(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board)
{
//        std::cout<<"Creating a knight\n";
}

Knight::~Knight()
{
//        std::cout<<"Killing a knight\n";
}

void Knight::Draw()
{
 if(player == 1)
        cout <<BOLDGREEN;
   else
        cout <<BOLDRED;
        std::cout << "C";
        cout <<BLACK;
}


Knight::Knight(int _player, string _position, PiecesArray &_board): Piece(_player, _position, _board) {

}

bool Knight::Validate(string dest)
{
        bool V= false;
        int cd = (int) (dest[0] - 'a'); // letters are the columns
        int rd = (int) 8 - (dest[1] - '0'); // numbers are rows
        int i=1, flag=0;
                if ((rd-r)!=0 && (cd-c) != 0)
                {
                        if(board[rd][cd]==NULL)
                        {
				if((rd-r)*(rd-r)+(cd-c)*(cd-c)==5)
					return true;		
                        }
                        else
                        {
                                        if(player==1)
                                                if(board[rd][cd]->player==2 && (rd-r)*(rd-r)+(cd-c)*(cd-c)==5)
                                                        return true;
                                        if(player==2)
                                                if(board[rd][cd]->player==1 && (rd-r)*(rd-r)+(cd-c)*(cd-c)==5)
                                                        return true;
                        }
			return false;

                }
}

