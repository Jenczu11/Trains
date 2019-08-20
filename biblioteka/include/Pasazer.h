//
// Created by Bartłomiej Jencz on 30.12.2018.
//

#ifndef PROJECTTRAINS_PASAZER_H
#define PROJECTTRAINS_PASAZER_H

#include <string>
#include <vector>
#include <memory>
#include "Bilet.h"

class Pasazer  {
private:
    std::string imie;
    std::string nazwisko;
    std::string pesel;

protected:
    std::vector<std::shared_ptr<Bilet>> bilety;
public:
    Pasazer(const std::string &imie, const std::string &nazwisko, const std::string &pesel);
    virtual ~Pasazer();
    const std::string &getImie() const;
    const std::string &getNazwisko() const;
    std::string getPesel();
    std::string  getInfo();
    void dodajBilet(Bilet_ptr);
    void usunBilet(Bilet_ptr);
    int getLiczbaBiletow();

    friend class Pociag;


};

typedef std::shared_ptr<Pasazer> Pasazer_ptr;

#endif //PROJECTTRAINS_PASAZER_H
