//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#include <algorithm>
#include <Pociag.h>
#include <sstream>
#include <Stacja.h>


Stacja::Stacja() {}

Stacja::~Stacja() {

}


bool Stacja::pociagOdjezdza(Pociag_ptr pociagOdjezdzajacy) {
    /*
     * Pociag wyrusza ze stacji czyli znajdz go w bazie pociagow na danej stacji
     * jezeli tam jest to go usun i zmien jego stan na to ze nie jest przy peronie
     * czyli jest 'w trasie'
     */
    auto it = std::find(pociagi.begin(), pociagi.end(), pociagOdjezdzajacy);
    if(it != pociagi.end())
    {
        pociagi.erase(it);
        pociagOdjezdzajacy->setPrzyPeronie(false);
        pojemnoscStacji = pojemnoscStacji+1;
        return true;
    }
    return false;
}


bool Stacja::pociagWjechal(Pociag_ptr pociagWjezdza) {
/*
 * Jezeli pociag nie jest przy zadnym peronie to znaczy ze jest w drodze (nie na stacji)
 * Jezeli tak to dodaj pociag do aktualnej stacji i zmien jego stan na to ze jest przy peronie
 *
 */

    if(pociagWjezdza->przyPeronie()==false and pojemnoscStacji>=1) {
        pociagi.push_back(pociagWjezdza);
        pojemnoscStacji = pojemnoscStacji-1;
        pociagWjezdza->setPrzyPeronie(true);
        return true;
    }
    return false;

}

int Stacja::pobierzLiczbePociagow() {
    return (int)pociagi.size();
}


std::string Stacja::informacja() {
    std::stringstream ss;
    ss << " Stacja pociagow, liczba pociagow : " << std::to_string(pobierzLiczbePociagow()) << "\n";
    for (auto pociag : pociagi) {
        ss << pociag->toString() << "\n";
    }
    return ss.str();
}

std::string Stacja::getPociagNazwa(int informacjaOKtorymPociagu) {
    /*
     * Stacja::GetPociagNazwa pozwala zwrocic informacje o pojedynczym pociagu znajdujacym sie na stacji
     * indeksujac je od 0 tak jak sa w kolejnosci w wektorze.
     * 0...inf
     */

    if(informacjaOKtorymPociagu>=(int)pociagi.size())
    {
        std::string wyjatek = "Chcesz wyswietlic informacje o pociagu ktorego nie ma w indeksie !";
        throw std::invalid_argument(wyjatek);
    }

    return pociagi[informacjaOKtorymPociagu]->toString();
}

Stacja::Stacja(unsigned int pojemnoscStacji) : pojemnoscStacji(pojemnoscStacji) {}

unsigned int Stacja::getPojemnoscStacji() const {
    return pojemnoscStacji;
}

void Stacja::setPojemnoscStacji(unsigned int pojemnoscStacji) {
    Stacja::pojemnoscStacji = pojemnoscStacji;
}

