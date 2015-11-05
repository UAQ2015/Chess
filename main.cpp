#include <iostream>
#include <string>
#include "chessboard.h"

using namespace std;

int main()
{
	string move;
	bool v=false;
    ChessBoard cb;
	Piece *p=NULL;
	cout<< "Test getting a piece from the chessboard\n";
	p= cb.GetPiece("a4");

	if (p!=NULL) {
		p->Draw();
		cout<<"player: "<< p->player<<endl;
	}
	else cout<<"null";

	v=cb.Validate(p, "a1");
	cout<< (v==true?"valid\n":"unvalid\n");


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

    
    
    return 0;	
}

