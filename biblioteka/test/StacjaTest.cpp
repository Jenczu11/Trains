//
// Created by Bartłomiej Jencz on 11.01.2019.
//
#include <boost/test/unit_test.hpp>
#include "Pociag.h"
#include "Pospieszny.h"
#include "Osobowy.h"
#include "Stacja.h"
#include<string>
#include<iostream>


BOOST_AUTO_TEST_SUITE(TestyStacji)

    BOOST_AUTO_TEST_CASE(TworzenieStacji){
        auto s1 = std::make_shared<Stacja>(3);
        BOOST_CHECK_EQUAL(s1->pobierzLiczbePociagow(),0);
        BOOST_TEST_MESSAGE(s1->informacja());
    }

    BOOST_AUTO_TEST_CASE(DodaniePociagow){
        auto s1 = std::make_shared<Stacja>(3);
        BOOST_CHECK_EQUAL(s1->pobierzLiczbePociagow(),0);
        BOOST_TEST_MESSAGE(s1->informacja());
        Pospieszny_ptr p1=std::make_shared<Pospieszny>(1,1,1);
        Pospieszny_ptr p2=std::make_shared<Pospieszny>(2,2,2);
        Osobowy_ptr o1=std::make_shared<Osobowy>(3,3,3);
        BOOST_CHECK_EQUAL(s1->pociagWjechal(p1),1);
        BOOST_CHECK_EQUAL(s1->pociagWjechal(p2),1);
        BOOST_CHECK_EQUAL(s1->pociagWjechal(o1),1); // Inny rodzaj testu
        BOOST_CHECK_EQUAL(s1->pobierzLiczbePociagow(),3);
        BOOST_TEST_MESSAGE(s1->informacja());
}

    BOOST_AUTO_TEST_CASE(UsuwaniePociagow){
        auto s1 = std::make_shared<Stacja>(3);
        Pospieszny_ptr p1=std::make_shared<Pospieszny>(1,1,1);
        Pospieszny_ptr p2=std::make_shared<Pospieszny>(2,2,2);
        Osobowy_ptr o1=std::make_shared<Osobowy>(3,3,3);
        s1->pociagWjechal(p1);
        s1->pociagWjechal(p2);
        s1->pociagWjechal(o1);
        BOOST_CHECK_EQUAL(s1->pobierzLiczbePociagow(),3);
        BOOST_CHECK_EQUAL(s1->pociagOdjezdza(p2),1);
        BOOST_CHECK_EQUAL(s1->pobierzLiczbePociagow(),2);
        BOOST_TEST_MESSAGE(s1->informacja());
    }
    BOOST_AUTO_TEST_CASE(TestInformacjaPociag){
        auto s1 = std::make_shared<Stacja>(1);
        Pospieszny_ptr p1=std::make_shared<Pospieszny>(1,1,1);
        s1->pociagWjechal(p1);
        BOOST_TEST_MESSAGE(s1->getPociagNazwa(0));
        BOOST_CHECK_THROW(s1->getPociagNazwa(1),std::invalid_argument);
    }


BOOST_AUTO_TEST_SUITE_END()
