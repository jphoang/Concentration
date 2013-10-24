#include "cs1037lib-window.h" 
#include "cs1037lib-time.h"   
#include <iostream>
#include <time.h>
#include "Bag.h"
#include "DynArray.h"
#include "ImageCard.h"

using namespace std;


DynArray<ImageCard *> cards;
ImageCard* first = NULL;
ImageCard* second = NULL;
int good(0),bad(0);


void clear_cards();
void init_cards();
void draw_cards();
void check_pair_matches(); 
void reveal_card(int i); 


int main()
{
	cout << "press 'n'-key to start a new game" << endl << endl;
	srand( (unsigned) time( NULL ) ); 
	init_cards();
	draw_cards();
	SetWindowTitle("Memory Game"); 
	SetWindowVisible(true); 

	while (!WasWindowClosed())
	{
		char c;
		if (GetKeyboardInput(&c)) 
		{
			if (c == 'n')      
			{
				clear_cards();
				init_cards();
				draw_cards();
			}
		}

		int x, y, button;
		if (GetMouseInput(&x, &y, &button)) 
		{
			if (button == 1)              
			{	
				for (int i=0; i<cards.getSize(); i++) 
					if (cards[i] && cards[i]->pointInCard(Point(x,y))) reveal_card(i);
				draw_cards();
			}
		}
	}
	clear_cards();
	return 0;
}

void draw_cards()
{
	
	SetDrawColour(255,255,255); DrawRectangleFilled(0,0,1280,1024);
	SetDrawColour(255,0,0); DrawText(10, 10, "Click on cards, choose pairs of the same denomination");
	int i,j; double line=0.001;
	for (i=0; i<cards.getSize(); i++) 
	{
		if(i%6==0) {j=0; line++;}
		if (cards[i]) {cards[i]->drawAt(Point(CARD_WIDTH*1.15*(j+1),CARD_HEIGHT*line*1.1));}
		j++;
	}



}

void init_cards() 
{
	int size = 8 + 2*(rand()%7);
	cards.resize(size);
	Suit suits[] = {SPADES, HEARTS, CLUBS, DIAMONDS};  
	Denomination denom[] = {N2,N3,N4,N5,N6,N7,N8,N9,N10,JACK,QUEEN,KING,ACE};
	Bag<ImageCard*> deck(size); 

	for (int i=0; i<size; i=i+2) 
	{
		Denomination tempDenom;
		cards[i] = new ImageCard(suits[rand()%4],tempDenom = denom[rand()%13]);
		
	
		int k=0;
		while(k < i) {
			if(cards[i] != NULL && cards[k]->getDenomination()==cards[i]->getDenomination() && cards[k]->getSuit() == cards[i]->getSuit()){
				delete cards[i];
				cards[i] = new ImageCard(suits[rand()%4],tempDenom = denom[rand()%13]);
				k=0;
				continue;
			}
			k++;
		}
		deck.add(cards[i]);
		
		cards[i+1] = new ImageCard(suits[rand()%4],tempDenom);
		int l=0;
		while(l < i+1){
			if(cards[i+1] != NULL && cards[l]->getDenomination()==cards[i+1]->getDenomination() && cards[l]->getSuit() == cards[i+1]->getSuit()){
				delete cards[i+1];
				cards[i+1] = new ImageCard(suits[rand()%4],tempDenom);
				l=0;
				continue;
			}
			l++;
		}
		deck.add(cards[i+1]);
	}

	for(int j=0;j<size;j++){
	cards[j] = deck.getOne();
	}

	
	cout << endl << "WELCOME TO A NEW GAME!" << endl << endl;
	cout << "Select your first card" << endl;
}

void reveal_card(int i)
{
	
		if (cards[i]) 
		{
			if (!cards[i]->isFaceUp()) cards[i]->setFaceUp();     
			draw_cards();
			if (first==NULL){first = cards[i]; cout<<"Select your second card now"<<endl;}
			else if(first != NULL && first != cards[i] && second == NULL) {second=cards[i];Pause(1000);check_pair_matches();return;}
			
		}
	
}

void check_pair_matches()
{
	
	if(first->getDenomination() == second->getDenomination())
	{
		for (int i=0;i<cards.getSize(); i++){
			if (cards[i] ==first ||cards[i]==second){
				delete cards[i]; 
				cards[i]=NULL;
			}
		}
		first = NULL;
		second =NULL;
		cout<<"Hurray, you got a matching pair :)"<<endl<<endl;
		good++;
		if(good == cards.getSize()/2){
			cout<<"GAME OVER, score: "<<good<<":"<<bad<<endl;
		}
		return;
	}else{
		first->setFaceDown();
		second->setFaceDown();
		draw_cards();
		cout<<"You will be luckier next time :("<<endl<<endl;
		cout << "Select your first card" << endl;
		first = NULL;
		second =NULL;
		bad++;
	}
	

}

void clear_cards()
{
	good=0;bad=0;
	for (int i=0; i<cards.getSize(); i++) 
		if (cards[i]) { 
			delete cards[i]; 
			cards[i]=NULL; 
	}


}