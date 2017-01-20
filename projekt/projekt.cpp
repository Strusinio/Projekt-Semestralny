#include "stdafx.h"  
#include <iostream> 
#include <conio.h> 
#include <cstdlib>
using namespace std;

#define ROZMIAR_PLANSZY 40
#define GORA 72
#define DOL 80
#define PRAWO 77
#define LEWO 75
#define PLUS 43
#define MINUS 45

void menu();
void Wczytaj(size_t &wysokosc, size_t &szerokosc, char &x);
void rysujPlansze();
char plansza[ROZMIAR_PLANSZY][ROZMIAR_PLANSZY];
void wypelnijPlansze(int x, int y, int rozmiarX, int rozmiarY, char wczytanyZnak);


int main()
{
	
	size_t wysokosc, szerokosc;
	int punktX = 0, punktY = 0;
	char x;
	
	
	

	menu();
	Wczytaj(wysokosc, szerokosc, x);
	wypelnijPlansze(punktX, punktY, szerokosc,wysokosc,x);
	int polowa = (szerokosc - 0.5) / 2;

	while (true) 
	{
		rysujPlansze();

		char wczytanyZnak = _getch();

		switch (wczytanyZnak)

		{
		case DOL :
			if (punktX + wysokosc < ROZMIAR_PLANSZY)
			{
				punktX += 1;
			}
			break;
		case GORA:
			if (punktX > 0) {
				punktX -= 1;
			}
			break;
		case PRAWO:
			if (punktY + szerokosc + polowa < ROZMIAR_PLANSZY)
			{
				punktY += 1;
			}
			break;
		case LEWO:
			if (punktY > 0)
			{
				punktY -= 1;
			}
			break;
		case PLUS:
			if (szerokosc + punktY + polowa +1  < ROZMIAR_PLANSZY && wysokosc + punktX < ROZMIAR_PLANSZY)
			{
				szerokosc += 1;
				wysokosc += 2;
				polowa += 1;
			}
			break;
		case MINUS:
			if (szerokosc > 0 && wysokosc > 2)
			{
				szerokosc -= 1;
				wysokosc -= 2;
				polowa -= 1;

			}
			break;
		default:
			break;
		}

		wypelnijPlansze(punktX, punktY, szerokosc, wysokosc, x);
		system("cls");
	}

	return 0;
}



void menu()
{
	cout << "PATRYK KASZUBOWSKI\t nr indeksu 16219" << endl;
	cout << "Napisz program rysowania znakiem ASCII ponizszej figury: " << endl;
	cout << "      *		   "<< endl;
	cout << "        *         "<< endl;
	cout << "          * * * * "<< endl;
	cout << "        *         "<< endl;
	cout << "      *           "<< endl; 
	cout << "Program powinien umozliwiac: "<<endl;
	cout << "- wybor znaku ASCII" << endl;
	cout << "- wczytanie poczatkowych rozmiarow figury"<<endl;
	cout << "- przesuwanie figury klawiszami lewo, prawo, gora, dol"<<endl;
	cout << " >>>Wcisnij dowolny klawisz aby kontynuowac<<<"<<endl;

	_getch();
}

void Wczytaj(size_t &wysokosc, size_t &szerokosc, char &x)
{
	
	cout << "ZNAK : ";
	cin >> x;

	cout << "SZEROKOSC = ";
	cin >> szerokosc;
	while (szerokosc>5)
		{
			cout << "podaj mniejsza szerokosc"<<endl;
			cin >> szerokosc;
		}
	cout << "WYSOKOSC = ";
	cin >> wysokosc;
	while(wysokosc > 5)
	{

		{
			cout << "podaj mniejsza wysokosc" << endl;
			cin >> wysokosc;
		}
		
	 if (wysokosc % 2 == 0)
		{
			cout << "Podaj liczbe nieparzysta" << endl;
			cin >> wysokosc;
		}
		
	}
	
	cout << endl;
}

void rysujPlansze()
{
	for (int i = 0; i < ROZMIAR_PLANSZY; i++)
	{
		for (int j = 0; j < ROZMIAR_PLANSZY; j++) 
		{
			cout << plansza[i][j];
		}
		cout << endl;
	}
}

void wypelnijPlansze(int x, int y, int rozmiarX, int rozmiarY, char wczytanyZnak)
{
	//czyszczenie tablicy
	for (int i = 0; i < ROZMIAR_PLANSZY; i++) 
	{
		for (int j = 0; j < ROZMIAR_PLANSZY; j++)
		{
			plansza[i][j] = ' ';
		}
	}
	
	int polowa=(rozmiarY - 0.5) / 2;
	for (int i = 0; i < polowa; i++)
	{
		plansza[i+x ][i+y] = wczytanyZnak;
	}
	for (int i = 0; i < polowa; i++)
	{
		plansza[rozmiarY-i-1+x][i+y] = wczytanyZnak;
	}
	for (int i = polowa; i < rozmiarX+polowa; i++)
	{
		plansza[polowa +x][i+y] = wczytanyZnak;
	}
}







