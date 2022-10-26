/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#include "Patron.h"
#include "Patrons.h"
#include "Book.h"
#include "Books.h"
#include "Loan.h"
#include "Loans.h"
Patrons* myPatrons= new Patrons;
Books* myBooks= new Books;
Loans* myLoans= new Loans;


int main()
{
    int choice=-1;
    int subchoice = -1;
    string n;
    int id, isbn;
    

    while (choice!=0)
    {
            cout << "\nChoose from the following menu:\n";
            cout << "0 - Quit\n";
            cout << "1 - Patron options\n";
            cout << "2 - Book options\n";
            cout << "3 - Loan options\n";
        
            cout << "Enter choice: ";cin >> choice;

        switch (choice)
        {
            case 0: cout << "\nQuitting...\n"; exit(1); break;

            case 1: 
                cout << "\nWhat would you like to do to Patrons?\n";
                cout << "0 - Back to main menu\n";
                cout << "1 - Add Patron\n";
                cout << "2 - Edit Patron Information\n";
                cout << "3 - Delete Patron\n";
                cout << "4 - Search for Patron by ID\n";
                cout << "5 - Search for Patron by name\n";
                cout << "6 - Pay fines for Patron\n";
                cout << "7 - Print all Patrons list\n";
                cout << "8 - Print info for one Patron\n";
                

                cout << "\nEnter choice: ";cin >> subchoice;
                    switch (subchoice)
                    {
                        case 1: myPatrons->AddPatron();break;
                        case 2: myPatrons->EditPatron();break;
                        case 3: myPatrons->DeletePatron();break;
                        case 4: cout << "\nEnter ID: ";cin >> id; myPatrons->SearchByID(id); break;
                        case 5: cout << "\nEnter name: "; cin.ignore(); getline(cin,n);myPatrons->SearchByName(n);break;
                        case 6: myPatrons->PayFines();break;
                        case 7: myPatrons->PrintAll();break;
                        case 8: cout << "Enter the ID number of the patron you want to print the info for: "; cin >> id;myPatrons->PrintOne(id);break;
                        default: break;
                    }
            break;
            
            case 2:
                cout << "\nWhat would you like to do to Books?\n";
                cout << "0 - Back to main menu\n";
                cout << "1 - Add Book\n";
                cout << "2 - Edit Book Information\n";
                cout << "3 - Delete Book\n";
                cout << "4 - Search for Book by Library ID\n";
                cout << "5 - Search for Book by ISBN\n";
                cout << "6 - Print all Book list\n";
                cout << "7 - Print info for one Book\n";
                
                cout << "\nEnter choice: ";cin >> subchoice;
                    switch (subchoice)
                    {
                        case 1: myBooks->AddBook();break;
                        case 2: myBooks->EditBook();break;
                        case 3: myBooks->DeleteBook();break;
                        case 4: cout << "\nEnter ID: ";cin >> id; myBooks->SearchByID(id); break;
                        case 5: cout << "\nEnter ISBN: "; cin >> isbn; myBooks->SearchByISBN(isbn);break;
                        case 6: myBooks->PrintAll();break;
                        case 7: cout << "\nEnter ID: ";cin >> id; myBooks->PrintOne(id);break;
                        default: break;
                    }
            break;

            case 3:
                cout << "\nWhat would you like to do to Loans?\n";
                cout << "0 - Back to main menu\n";
                cout << "1 - Add a loan\n";
                cout << "2 - Return a book\n";
                cout << "3 - Report a lost book\n";
                cout << "4 - Print all loan\n";
                cout << "5 - Print one loan\n";

                
                cout << "\nEnter choice: ";cin >> subchoice;
                    switch (subchoice)
                    {
                        case 1: myLoans->CheckOut(myPatrons,myBooks);break;
                        case 2: myLoans->CheckIn(myPatrons,myBooks);break;
                        case 3: myLoans->ReportLost(myPatrons,myBooks);break;
                        case 4: myLoans->PrintAll(myPatrons,myBooks);break;
                        case 5: cout << "Enter Loan ID: "; cin >> id; myLoans->PrintLoan(id,myPatrons,myBooks);break;
                        default: break;
                    }


                
            break;

            default: 
                cout << "\nWrong choice, please enter again.\n "; break;
        }
    }








myPatrons->makeempty();
myLoans->makeempty();
myBooks->makeempty();

    delete myBooks;
    delete myLoans;
    delete myPatrons;
    
    return 0;
}