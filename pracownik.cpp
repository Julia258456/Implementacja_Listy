#include <iostream>
#include "pracownik.h"

int Pracownik::liczba_pracownikow = 0;

Pracownik::Pracownik() {
	liczba_pracownikow++;
	wiek = 0;
#ifdef _DEBUG
	std::cout << "Pracownik()" << std::endl;
#endif //_DEBUG
}

Pracownik::Pracownik(int wiek) {
	this->wiek = wiek;
	liczba_pracownikow++;
#ifdef _DEBUG
	std::cout << "Pracownik(int)" << std::endl;
#endif //_DEBUG
}

Pracownik::Pracownik(Pracownik& p) {
	this->wiek = p.wiek;
	liczba_pracownikow++;
#ifdef _DEBUG
	std::cout << "Pracownik(Pracownik&)" << std::endl;
#endif //_DEBUG
}

Pracownik::~Pracownik() {
	liczba_pracownikow--;
#ifdef _DEBUG
	std::cout << "~Pracownik()" << std::endl;
#endif //_DEBUG
}

int Pracownik::getWiek() {
	return wiek;
}

void Pracownik::setWiek(int wiek) {
	this->wiek = wiek;
}

int Pracownik::getLiczbaPracownikow() {
	return liczba_pracownikow;
}

bool Pracownik::operator==(const Pracownik& p) {
	return wiek == p.wiek;
}

bool Pracownik::operator!=(const Pracownik& p) {
	return !(*this == p);
}

Pracownik& Pracownik::operator=(const Pracownik& p) {
	wiek = p.wiek;
	return *this;
}

