
/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#ifndef Books_h
#define Books_h

#include "Book.h"
#include <iostream>
#include <vector>
using namespace std;

    class Books{
            
            public:
                Books() {count=0;}
                void addCount() {count++;}
                void decCount() {count--;}
                Book* SearchByID(int id);
                Book* SearchByISBN(int isbn);
                void AddBook();
                void EditBook();
                void DeleteBook();
                void PrintAll();
                void PrintOne(int id);
                void makeempty();

            private:
                int count;
                vector<Book*> BookList;
                

    };

#endif