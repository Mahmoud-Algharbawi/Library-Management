/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#include "Book.h"


        Book::Book()
        {
            author = " ";
            title = " ";
            ISBN = 0;
            libraryID = 0;
            cost =0;
            status = ' ';
        }

        Book::Book(string author, string title, int ISBN, int libraryID, float cost, char status)
        {
            this->author = author;
            this->title = title;
            this->ISBN = ISBN;
            this->libraryID = libraryID;
            this->cost = cost;
            this->status = status;
        }

        void Book::setAuthor(string a)
        {
            author = a;
        }

        void Book::setTitle(string t)
        {
            title = t;
        }

        void Book::setISBN(int isbn)
        {
            ISBN = isbn;
        }

        void Book::setLibraryID(int id)
        {
            libraryID = id;
        }

        void Book::setCost(float c)
        {
            cost = c;
        }

        void Book::setStatus(char s)
        {
            status = s;
        }

        string Book::getAuthor()
        {
            return author;
        }

        string Book::getTitle()
        {
            return title;
        }

        int Book::getISBN()
        {
            return ISBN;
        }

        int Book::getLibraryID()
        {
            return libraryID;
        }

        float Book::getCost()
        {
            return cost;
        }

        char Book::getStatus()
        {
            return status;
        }