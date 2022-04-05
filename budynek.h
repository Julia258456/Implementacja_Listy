#pragma once
#include <iostream>
#include <string>

/// Klasa reprezentujca firme
class Budynek {

public:
	/// Konstruktor domyslny
	Budynek();

	// Konstruktor kopiujcy 
	/**
	\param Budynek&  Obiekt klasy Budynek
	*/
	Budynek(Budynek& b);

	// Destruktor
	~Budynek();

	// Pobranie liczby pomieszczen
	/**
	\return Zwraca liczbe pomieszczen
	*/
	int getLiczbaPomieszczen();

	// Ustawianie liczby pomieszczen
	/**
	\param liczba_pomieszczen_ Liczba pomieszczen budynku
	*/
	void setLiczbaPomieszczen(int liczba_pomieszczen_);

	// Pobieranie adresu budynku 
	/**
	\return Zwraca adres budynku (string)
	*/
	std::string getAdres();

	// Ustawianie adresu budynku
	/**
	\param adres Adres budynku (string)
	*/
	void setAdres(std::string adres);

	// Operator przypisania
	/**
	\param Budynek& Obiekt klasy Budynek
	\return Zwraca obiekt klasy Budynek
	*/
	Budynek& operator=(const Budynek& b);

private:
	std::string adres = "brak"; ///< Adres budynku
	int liczba_pomieszczen = 0; ///< Liczba pomieszczen sklepu
};
