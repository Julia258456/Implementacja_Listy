#pragma once
#include "pracownik.h"
#include "budynek.h"
#include <iostream>
#include <string>
#include <vector>

/// Klasa reprezentujca firme
class Firma {
public:
	/// Konstruktor domyslny 
	Firma();

	// Destruktor
	virtual ~Firma();

	// Operator wyjscia
	/**
	\param Firma& Obiekt klasy Firma
	\param ostream& Obiekt klasy ostream
	\return Zwraca strumien wyjscia
	*/
	friend std::ostream& operator <<(std::ostream&, Firma&);

	// Operator wejscia
	/**
	\param Firma& Obiekt klasy Firma
	\param istream& Obiekt klasy istream
	\return Zwraca strumien wejscia
	*/
	friend std::istream& operator >>(std::istream&, Firma&);

	// Funkcja dodajaca pracownika
	/**
	\param wiek Wiek pracownika
	*/
	virtual void ZatrudnijPracownika(int) = 0;

	// Pobieranie nazwy wypozyczalni
	/**
	\return Zwraca nazwe wypozyczalni
	*/
	virtual std::string getNazwa() = 0;

	// Pobranie liczby pracownikow
	/**
	\return Zwraca liczbe pracownikow
	*/
	virtual int getLiczbaPracownikow() = 0;

	// Wypisywanie klasy stworzonego obiektu na konsole
	virtual void KimJestem() = 0;

	// Pobieranie liczby pomieszczen siedziby
	/**
	\return Zwraca liczbe pomieszczen w siedzibie firmy (int)
	*/
	int getLiczbaPomieszczenW();

	// Ustawianie liczby pomieszczen siedziby
	/**
	\param liczba_pomieszczen_ Liczba pomieszcze w siedzibie firmy (int)
	*/
	void setLiczbaPomieszczenW(int liczba_pomieszczen_);

	// Pobieranie adresu siedziby 
	/**
	\return Zwraca adres siedziby firmy (string)
	*/
	std::string getAdresW();

	// Ustawianie adresu siedziby
	/**
	\param adres Adres siedziby firmy (string)
	*/
	void setAdresW(std::string adres);

protected:
	std::string nazwa; ///< Nazwa firmy
	std::vector<Pracownik*> pracownicy; ///< Pole dynamiczne (obiekty klasy Pracownik)
	Budynek siedzibaFirmy; ///< Pole automatyczne (obiekt klasy Budynek)

	// Funkcja odczytu z pliku
	/**
	\param istream& Obiekt klasy istream
	*/
	virtual void Odczytaj(std::istream& strum) = 0;

	// Funkcja zapisu do pliku
	/**
	\param ostream& Obiekt klasy ostream
	*/
	virtual void Zapisz(std::ostream& strum) = 0;

	// Funkcja usuwajaca spacje ze zmiennej typu string
	/**
	\param string Zmienna typu string zawierajaca spacje
	\return Zwraca zmienna typu string bez spacji
	*/
	std::string usunSpacje(std::string str);
}; 
