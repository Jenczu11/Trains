//
// Created by Bartłomiej Jencz on 30.12.2018.
//
//Windows
#define BOOST_UUID_RANDOM_PROVIDER_FORCE_WINCRYPT
#include <Pociag.h>

#include "Pociag.h"
#include <algorithm>
#include <boost/uuid/random_generator.hpp>

Pociag::Pociag() {}



Pociag::Pociag(unsigned int iloscWagonow, unsigned int iloscOsobNaWagon) :
iloscWagonow(iloscWagonow),
iloscOsobNaWagon(iloscOsobNaWagon)
{
    //LINUX
    //this->UUID
    //WINDOWS
    this->UUID=boost::uuids::random_generator()();
    this->pojemnosc=iloscWagonow*iloscOsobNaWagon;
    this->czyPeron=false;
}



bool Pociag::przyPeronie() {
    return false;
}

bool Pociag::pasazerWysiada(Pasazer_ptr pasazerWysiadajacy) {
    auto it = std::find(pasazerowie.begin(), pasazerowie.end(), pasazerWysiadajacy);
    if(it != pasazerowie.end())
    {
        pasazerowie.erase(it);
        pojemnosc=pojemnosc+1;
        return true;
    }
    return false;
}

bool Pociag::pasazerWsiada(Pasazer_ptr pasazerWsiadajacy) {
    for(int i=0; i<pasazerWsiadajacy->bilety.size(); i++)
        if(this->pojemnosc-1>=0 && pasazerWsiadajacy->bilety[i]->getRodzajPociagu()==getRodzajPociagu()) {
            pasazerowie.push_back(pasazerWsiadajacy);
            pojemnosc=pojemnosc-1;
            return true;
        }
        return false;

}

std::string Pociag::getRodzajPociagu()  {
    return rodzajPociagu;
}

unsigned int Pociag::getIloscWagonow() const {
    return iloscWagonow;
}

void Pociag::setIloscWagonow(unsigned int iloscWagonow) {
    Pociag::iloscWagonow = iloscWagonow;
}

unsigned int Pociag::getIloscOsobNaWagon() const {
    return iloscOsobNaWagon;
}

void Pociag::setIloscOsobNaWagon(unsigned int iloscOsobNaWagon) {
    Pociag::iloscOsobNaWagon = iloscOsobNaWagon;
}

unsigned int Pociag::getPojemnosc() const {
    return pojemnosc;
}


int Pociag::getGodzinaOdjazdu() const {
    return godzinaOdjazdu;
}

void Pociag::setGodzinaOdjazdu(int godzinaOdjazdu) {
    Pociag::godzinaOdjazdu = godzinaOdjazdu;
}

int Pociag::getGodzinaPrzyjazdu() const {
    return godzinaPrzyjazdu;
}

void Pociag::setGodzinaPrzyjazdu(int godzinaPrzyjazdu) {
    Pociag::godzinaPrzyjazdu = godzinaPrzyjazdu;
}

void Pociag::setPrzyPeronie(bool czyPeron) {
    Pociag::czyPeron = czyPeron;

}

int Pociag::getIloscOsobWPociagu() {
    return (int)Pociag::pasazerowie.size();

}
