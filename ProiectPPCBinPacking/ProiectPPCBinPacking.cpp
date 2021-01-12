// ProiectPPCBinPacking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Global variables
int Ace = 1;
int J = 10;
int Q = 10;
int K = 10;
vector<int>deck;

/* Begin Function:init_deck **************************************************
Description : Initialize a classic 52-Card deck.
Input       : None.
Output      : Initialized deck.
Return      : None.
******************************************************************************/
void init_deck() {
	deck = { Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
			 Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
			 Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
			 Ace,2,3,4,5,6,7,8,9,10,J,Q,K };
}
/* End Function:init_deck ****************************************************/


/* Begin Function:shuffler **************************************************
Description : Shuffle a classic 52-Card deck.
Input       : None.
Output      : Shuffled deck.
Return      : None.
****************************************************************************/
void shuffler() {
	srand((unsigned)time(0));
	for (int i = 0; i < 52; i++)
		swap(deck[i], deck[rand() % 52]);
	cout << "******Deck Shuffled!******" << endl;
}
/* End Function:shuffler ***************************************************/

/* Begin Function:print_deck ************************************************
Description : Print the deck.
Input       : None.
Output      : Deck.
Return      : None.
****************************************************************************/
void print_deck() {
	cout << "deck:" << endl;
	int t = 0;
	for (auto i : deck) {
		cout << i << " ,";
		t++;
		if (t % 13 == 0) cout << endl;
	}
}
/* End Function:print_deck ************************************************/

int main()
{
	init_deck();
	// Shuffle deck
	shuffler();
	print_deck();

	// capacitatea containerului = 21 
	// nr de containere =  nr de playeri + delaer



	//int cardsValues[] = init_deck();
	//int c = 10;
	//int n = sizeof(weight) / sizeof(weight[0]);
	//cout << "Number of bins required in Next Fit : "
	//	<< nextFit(weight, n, c);
	return 0;
}

// Returns number of bins required using next fit online algorithm 
int nextFit(int weight[], int n, int c)
{
	// Initialize result (Count of bins) and remaining 
		// capacity in current bin. 
	int res = 0, bin_rem = c;

	// Place items one by one 
	for (int i = 0; i < n; i++) {
		// If this item can't fit in current bin 
		if (weight[i] > bin_rem) {
			res++; // Use a new bin 
			bin_rem = c - weight[i];
		}
		else
			bin_rem -= weight[i];
	}
	return res;
	}