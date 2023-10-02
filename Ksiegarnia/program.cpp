#include <iostream>
#include <Windows.h>
#include "ksiegarnia.h"

int main() {
    Koszyk koszyk;

    KsiazkaPapierowa a("C++ - ksiega eksperta", "Jesse Liberty",
        "Helion", "Gliwice", 1999,
        "83-7179-130-3", 767, 99.9,
        "B6", "klejona twarda", 380, 870.6);
    KsiazkaPapierowa b("Aplikacje dla Windows", "Pawel Borkowski",
        "Helion", "Gliwice", 2008,
        "978-83-246-1881-1", 467, 45.7,
        "A6", "klejona miekka", 240, 240.5);
    KsiazkaElektroniczna c("Jezyk C++", "Bjarne Stroustrup",
        "WNT", "Warszawa", 2002,
        "83-204-2727-4", 988, 115.0,
        "DjVu", 1, 5009);

    koszyk.Dodaj(a);
    koszyk.Dodaj(b);
    koszyk.Dodaj(c);

    koszyk.DrukujListe(std::cout);
    system("pause");
    std::cout << std::endl;
    koszyk.DrukujFakture(std::cout);
    system("pause");
}
