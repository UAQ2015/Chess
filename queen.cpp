#include "queen.h"
#include <iostream>

Queen::Queen(int _player, int _row, int _col, PiecesArray &board)
        : Piece(_player, _row, _col, board) {
//    std::cout << "Creating a Queen\n";
}

Queen::~Queen() {
//    std::cout << "Killing a Queen :s\n";
}

void Queen::Draw() {
    std::cout << "Q";
}


Queen::Queen(int _player, string _position, PiecesArray &_board) : Piece(_player, _position, _board) {

}

bool Queen::Validate(string dest)
{
        bool V= false;
        int cd = (int) (dest[0] - 'a'); // letters are the columns
        int rd = (int) 8 - (dest[1] - '0'); // numbers are rows
        int i=1, flag=0;
                if ((rd-r)/(cd-c) == -1)
                {
                        if(cd-c<0)
                        {
                                        for(i=1;i<c-cd;i++)
                                                if(board[r+i][c-i]!=NULL)
                                                        flag=1;
                                        if(flag==0)
                                                return V=true;
                        }
                        else
                        {
                                        for(i=1;i<cd-c;i++)
                                                if(board[r-i][c+i]!=NULL)
                                                        flag=1;
                                        if(flag==0)
                                                V=true;
                        }

                }
		if((d-c)/(rd-r) == 1)
		 {
                        if(cd-c<0)
                        {
                                        for(i=1;i<c-cd;i++)
                                                if(board[r-i][c-i]!=NULL)
                                                        flag=1;
                                        if(flag==0)
                                                V=true;
                        }
                        else
                        {
                                        for(i=1;i<cd-c;i++)
                                                if(board[r+i][c+i]!=NULL)
                                                        flag=1;
                                        if(flag==0)
                                                V=true;
                        }

                }
                if(player==1)
                        if(V==true && board[rd][cd]==NULL)
                        {
                                if(board[rd][cd]->player==2)
                                        return V=true;
                                else
                                        return V=false;
                        }
                else
                        if(V==true && board[rd][cd]==NULL)
                        {
                                if(board[rd][cd]->player==1)
                                        return V=true;
                                else
                                        return V=false;
                        }
}
