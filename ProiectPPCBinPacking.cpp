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
int deck[] = { Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
			 Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
			 Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
			 Ace,2,3,4,5,6,7,8,9,10,J,Q,K };

//int deck[] = { 2, 5, 4, 7, 1, 3, 8 };

/* Begin Function:shuffler **************************************************
Description : Shuffle a classic 52-Card deck.
Input       : None.
Output      : Shuffled deck.
Return      : None.
****************************************************************************/
int * shuffler() {
	srand((unsigned)time(0));
	for (int i = 0; i < 52; i++)
		swap(deck[i], deck[rand() % 52]);
	cout << "deck:" << endl;
	int t = 0;
	for (int j : deck) {
		cout << j << " ,";
		t++;
		if (t % 13 == 0) cout << endl;
	}
	return deck;
}
/* End Function:shuffler ***************************************************/

void ClaculProbabilitate() {
	int sumaBin = 0;
	double probabilitate = 0;
	int n = sizeof(deck) / sizeof(deck[0]);
	do {
		for (int i = 0; i < n; i++)
		{
			int cartiCareNuDauBust = 0;
			int cartiCareDauBust = 0;
			int puncteRamasePanaLaBust = 21;
			sumaBin += deck[i];
			puncteRamasePanaLaBust -= sumaBin;

			if (puncteRamasePanaLaBust > 0) {
				for (int j = i + 1; j < n - i + 1; j++)
				{
					if (deck[j] <= puncteRamasePanaLaBust) {
						cartiCareNuDauBust++;
					}
					else
					{
						cartiCareDauBust++;
					}
				}

				double cazuriFavorabile = cartiCareDauBust;
				double cazuriPosibile = n - i;

				probabilitate = cazuriFavorabile / cazuriPosibile;
				cout << "Probabilitate : " << probabilitate << endl;
			}
			else
			{
				return;
			}

		}
	} while (sumaBin <= 21);
}

int main()
{
	// Shuffle deck
	shuffler();

	//int binCapacity = 21;
	//int n = sizeof(deck) / sizeof(deck[0]);	
	//cout << "Number of bins required in Next Fit : "
	//	<< nextFit(deck, n, binCapacity);

	ClaculProbabilitate();
	return 0;

}


