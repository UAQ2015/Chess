#include "chessboard.h"

#include <iostream>

using namespace std;

ChessBoard::ChessBoard():
    board{ 0 }
{
    turn = 1;
    winner = 0;

    FillBoard();
    Draw();
}

void ChessBoard::FillBoard()
{
    int row;
    Pawn *p=NULL;
    for(int j=1;j<=2;j++)
        for(int i=0;i<8;i++)
        {
            row= 1+5*(j-1);
            p= new Pawn(j, row, i);
            board[row][i]= p;
        }

    Bishop *b=NULL;
      for(int j=1;j<=2;j++)
        for(int i=2;i<=5;i=i+3)
        {
            row=7*(j-1);
            b= new Bishop(j, row, i);
            board[row][i]= b;
        }

     Rook *r=NULL;
      for(int j=1;j<=2;j++)
        for(int i=0;i<=7;i=i+7)
        {
            row=7*(j-1);
            r= new Rook(j, row, i);
            board[row][i]= r;
        }
    Knight *c=NULL;
      for(int j=1;j<=2;j++)
        for(int i=1;i<=6;i=5+i)
        {
            row=7*(j-1);
            c= new Knight(j, row, i);
            board[row][i]= c;
        }
     Queen *q=NULL;
      for(int j=1;j<=2;j++)
        {
            row=7*(j-1);
            q= new Queen(j, row, 3);
            board[row][3]= q;
        }

     King *k=NULL;
      for(int j=1;j<=2;j++)
        {
            row=7*(j-1);
            k= new King(j, row, 4);
            board[row][4]= k;
        }



	
    // TODO put all of the other pieces

}

void ChessBoard::Draw()
{
    Piece *p=NULL;
    char white= ' ';
    char black= '#';
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
        {
            p=board[i][j];
            if (p==NULL){
                if ((i+j)%2==0){
                    cout<<white;
                }else{
                    cout<<black;
                }
            }else{
                p->Draw();
            }

        }
        cout<<endl;
    }
}

