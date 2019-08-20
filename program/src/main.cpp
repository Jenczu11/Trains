#include <iostream>
#include <string>
#include <Pociag.h>
#include <Stacja.h>
#include <memory>
#include <vector>
#include <Pospieszny.h>
#include <fstream>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    auto s1 = std::make_shared<Stacja>();
    Pospieszny_ptr p1 = std::make_shared<Pospieszny>(1, 1, 1);
    s1->pociagWjechal(p1);
    cout << s1->pobierzLiczbePociagow();
    try {
        s1->getPociagNazwa(1);
    }
    catch (std::string w) {
        cout << w;
    }

    Pospieszny_ptr p2 = std::make_shared<Pospieszny>(3, 50, 40);
    Bilet_ptr bilet1 = std::make_shared<Bilet>("Pospieszny", "11.01.2019", 120, Klasa1());
    Pasazer_ptr pas1 = std::make_shared<Pasazer>("Jan", "Kowalski", "7932418");
    pas1->dodajBilet(bilet1);
    p2->pasazerWsiada(pas1);
    cout<<p2->toString();
    p2->pasazerWysiada(pas1);
    cout<<p2->toString();

    return 0;
}