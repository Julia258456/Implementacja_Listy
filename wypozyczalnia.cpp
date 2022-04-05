#include "wypozyczalnia.h"

int Wypozyczalnia::liczba_wypozyczalni = 0;

Wypozyczalnia::Wypozyczalnia() {
	liczba_wypozyczalni++;
	nazwa = "BRAK";
#ifdef _DEBUG
	std::cout << "Wypozyczalnia()" << nazwa << std::endl;
#endif // _DEBUG
}

Wypozyczalnia::Wypozyczalnia(int liczba_pracownikow) {
	for (int i = 0; i < liczba_pracownikow; i++) {
		Pracownik* p = new Pracownik();
		pracownicy.push_back(p);
	}
	liczba_wypozyczalni++;
	nazwa = "BRAK";
#ifdef _DEBUG
	std::cout << "Wypozyczalnia(int)" << nazwa << std::endl;
#endif // _DEBUG
}

Wypozyczalnia::Wypozyczalnia(std::string nazwa) {
	liczba_wypozyczalni++;
	this->nazwa = nazwa;
#ifdef _DEBUG
	std::cout << "Wypozyczalnia(string)" << nazwa << std::endl;
#endif // _DEBUG
}

Wypozyczalnia::Wypozyczalnia(std::string nazwa, int liczba_pracownikow) {
	this->nazwa = nazwa;
	liczba_wypozyczalni++;
	for (int i = 0; i < liczba_pracownikow; i++) {
		Pracownik* p = new Pracownik();
		pracownicy.push_back(p);
	}
#ifdef _DEBUG
	std::cout << "Wypozyczalnia(string, int)" << nazwa << std::endl; //!
#endif // _DEBUG
}

Wypozyczalnia::Wypozyczalnia(Wypozyczalnia& w) {
	this->nazwa = w.nazwa;
	this->siedzibaFirmy.setLiczbaPomieszczen(w.siedzibaFirmy.getLiczbaPomieszczen());
	this->siedzibaFirmy.setAdres(w.siedzibaFirmy.getAdres());

	for (int i = 0; i < w.pracownicy.size(); i++) {
		Pracownik* p = new Pracownik(w.pracownicy[i]->getWiek());
		this->pracownicy.push_back(p);
	}

	liczba_wypozyczalni++;
#ifdef _DEBUG
	std::cout << "Wypozyczalnia(Wypozyczalnia&)" << nazwa << std::endl;
#endif // _DEBUG
}

Wypozyczalnia::~Wypozyczalnia() {
	for (int i = 0; i < pracownicy.size(); i++) {
		delete pracownicy[i];
	}
	pracownicy.clear();
	liczba_wypozyczalni--;
#ifdef _DEBUG
	std::cout << " ~Wypozyczalnia()" << std::endl;
#endif //_DEBUG
}

bool  Wypozyczalnia::operator==(Wypozyczalnia& w) {

	if (nazwa != w.nazwa) {
		return false;
	}
	if (pracownicy.size() != w.pracownicy.size()) {
		return false;
	}
	for (int j = 0; j < pracownicy.size(); j++) {
		if (pracownicy[j] != w.pracownicy[j]) {
			return false;
		}
	}
	if (siedzibaFirmy.getLiczbaPomieszczen() != w.siedzibaFirmy.getLiczbaPomieszczen()) {
		return false;
	}
	if (siedzibaFirmy.getAdres() != w.siedzibaFirmy.getAdres()) {
		return false;
	}
	return true;
}

Wypozyczalnia& Wypozyczalnia::operator=(Wypozyczalnia& w) {

	if (&w == this) return *this;

	for (int i = 0; i < pracownicy.size(); i++) {
		delete pracownicy[i];
	}
	pracownicy.clear();


	this->nazwa = w.nazwa;
	siedzibaFirmy.setLiczbaPomieszczen(w.siedzibaFirmy.getLiczbaPomieszczen());
	siedzibaFirmy.setAdres(w.siedzibaFirmy.getAdres());

	for (int i = 0; i < w.pracownicy.size(); i++) {
		Pracownik* p = new Pracownik(w.pracownicy[i]->getWiek());
		this->pracownicy.push_back(p);
	}

	return *this;
}

Pracownik Wypozyczalnia::operator[](int j) {

	if (j > pracownicy.size()) {
		throw "Pracownik nie istnieje";
	}
	return *pracownicy[j];
}

std::ostream& operator<<(std::ostream& s, Wypozyczalnia& w) {
	w.Zapisz(s);

	return s;
}

std::istream& operator>>(std::istream& s, Wypozyczalnia& w) {
	w.Odczytaj(s);

	return s;
}

void Wypozyczalnia::Zapisz(std::ostream& s) {
	s << usunSpacje(nazwa) << std::endl << usunSpacje(siedzibaFirmy.getAdres()) << std::endl;
	s << getLiczbaPomieszczenW() << " " << pracownicy.size() << std::endl;

	int liczba_pracownikow = pracownicy.size();

	for (int i = 0; i < liczba_pracownikow; i++) {
		s << pracownicy[i]->getWiek();
		if (i + 1 < liczba_pracownikow) {
			s << " ";
		}
	}
	if (liczba_pracownikow > 0) {
		s << std::endl;
	}
}

void Wypozyczalnia::Odczytaj(std::istream& s) {

	s >> nazwa;
	std::string adres;
	s >> adres;

	int liczba_pomieszczen, liczba_pracownikow;
	s >> liczba_pomieszczen >> liczba_pracownikow;

	for (int i = 0; i < liczba_pracownikow; i++) {
		int wiek;
		s >> wiek;
		Pracownik* p = new Pracownik(wiek);
		pracownicy.push_back(p);
	}

	siedzibaFirmy.setAdres(adres);
	siedzibaFirmy.setLiczbaPomieszczen(liczba_pomieszczen);
}

Wypozyczalnia::operator std::string() {
	return " Nazwa wypozyczalni: " + this->nazwa + ". Liczba pracownikow: " + std::to_string(pracownicy.size())
		+ ". Adres: " + siedzibaFirmy.getAdres() + ". Liczba pomieszczen: "
		+ std::to_string(siedzibaFirmy.getLiczbaPomieszczen()) + ".\n";
}

Wypozyczalnia& Wypozyczalnia::operator++() {
	siedzibaFirmy.setLiczbaPomieszczen(siedzibaFirmy.getLiczbaPomieszczen() + 1);
	return *this;
}

Wypozyczalnia& Wypozyczalnia::operator++(int) {
	siedzibaFirmy.setLiczbaPomieszczen(siedzibaFirmy.getLiczbaPomieszczen() + 1);
	return *this;
}

int Wypozyczalnia::getLiczbaWypozyczalni() {
	return liczba_wypozyczalni;
}

std::string Wypozyczalnia::getNazwa() {
	return this->nazwa;
}

int Wypozyczalnia::getLiczbaPracownikow() {
	return pracownicy.size();
}

void Wypozyczalnia::KimJestem() {
	std::cout << "Jestem wypozyczalnia. Moja nazwa to: " << nazwa << std::endl;
}

void Wypozyczalnia::ZatrudnijPracownika(int wiek) {
	Pracownik* p = new Pracownik(wiek);
	pracownicy.push_back(p);
}