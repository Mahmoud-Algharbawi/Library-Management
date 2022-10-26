
#include "Patron.h"



        Patron::Patron()
        {
            name = " ";
            ID = 0;
            fines = 0;
            outBooks = 0;
        }

        Patron::Patron(string name, int ID, float fines, int outBooks)
        {
            this->name = name;
            this->ID = ID;
            this->fines = fines;
            this->outBooks = outBooks;
        }

        void Patron::setName(string n)
        {
            name =n;
        }

        void Patron::setID(int id)
        {
            ID = id;
        }

        void Patron::setFines(float f)
        {
            fines = f;
        }

        void Patron::setOutBooks(int b)
        {
            outBooks = b;
        }

        string Patron::getName()
        {
            return name;
        }

        int Patron::getID()
        {
            return ID;
        }

        float Patron::getFines()
        {
            return fines;
        }

        int Patron::getOutBooks()
        {
            return outBooks;
        }