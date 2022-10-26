/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#include "Loans.h"


    void Loans::CheckOut(Patrons* pats,Books* books)
    {
        int loanID,patronID,bookID;
        Patron* pat;
        Book* book;
        
        cout << "\nCreating new Loan\n";
        cout << "Enter the Patron ID you want to make the new loan for:"; cin >> patronID;
        pat = pats->SearchByID(patronID);

        if (pat != NULL && pat->getOutBooks() <= 5)
        {
            cout << "Enter new Loan ID: "; cin >> loanID;
            cout << "Enter book ID: "; cin >> bookID;
            Loan* temp = new Loan(loanID,bookID,false,patronID);
            LoanList.push_back(temp);
            pat->setOutBooks(pat->getOutBooks()+1);
            book = books->SearchByID(bookID);
            book->setStatus('O');
            addCount();
        }


    }

    void Loans::CheckIn(Patrons* pats,Books* books)
    {
        int bookID,loanID,patronID;
        Book* book;
    

        cout << "\nEnter loan ID: "; cin >> loanID;

        for (auto it= 0; it < LoanList.size(); ++it)
        {
            if (LoanList[it]->getLoanID() == loanID)
            {
                patronID =LoanList[it]->getPatronID();
                Patron* tempPat = pats->SearchByID(patronID);
                book = books->SearchByID(LoanList[it]->getBookID());
                if (tempPat->getFines()>0)
                {
                    cout << "\nPatron owes fines: " << tempPat->getFines() << endl;
                    break;
                }

                else{
                    tempPat->setOutBooks(tempPat->getOutBooks() -1);
                    book->setStatus('A');
                    LoanList.erase(LoanList.begin()+it);
                    decCount();
                }
            }
        }


    }

    //void Loans::ListOverdue()
    //{

    //}

    void Loans::ListBooks(Patrons* pats,Books* books)
    {
        int bookID,loanID,patronID;
        Patron* pat;
        cout << "\nEnter patron ID:";cin >> patronID;
        cout << "Patron info: \n"; pats->PrintOne(patronID);
        pat = pats->SearchByID(patronID);
        for (auto i= LoanList.begin(); i!= LoanList.end(); ++i)
        {
            if (patronID == (*i)->getPatronID())
            {
                bookID = (*i)->getBookID();
                Book* book= books->SearchByID(bookID);
                cout << "Loan Info: " << (*i)->getLoanID() <<endl;
                cout << "Book info: ";books->PrintOne(bookID);                  
            }
        }
    }

    /*void Loans::UpdateLoan(Patrons* pats,Books* books)
    {

    }

    void Loans::RecheckBook(Patrons* pats,Books* books)
    {

    }*/

    void Loans::ReportLost(Patrons* pats,Books* books)
    {
        int bookID,loanID,patronID;
        Patron* pat;
        Book* book;
        cout << "Enter Loan ID: "; cin >> loanID;
        for (auto it = LoanList.begin(); it != LoanList.end(); ++it)
        {
            if (loanID == (*it)->getLoanID())
            {
                patronID = (*it)->getPatronID();
                bookID = (*it)->getBookID();
                book = books->SearchByID(bookID);
                pat = pats->SearchByID(patronID);
                pat->setFines((pat->getFines()) + (book->getCost()));
                book->setStatus('L');
            }
        }
    
      
    }

    void Loans::PrintLoan(int id, Patrons* pats,Books* books)
    {
        for (auto it = LoanList.begin(); it != LoanList.end(); ++it)
        {
            if ((*it)->getLoanID() == id)
            {
                int bookID = (*it)->getBookID();
                int patronID = (*it)->getPatronID();
                cout << "Loan Info: " << (*it)->getLoanID() <<endl;
                cout << "Book info: ";books->PrintOne(bookID);
                cout << "Patron Info: ";pats->PrintOne(patronID);
            }
        }
    }


    void Loans::PrintAll(Patrons* pats,Books* books)
    {
        Patron* pat;
        Book* book;
        for (auto it = LoanList.begin(); it != LoanList.end(); ++it)
        {
            int bookID = (*it)->getBookID();
            int patronID = (*it)->getPatronID();
            cout << "Loan Info: " << (*it)->getLoanID() <<endl;
            cout << "Book info: ";books->PrintOne(bookID);
            cout << "Patron Info: ";pats->PrintOne(patronID);
        }
    }
   void Loans::makeempty()
        {
            for (auto it = LoanList.begin(); it != LoanList.end(); it++)
            {
                LoanList.erase((it));
            }
        }