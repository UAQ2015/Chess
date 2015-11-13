#include <iostream>
#include <string>
#include "chessboard.h"

using namespace std;

int main()
{
    ChessBoard cb;

	cb.TestRook();
/*
	while(cb.winner==0){
		do{
			cout<<"Move piece from :\n";
			cin>>move;
			p= cb.GetPiece(move);
			cout<<"Move piece to:\n";
			cin>>move;
			v= cb.Validate(p, move);

			if(v==true){
				cb.Move(p, move);
			}else{
				cout<<"Error\n";
			}

		}while(v==false);

		cb.ChangeTurn();
	}
*/

    
	cout<<"Done.\n";
    return 0;	
}

