//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#ifndef PROJECTTRAINS_POCIAG_H
#define PROJECTTRAINS_POCIAG_H

#include<string>
#include<vector>
#include<memory>
#include "Pasazer.h"
#include "Bilet.h"
#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

class Pociag {
protected:
    unsigned int iloscWagonow;
    unsigned int iloscOsobNaWagon;
    unsigned int pojemnosc;
    int godzinaOdjazdu;
    int godzinaPrzyjazdu;
    std::string rodzajPociagu;
    bool czyPeron;
    boost::uuids::uuid UUID;
protected:
    std::vector <Pasazer_ptr> pasazerowie;
public:
    Pociag(unsigned int IloscWagonow, unsigned int IloscOsobNaWagon);
    Pociag();
    virtual ~Pociag(){}
    bool przyPeronie();
    unsigned int getPojemnosc() const;
    std::string getRodzajPociagu();
    virtual std::string toString()=0;
    void setGodzinaPrzyjazdu(int godzinaPrzyjazdu);
    void setIloscOsobNaWagon(unsigned int iloscOsobNaWagon);
    unsigned int getIloscWagonow() const;
    void setPrzyPeronie(bool);
    unsigned int getIloscOsobNaWagon() const;
    void setIloscWagonow(unsigned int iloscWagonow);

    void setGodzinaOdjazdu(int godzinaOdjazdu);

    int getGodzinaPrzyjazdu() const;

    int getGodzinaOdjazdu() const;

    bool pasazerWsiada(Pasazer_ptr);

    bool pasazerWysiada(Pasazer_ptr);

    int getIloscOsobWPociagu();



};

typedef std::shared_ptr<Pociag> Pociag_ptr;


#endif //PROJECTTRAINS_POCIAG_H
