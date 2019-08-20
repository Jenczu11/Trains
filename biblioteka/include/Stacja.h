//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#ifndef PROJECTTRAINS_STACJA_H
#define PROJECTTRAINS_STACJA_H

#include <string>
#include <vector>
#include <memory>
#include "Pociag.h"

//class Pociag;
class Stacja {

private:
std::vector<std::shared_ptr<Pociag>> pociagi;
unsigned int pojemnoscStacji;
public:
    Stacja(unsigned int pojemnoscStacji);

    Stacja();

    ~Stacja();

    std::string informacja();
    std::string getPociagNazwa(int informacjaOKtorymPociagu);
    bool pociagWjechal(std::shared_ptr<Pociag> pociagWjezdza);
    int pobierzLiczbePociagow();
    bool pociagOdjezdza(std::shared_ptr<Pociag> pociagOdjezdzajacy);
    unsigned int getPojemnoscStacji() const;
    void setPojemnoscStacji(unsigned int pojemnoscStacji);
};

typedef std::shared_ptr<Stacja> Stacja_ptr;
#endif //PROJECTTRAINS_STACJA_H
