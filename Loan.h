/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#ifndef Loan_h
#define Loan_h
#include <iostream>
#include <ctime>
using namespace std;


class Loan {
    
    public:

        Loan();
        Loan(int loanID, int bookID, bool status, int patronID);// time_t time);

        void setLoanID(int id);
        void setBookID(int bookid);
        void setStatus(bool stat);
        void setPatronID(int id);
       // void setTime(time_t now); 

        int getLoanID();
        int getBookID();
        int setPatronID();
        bool getStatus();
        int getPatronID();
        ///time_t getTime();

        //TODO: time in C++

    private:

        int loanID;
        int bookID;
        int patronID;
        bool status;//true = overdue 
       // time_t time;


};

#endif