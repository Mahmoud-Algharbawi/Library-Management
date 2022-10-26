/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#include "Books.h"

            
    void Books::AddBook()
        {
            string authorName, title;
            int id, isbn;
            float cost;
            char status;
                

            cout << "Enter author name: "; cin.ignore(); getline(cin,authorName);
            cout << "Enter Title: "; getline(cin,title);
            cout << "Enter ISBN: "; cin >> isbn;
            cout << "Enter Library ID: "; cin >> id;   
            cout << "Enter current cost "; cin >> cost;
            cout << "Enter current status:\nA - In\nO Out\nL - Lost\nEnter choice: "; cin >> status;

            Book *temp = new Book(authorName,title, isbn,id,cost, toupper(status));
                    

            BookList.push_back(temp);

            addCount();
        }

    void Books::EditBook()
        {
            string authorName,title;
            int id, isbn, choice;
            float cost;
            char status;

            cout << "Enter your search criterea:\n0 - search by Library ID\n1 - search by ISBN\nEnter your choice: ";
            cin >> choice;
                if (choice == 0)
                {
                    cout << "\nEnter ID: ";cin>>id;
                    SearchByID(id);
                }

                else {
                    cout << "\nEnter ISBN:"; cin >> isbn;
                    SearchByISBN(isbn);
                }

                    
            for (auto it = BookList.begin(); it!=BookList.end(); ++it)
            {
                if ((*it)->getLibraryID() == id || (*it)->getISBN() == isbn)
                {
                    cout << "Update author name: "; cin.ignore(); getline(cin,authorName); (*it)->setAuthor(authorName);
                    cout << "Update Title: "; getline(cin,title); (*it)->setTitle(title);
                    cout << "Update Library ID: "; cin >> id; (*it)->setLibraryID(id);
                    cout << "Update cost: "; cin >> cost; (*it)->setCost(cost);
                    cout << "Update status: "; cin >> status; (*it)->setStatus(status);
                }
                        
            }
        }

    void Books::DeleteBook()
        {
            int isbn,id, choice;
            cout << "Enter your search criterea:\n0 - search by Library ID\n1 - search by ISBN\nEnter your choice: ";
            cin >> choice;
                if (choice == 0)
                {
                    cout << "\nEnter ID: ";cin>>id;
                    SearchByID(id);
                }
                else {
                    cout << "\nEnter ISBN:"; cin >> isbn;
                    SearchByISBN(isbn);
                }

                    
            for (auto it = 0; it<=BookList.size(); ++it)
                {
                    if (BookList[it]->getLibraryID() == id || (BookList[it]->getISBN() == isbn))
                    {
                        cout << "Deleting...";
                        BookList.erase(BookList.begin()+it);
                    }
                }
         }

    Book* Books::SearchByID(int id)
        {
            bool found= false;
            for (auto it = BookList.begin(); it != BookList.end(); ++it)
            {
                if ((*it)->getLibraryID() == id)
                {
                    found = true;
                    cout << "Match found\n"; 
                    PrintOne((*it)->getLibraryID());
                    return (*it);
                }
            }
            if (!found)
            {
                cout << "\nNo match found\n";
            }
        }

    Book* Books::SearchByISBN(int isbn)
        {
            bool found=false;
            for (auto it = BookList.begin(); it != BookList.end(); ++it)
            {
                if ((*it)->getISBN() == isbn)
                    {
                        found = true;
                        cout << "Match found\n"; 
                        PrintOne((*it)->getLibraryID());
                        return (*it);
                    }
            }
            if (!found)
            {
                cout << "\nNo match found\n";
            }
        }
                

    void Books::PrintAll()
        {
            for (auto it = BookList.begin(); it != BookList.end(); it++)
            {
                cout << "Author: " << (*it)->getAuthor() << endl;
                cout << "Title: " << (*it)->getTitle() << endl;
                cout << "Library ID: " << (*it)->getLibraryID() << endl;
                cout << "Cost: " << (*it)->getCost() << endl;
                cout << "Status: " << (*it)->getStatus() << endl;

            }
        }

    void Books::PrintOne(int id)
        {
            for (auto it = BookList.begin(); it != BookList.end(); it++)
            {
                if ((*it)->getLibraryID() == id)
                {

                    cout << "Author: " << (*it)->getAuthor() << endl;
                    cout << "Title: " << (*it)->getTitle() << endl;
                    cout << "Library ID: " << (*it)->getLibraryID() << endl;
                    cout << "Cost: " << (*it)->getCost() << endl;
                    cout << "Status: " << (*it)->getStatus() << endl;
                }

            }
        }
   void Books::makeempty()
        {
            for (auto it = BookList.begin(); it != BookList.end(); it++)
            {
                BookList.erase((it));
            }
        }