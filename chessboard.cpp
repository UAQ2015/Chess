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

