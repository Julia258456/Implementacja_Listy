#include <iostream>
#include <fstream>
#include <exception>
#include "lista.h"
#include "wypozyczalnia.h"

using namespace std;

void Test1();

int main()
{
	Test1();

	return 0;
}

void Test1() {

	List<Wypozyczalnia> l1 = List<Wypozyczalnia>();
	std::ifstream plikOWypozyczalnia;
	std::ofstream plikZWypozyczalnia;

	Wypozyczalnia* wypozyczalniaTmp1 = new Wypozyczalnia("Biblioteka", 5);
	l1.push_back(*wypozyczalniaTmp1);
	Wypozyczalnia* wypozyczalniaTmp2 = new Wypozyczalnia("Wypozyczalniakaset", 2);
	l1.push_back(*wypozyczalniaTmp2);
	Wypozyczalnia* wypozyczalniaTmp3 = new Wypozyczalnia("Wypozyczalniagier", 3);
	l1.push_back(*wypozyczalniaTmp3);


	plikZWypozyczalnia.open("plikWypozyczalnia.txt");
	if (plikZWypozyczalnia.good()) {
		plikZWypozyczalnia << l1;
	}
	plikZWypozyczalnia.close();

	List<Wypozyczalnia> l2 = List<Wypozyczalnia>();

	plikOWypozyczalnia.open("plikWypozyczalnia.txt");
	if (plikOWypozyczalnia.good()) {
		plikOWypozyczalnia >> l2;
	}
	plikOWypozyczalnia.close();
	bool x = (l1 == l2);

	List<Wypozyczalnia> l3 = List<Wypozyczalnia>();
	l3 = l2;
	bool y = (l3 == l2);

	l1.print();
	l2.print();
	l3.print();
	cout << "1 jesli listy l1 i l2 sa takie same: " << x << endl;
	cout << "1 jesli listy l2 i l3 sa takie same: " << y << endl;

	cout << "Indeks 1: " << l3.indexOf(l3[1]->value) << endl;

	int kontynuuj = 1;
	do {
		int opcja = 0;
		cout << "Wybierz opcje:" << endl;
		cout << "1. Dodaj element do listy." << endl;
		cout << "2. Usun element z listy." << endl;
		cout << "3. Zamien kolejnosc dwoch elementow listy." << endl;
		cout << "4. Zapisz zmiany do pliku." << endl;
		cout << "5. Odczytaj istniejacy plik." << endl;
		cout << "6. Wyswietl liczbe elementow w liscie." << endl;
		cout << "7. Wyswietl liste." << endl;
		cout << "8. Usun ostatni element." << endl;
		cout << "9. Usun pierwszy element." << endl;
		cout << "10. Przenies obiekt na poczatek listy." << endl;
		cout << "11. Zakoncz program." << endl;
		cin >> opcja;

		switch (opcja) {
		case 1:
			try {
				cout << "Podaj jaki indeks ma miec nowy element" << endl;
				int n;
				cin >> n;
				Wypozyczalnia* w1 = new Wypozyczalnia();
				l2.insert(*w1, n);
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		case 2:
			try {
				cout << "Podaj indeks elementu do usunięcia" << endl;
				int j;
				cin >> j;
				l2[j];
				l2.erase(l2[j]);
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		case 3:
			try {
				cout << "Podaj indeksy elementow do zamiany" << endl;
				int k, l;
				cin >> k;
				cin >> l;
				l2[k];
				l2[l];
				l2.swapElements(l2[k], l2[l]);
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		case 4:
			try {
				plikZWypozyczalnia.open("plikWypozyczalnia.txt");
				if (plikZWypozyczalnia.good()) {
					plikZWypozyczalnia << l2;
				}
				plikZWypozyczalnia.close();
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		case 5:
			try {
				plikOWypozyczalnia.open("plikWypozyczalnia.txt");
				if (plikOWypozyczalnia.good()) {
					plikOWypozyczalnia >> l2;
				}
				plikOWypozyczalnia.close();

				l2.print();
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		case 6:
			try {
				cout << "Liczba elementow l2: " << l2.getSize() << endl;
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		case 7:
			try {
				l2.print();
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		case 8:
			try {
				l2.pop_back();
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		case 9:
			try {
				l2.pop_front();
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		case 10:
			try {
				cout << "Podaj indeks elementu do przeniesienia" << endl;
				int j;
				cin >> j;
				l2.moveToFront(j);
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		case 11:
			try {
				cout << "Na pewno zakonczyc działanie programu?(11-tak)" << endl;
				cin >> kontynuuj;
			}
			catch (exception e) {
				cout << "Wyjatek: " << e.what() << endl;
			}
			break;
		}
	} while (kontynuuj != 11);
}
