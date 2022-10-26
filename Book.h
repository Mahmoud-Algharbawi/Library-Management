/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#ifndef Book_h
#define Book_h
#include <iostream>
using namespace std;


class Book{

    public:

        Book();
        Book(string author, string title, int ISBN, int libraryID, float cost, char status);

        void setAuthor(string a);
        void setTitle(string t);
        void setISBN(int isbn);
        void setLibraryID(int id);
        void setCost(float c);
        void setStatus(char s);

        string getAuthor();
        string getTitle();
        int getISBN();
        int getLibraryID();
        float getCost();
        char getStatus();




    private:
    
        string author;
        string title;
        int ISBN;
        int libraryID;
        float cost;
        char status;//( O for out, L for lost, A for available)

};

#endif