/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#ifndef Patrons_h
#define Patrons_h
#include "Patron.h"
#include <vector>
#include <iostream>
using namespace std;


class Patrons {


    public:

        Patrons();
        int getCount();
        void setCount(int c);
        int addCount();
        int decCount();


        void AddPatron();
        void EditPatron();
        void DeletePatron();
        Patron* SearchByID(int id);
        Patron* SearchByName(string n);
        void PayFines();
        void PrintAll();
        void PrintOne(int id);
        void makeempty();
        
        

        

    private:

        int Count;
        vector<Patron*> PatronList;
};

#endif