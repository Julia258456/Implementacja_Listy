#include <iostream>
#include "budynek.h"
#include <string>

Budynek::Budynek() {
#ifdef _DEBUG
	std::cout << "Budynek() " << std::endl;
#endif // _DEBUG
}

Budynek::Budynek(Budynek& b) {
	setLiczbaPomieszczen(b.getLiczbaPomieszczen());
	setAdres(b.getAdres());
#ifdef _DEBUG
	std::cout << "Budynek(Budynek&) " << std::endl;
#endif // _DEBUG
}

Budynek::~Budynek() {
#ifdef _DEBUG
	std::cout << "~Budynek()" << std::endl;
#endif //_DEBUG
}

int Budynek::getLiczbaPomieszczen() {
	return liczba_pomieszczen;
}

void Budynek::setLiczbaPomieszczen(int liczba_pomieszczen_) {
	liczba_pomieszczen = liczba_pomieszczen_;
}

std::string Budynek::getAdres() {
	return adres;
}
void Budynek::setAdres(std::string adres) {
	this->adres = adres;
}

Budynek& Budynek::operator=(const Budynek& b) {
	liczba_pomieszczen = b.liczba_pomieszczen;
	adres = b.adres;
	return *this;
}