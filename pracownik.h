#pragma once

/// Klasa reprezentujca pracownika
class Pracownik {

public:
	/// Konstruktor domyslny 
	Pracownik();

	// Konstruktor z parametrem
	/**
	\param wiek Wiek pracownika
	*/
	Pracownik(int wiek);

	// Konstruktor kopiujcy 
	/**
	\param Pracownik&  Obiekt klasy Pracownik
	*/
	Pracownik(Pracownik& p);

	// Destruktor 
	~Pracownik();

	// Pobranie wieku pracownika
	/**
	\return Zwraca wiek pracownika
	*/
	int getWiek();

	// Ustawianie wieku pracownika
	/**
	\param wiek Wiek pracownika
	*/
	void setWiek(int wiek);

	// Pobieranie liczby obiektow klasy pracownik
	/**
	\return Zwraca zmienna typu int
	*/
	static int getLiczbaPracownikow();

	// Operator porownania (prawda jesli sa rowne)
	/**
	\param Pracownik& Obiekt klasy Pracownik
	\return Zwraca prawd lub fasz
	*/
	bool operator==(const Pracownik&);

	// Operator porownania (prawda jesli nie sa rowne)
	/**
	\param Pracownik& Obiekt klasy Pracownik
	\return Zwraca prawd lub fasz
	*/
	bool operator!=(const Pracownik&);

	// Operator przypisania
	/**
	\param Pracownik& Obiekt klasy Pracownik
	\return Zwraca obiekt klasy Pracownik
	*/
	Pracownik& operator=(const Pracownik& p);

private:
	int wiek; ///< Wiek pracownika
	static int liczba_pracownikow; ///< Statyczne pole klasy (okresla liczbe stworzonych pracownikow)
};
#pragma once
