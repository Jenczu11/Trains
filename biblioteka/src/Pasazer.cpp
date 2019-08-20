//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#include <Pasazer.h>
#include <sstream>
#include "Pasazer.h"
#include <iostream>
#include <fstream>
using namespace std;

const std::string &Pasazer::getImie() const {
    return imie;
}

const std::string &Pasazer::getNazwisko() const {
    return nazwisko;
}

Pasazer::Pasazer(const std::string &imie, const std::string &nazwisko, const std::string &pesel) :
imie(imie),
nazwisko(nazwisko),
pesel(pesel) {}

Pasazer::~Pasazer() {

}

std::string Pasazer::getInfo() {
    stringstream ss;
    ss<<"PASAZER"<<std::endl<<
    "GODNOSC: "<<imie<<" "<<nazwisko<<endl<<
    "PESEL: "<<pesel<<endl<<
    "BILETY: "<<endl;
    for(int i=0; i<bilety.size(); i++)
    {
        ss<<bilety[i]->biletInfo();
    }
    return ss.str();
}

std::string Pasazer::getPesel() {
    return pesel;
}

void Pasazer::dodajBilet(Bilet_ptr nowybilet) {
        bilety.push_back(nowybilet);
}

void Pasazer::usunBilet(Bilet_ptr starybilet) {
    if(getLiczbaBiletow()!=0)
    {
        for(int i=0; i<bilety.size(); i++)
        {
            if(starybilet=bilety[i])
            {
                bilety.erase(bilety.begin()+i);

            }
        }
    }
}

int Pasazer::getLiczbaBiletow() {
    int ile=0;
    for(int i=0; i<bilety.size(); i++)
    {
        ile++;
    }
    return ile;
}
