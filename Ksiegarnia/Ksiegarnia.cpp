#include "ksiegarnia.h"

Ksiazka::Ksiazka(std::string tytul, std::string autor, std::string wydawnictwo, std::string miejsce,
    int rok, std::string ISBN, int strony, double cena)
    : tytul_(tytul), autor_(autor), wydawnictwo_(wydawnictwo), miejsce_(miejsce), rok_(rok),
    ISBN_(ISBN), strony_(strony), cena_(cena) {}

Ksiazka::~Ksiazka() {}

void Ksiazka::DrukujDane(std::ostream& wyjscie) const {
    wyjscie << "\t" << tytul_ << " , " << autor_ << " , " << wydawnictwo_ << ", " << miejsce_ << " " << rok_ << std::endl;
    wyjscie << "ISBN: " << ISBN_ << std::endl;
    wyjscie << "liczba stron: " << strony_ << std::endl;
    wyjscie << "cena detaliczna: " << cena_ << " zl" << std::endl;
}
void Ksiazka::DrukujDaneDoFaktury(std::ostream& wyjscie) const {
    wyjscie << "\t" << tytul_ << "\t|\t" << ISBN_ << " |       " << cena_ << "|" << std::endl;
    wyjscie <<"|\t\t" << autor_  << "\t|" << "\t\t\t\b\b" << "|" << "\t\t  |" << std::endl;
    wyjscie << "+-------------------------------+---------------------+-----------+" << std::endl;
}

KsiazkaPapierowa::KsiazkaPapierowa(std::string tytul, std::string autor, std::string wydawnictwo, std::string miejsce,
    int rok, std::string ISBN, int strony, double cena, std::string format,
    std::string okladka, int kartki, double masa)
    : Ksiazka(tytul, autor, wydawnictwo, miejsce, rok, ISBN, strony, cena),
    format_(format), okladka_(okladka), kartki_(kartki), masa_(masa) {}

void KsiazkaPapierowa::OpisTechniczny(std::ostream& wyjscie) const {
    wyjscie << "format papieru: " << format_ << std::endl;
    wyjscie << "rodzaj okladki: " << okladka_ << std::endl;
    wyjscie << "liczba kartek: " << kartki_ << std::endl;
    wyjscie << "masa ksiazki: " << masa_ << " g" << std::endl;
}

KsiazkaElektroniczna::KsiazkaElektroniczna(std::string tytul, std::string autor, std::string wydawnictwo, std::string miejsce,
    int rok, std::string ISBN, int strony, double cena, std::string format,
    int pliki, int pojemnosc)
    : Ksiazka(tytul, autor, wydawnictwo, miejsce, rok, ISBN, strony, cena),
    format_(format), pliki_(pliki), pojemnosc_(pojemnosc) {}

void KsiazkaElektroniczna::OpisTechniczny(std::ostream& wyjscie) const {
    wyjscie << "format pliku: " << format_ << std::endl;
    wyjscie << "liczba plikow: " << pliki_ << std::endl;
    wyjscie << "pojemnosc ksiazki: " << pojemnosc_ << " kB" << std::endl;
}

Koszyk::Koszyk() : ilosc_(0), cena_(0.0) {}

void Koszyk::Dodaj(Ksiazka& ksiazka) {
    if (ilosc_ < maxilosc) {
        ksiazki_[ilosc_] = &ksiazka;
        ilosc_++;
        cena_ += ksiazka.getCena();
    }
}

void Koszyk::DrukujListe(std::ostream& wyjscie) const {
    for (int i = 0; i < ilosc_; i++) {
        wyjscie << i + 1 << ") ";
        ksiazki_[i]->DrukujDane(wyjscie);
        ksiazki_[i]->OpisTechniczny(wyjscie);
        wyjscie << std::endl;
    }
}

void Koszyk::DrukujFakture(std::ostream& wyjscie) const {
    wyjscie << "+-------------------------------+---------------------+-----------+" << std::endl;
    wyjscie << "|                       Ksiazka |                ISBN |   Cena zl |" << std::endl;
    wyjscie << "+-------------------------------+---------------------+-----------+" << std::endl;
    for (int i = 0; i < ilosc_; i++) {
       wyjscie << "| ";
        ksiazki_[i]->DrukujDaneDoFaktury(wyjscie);
     //   wyjscie << " |" << std::endl;
    }
    wyjscie << "+-------------------------------+---------------------+-----------+" << std::endl;
    wyjscie << "|                                              Razem:       " << cena_ << " |" << std::endl;
    wyjscie << "+-------------------------------+---------------------+-----------+" << std::endl;
}

