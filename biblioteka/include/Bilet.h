//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#ifndef PROJECTTRAINS_BILET_H
#define PROJECTTRAINS_BILET_H

#include <string>
#include <memory>
#include <BiletType.h>
#include <klasa1.h>
#include <klasa2.h>
#include <klasa3.h>
//TODO: Cala klasa
class Bilet {
protected:
    std::string rodzajPociagu;
private:
    std::string dataWaznosci;
    unsigned int dlugoscTrasy;
    BiletType biletType;

public:
    Bilet(const std::string rodzajPociagu, const std::string &dataWaznosci, unsigned int);
    Bilet(const std::string rodzajPociagu, const std::string &dataWaznosci, unsigned int dlugoscTrasy, const BiletType &biletType);
    Bilet();
    virtual ~Bilet();
    std::string getBiletType();
    std::string getDataWaznosci();
    unsigned int getDlugoscTrasy();
    std::string getRodzajPociagu();
    void setBiletType(const BiletType &biletType);
    double cena();
    std::string biletInfo();

};
typedef std::shared_ptr<Bilet> Bilet_ptr;

#endif //PROJECTTRAINS_BILET_H
