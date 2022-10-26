/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#ifndef Loans_h
#define Loans_h
#include <iostream>
#include <vector>
#include "Loan.h"
#include "Patron.h"
#include "Patrons.h"
#include "Book.h"
#include "Books.h"
using namespace std;



class Loans{
    
    public:
        Loans() {Count=0;}
        void addCount() {Count++;}
        void decCount() {Count--;}
        void CheckOut(Patrons* pats,Books* books);
        void CheckIn(Patrons* pats,Books* books);
        void ListOverdue(Patrons* pats,Books* books);
        void ListBooks(Patrons* pats,Books* books);
        void UpdateLoan(Patrons* pats,Books* books);
        void RecheckBook(Patrons* pats,Books* books);
        void ReportLost(Patrons* pats,Books* books);
        void PrintLoan(int id,Patrons* pats,Books* books);
        void PrintAll(Patrons* pats,Books* books);
        void makeempty();



    private:
        int Count;
        vector<Loan*> LoanList;



};

#endif

