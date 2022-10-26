/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#include "Loan.h"

        Loan::Loan()
        {
            loanID=0;
            bookID=0;
            patronID=0;
            status = false;
            //time = 1;
        }

        Loan::Loan(int loanID, int bookID, bool status, int patronID)// time_t time)
        {
            this->loanID = loanID;
            this->bookID = bookID;
            this->status = status;
            this->patronID=patronID;
            //this->time = time;
        }

        void Loan::setLoanID(int id)
        {
            loanID = id;
        }

        void Loan::setBookID(int bookid)
        {
            bookID = bookid;
        }

        void Loan::setStatus(bool stat)
        {
            status = stat;
        }

        void Loan::setPatronID(int id)
        {
            patronID=id;
        }

       /* void Loan::setTime(time_t now)
        {
            time = now;
        }*/

        int Loan::getLoanID()
        {
            return loanID;
        }

        int Loan::getBookID()
        {
            return bookID;
        }

        int Loan::getPatronID()
        {
            return patronID;
        }

        bool Loan::getStatus()
        {
            return status;
        }


      /*  time_t Loan::getTime()
        {
            return time;
        }*/