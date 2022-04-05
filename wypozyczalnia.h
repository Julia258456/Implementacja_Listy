#pragma once
#include "firma.h"
#include "pracownik.h"
#include "budynek.h"

/// Klasa reprezentujca wypozyczalnie
class Wypozyczalnia : public Firma {
public:
	/// Konstruktor domyslny 
	Wypozyczalnia();

	// Konstruktor z parametrem
	/**
	\param nazwa nazwa wypozyczalni
	*/
	Wypozyczalnia(std::string nazwa);

	// Konstruktor z parametrem
	/**
	\param liczba_pracownikow liczba pracownikow wypozyczalni
	*/
	Wypozyczalnia(int liczba_pracownikow);

	// Konstruktor z parametrami
	/**
	\param nazwa nazwa wypozyczalni
	\param liczba_pracownikow liczba pracownikow wypozyczalni
	*/
	Wypozyczalnia(std::string nazwa, int liczba_pracownikow);

	// Konstruktor kopiujcy 
	/**
	\param Wypozyczalnia&  Obiekt klasy Wypozyczalnia
	*/
	Wypozyczalnia(Wypozyczalnia&);

	// Destruktor 
	virtual ~Wypozyczalnia();

	// Operator porownania
	/**
	\param Wypozyczalnia &w Obiekt klasy Wypozyczalnia
	\return Zwraca prawd lub fasz
	*/
	bool operator==(Wypozyczalnia&);

	// Operator przypisania
	/**
	\param Wypozyczalnia& Obiekt klasy Wypoyczalnia
	\return Zwraca obiekt klasy Wypozyczalnia
	*/
	Wypozyczalnia& operator=(Wypozyczalnia&);

	// Operator indeksowy
	/**
	\param j Zmienna typu int
	\return Zwraca obiekt klasy Pracownik
	*/
	Pracownik operator[](int j);

	// Operator konwersji
	/**
	\return Zwraca obiekt klasy string
	*/
	operator std::string();

	// Operator inkrementacji
	/** Zwieksza o jeden liczbe pomieszczen w siedzibie firmy
	\return Zwraca obiekt klasy Wypozyczalnia
	*/
	Wypozyczalnia& operator++();

	// Operator postinkrementacji
	/** Zwieksza o jeden liczbe pomieszczen w siedzibie firmy
	\return Zwraca obiekt klasy Wypoyczalnia
	*/
	Wypozyczalnia& operator++(int);


	// Pobieranie liczby obiektw klasy Wypozyczalnia
	/**
	\return Zwraca zmienn typu int
	*/
	static int getLiczbaWypozyczalni();

	// Operator wyjscia
	/**
	\param Wypozyczalnia& Obiekt klasy Wypozyczalnia
	\param ostream& Obiekt klasy ostream
	\return Zwraca strumien wyjscia
	*/
	friend std::ostream& operator <<(std::ostream& s, Wypozyczalnia& w);

	// Operator wejscia
	/**
	\param Wypozyczalnia& Obiekt klasy Wypozyczalnia
	\param istream& Obiekt klasy istream
	\return Zwraca strumien wejscia
	*/
	friend std::istream& operator >>(std::istream& s, Wypozyczalnia& w);

	// Pobranie liczby pracownikow
	/**
	\return Zwraca liczbe pracownikow
	*/
	int getLiczbaPracownikow();

	// Funkcja dodajaca pracownika
	/**
	\param wiek Wiek pracownika
	*/
	void ZatrudnijPracownika(int wiek);

	// Pobieranie nazwy wypozyczalni
	/**
	\return Zwraca nazwe wypozyczalni
	*/
	std::string getNazwa();

	// Wypisywanie klasy stworzonego obiektu na konsole
	void KimJestem();

protected:
	static int liczba_wypozyczalni; ///< Statyczne pole klasy (okresla liczbe stworzonych wypozyczalni)

	// Funkcja zapisu do pliku
	/**
	\param ostream& Obiekt klasy ostream
	*/
	void Zapisz(std::ostream&);

	// Funkcja odczytu z pliku
	/**
	\param istream& Obiekt klasy istream
	*/
	void Odczytaj(std::istream&);
};