#ifndef Patron_h
#define Patron_h
#include <iostream>
using namespace std;


class Patron {

    public:
             
        Patron();
        Patron(string name, int ID, float fines, int outBooks);
        void setName(string n);
        void setID(int id);
        void setFines(float f);
        void setOutBooks(int b);

        string getName();
        int getID();
        float getFines();
        int getOutBooks();



    private:
        
        string name;
        int ID;
        float fines;
        int outBooks;
};

#endif