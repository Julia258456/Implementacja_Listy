#include "firma.h"

Firma::Firma() {
#ifdef _DEBUG
	std::cout << "Firma()" << std::endl;
#endif // _DEBUG
}

Firma::~Firma() {
#ifdef _DEBUG
	std::cout << "Firma()" << std::endl;
#endif //_DEBUG
}

int Firma::getLiczbaPomieszczenW() {
	return siedzibaFirmy.getLiczbaPomieszczen();
}

void Firma::setLiczbaPomieszczenW(int liczba_pomieszczen) {
	siedzibaFirmy.setLiczbaPomieszczen(liczba_pomieszczen);
}

std::string Firma::getAdresW() {
	return siedzibaFirmy.getAdres();
}

void Firma::setAdresW(std::string adres) {
	siedzibaFirmy.setAdres(adres);
}

std::ostream& operator <<(std::ostream& strum, Firma& f)
{
	f.Zapisz(strum);
	return strum;
}

std::istream& operator >>(std::istream& strum, Firma& f)
{
	f.Odczytaj(strum);
	return strum;
}

std::string Firma::usunSpacje(std::string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}