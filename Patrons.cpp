/*Mahmoud Algharbawi
Homework 3
CSCE 1040 Sectoin 002*/
#include "Patrons.h"
#include <iostream>
using namespace std;

        Patrons::Patrons()
        {
            Count=0;
        }

        int Patrons::getCount()
        {
            return Count;
        }

        void Patrons::setCount(int c)
        {
            Count = c;
        }
        int Patrons::addCount() {Count++;}
        int Patrons::decCount() {Count--;}

        void Patrons::AddPatron()
        {
            string name;
            int id, outbooks;
            float fines;
           

            cout << "Enter patron name: "; cin.ignore(); getline(cin,name);
            cout << "Enter ID: "; cin >> id;

            Patron *temp = new Patron(name,id,0,0);
            cout << "Adding\n";
            PatronList.push_back(temp);
            //cout << "Adding\n";
            addCount();
        }

        void Patrons::EditPatron()
        {
            string n;
            int id, num;
            float fine;
            cout << "\nEnter ID: ";cin>>id;
                SearchByID(id);
            for (auto it = PatronList.begin(); it!=PatronList.end(); ++it)
            {
                if ((*it)->getID() == id)
                {
                    cout << "Update name: "; cin.ignore(); getline(cin,n); (*it)->setName(n);
                    cout << "Update ID: "; cin >> id; (*it)->setID(id);
                    cout << "Update fine balance: "; cin >> fine; (*it)->setFines(fine);
                    cout << "Update number of books borrowed: "; cin >> num; (*it)->setOutBooks(num);
                }
                
            }
        }

        void Patrons::DeletePatron()
        {
            int id;
            cout << "\nEnter ID: ";cin >> id;
            for (auto it = 0; it <PatronList.size(); ++it)
            {
                if (PatronList[it]->getID() == id)
                {
                    cout << "Deleting...\n";
                    PatronList.erase(PatronList.begin()+it);
                }
            }
            decCount();
        }

        Patron* Patrons::SearchByID(int id)
        {
            bool found;
            for (auto it = PatronList.begin(); it != PatronList.end(); ++it)
            {
                if ((*it)->getID() == id)
                {
                    found = true;
                    cout << "Match found\n"; 
                    //PrintOne((*it)->getID());
                    return (*it);
                }
            }
            if (!found)
            {
                cout << "\nNo match found.\n";
                return NULL;
            }
            
        }

        Patron* Patrons::SearchByName(string n)
        {
            bool found=false;            
            for (auto it = PatronList.begin(); it != PatronList.end(); ++it)
            {
                if ((*it)->getName() == n)
                {
                    found = true;
                    cout << "Match found\n";
                    //PrintOne((*it)->getID());
                    return (*it);
                }
                
            }
            if (!found)
            {
                cout << "\nNo match found.\n";
                return NULL;
            }
        }

        void Patrons::PayFines()
        {
            int id;
            cout << "\nEnter patron ID: "; cin >> id;
            for (auto it = PatronList.begin(); it!= PatronList.end(); ++it)
            {
                int payment, temp;
                if ((*it)->getID() == id)
                {
                    cout << "Fines: " << (*it)->getFines() << endl;
                    cout << "Enter payment amount: ";cin>>payment;
                    temp = (*it)->getFines() - payment;
                    (*it)->setFines(temp);
                }
            }
        }

        void Patrons::PrintAll()
        {
            for (auto it = PatronList.begin(); it != PatronList.end(); it++)
            {

                cout << "\nID: " << (*it)->getID() << endl;
                cout << "Name: " << (*it)->getName() << endl;
                cout << "Fines: " << (*it)->getFines() << endl;
                cout << "Number of books borrowed currently: " << (*it)->getOutBooks() << endl;

            }
        }
        void Patrons::PrintOne(int id)
        {
            
       
            for (auto it = PatronList.begin(); it != PatronList.end(); it++)
            {
                if ((*it)->getID() == id)
                {
                    cout << "\nID: " << (*it)->getID() << endl;
                    cout << "Name: " << (*it)->getName() << endl;
                    cout << "Fines: " << (*it)->getFines() << endl;
                    cout << "Number of books borrowed currently: " << (*it)->getOutBooks() << endl;
                }

            }
        }

        
        void Patrons::makeempty()
        {
            for (auto it = PatronList.begin(); it != PatronList.end(); it++)
            {
                PatronList.erase((it));
            }
        }