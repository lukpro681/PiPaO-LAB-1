#pragma once
#ifndef KSIEGARNIA_H
#define KSIEGARNIA_H

#include <iostream>
#include <string>

class Ksiazka {
public:
    Ksiazka(std::string tytul, std::string autor, std::string wydawnictwo, std::string miejsce,
        int rok, std::string ISBN, int strony, double cena);
    virtual ~Ksiazka();
    virtual void OpisTechniczny(std::ostream& wyjscie) const = 0;
    void DrukujDane(std::ostream& wyjscie) const;
    void DrukujDaneDoFaktury(std::ostream& wyjscie) const;
    double getCena() { return cena_; }

private:
    std::string tytul_;
    std::string autor_;
    std::string wydawnictwo_;
    std::string miejsce_;
    int rok_;
    std::string ISBN_;
    int strony_;
    double cena_;
};

class KsiazkaPapierowa : public Ksiazka {
public:
    KsiazkaPapierowa(std::string tytul, std::string autor, std::string wydawnictwo, std::string miejsce,
        int rok, std::string ISBN, int strony, double cena, std::string format,
        std::string okladka, int kartki, double masa);
    void OpisTechniczny(std::ostream& wyjscie) const;

private:
    std::string format_;
    std::string okladka_;
    int kartki_;
    double masa_;
};

class KsiazkaElektroniczna : public Ksiazka {
public:
    KsiazkaElektroniczna(std::string tytul, std::string autor, std::string wydawnictwo, std::string miejsce,
        int rok, std::string ISBN, int strony, double cena, std::string format,
        int pliki, int pojemnosc);
    void OpisTechniczny(std::ostream& wyjscie) const;

private:
    std::string format_;
    int pliki_;
    int pojemnosc_;
};

class Koszyk {
public:
    static const int maxilosc = 100;

    Koszyk();
    void Dodaj(Ksiazka& ksiazka);
    void DrukujListe(std::ostream& wyjscie) const;
    void DrukujFakture(std::ostream& wyjscie) const;

private:
    Ksiazka* ksiazki_[maxilosc];
    int ilosc_;
    double cena_;
};

#endif
