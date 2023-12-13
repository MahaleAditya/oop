#include<iostream>
#include<exception>
#include<string.h>

using namespace std;

// Base class 'Publication'
class Publication
{
public:
    string title;
    float price;

    // Function to get data for a publication
    void getdata() 
    {
        cout << "Enter title: ";
        cin >> title;

        try {
            cout << "Enter price: ";
            cin >> price;

            // Check if price is less than or equal to 0, throw an exception
            if (price <= 0) 
                throw price;
        } catch (float a) {
            // Catch the exception and handle it by setting price to 0
            cout << "Invalid price ";
            price = 0;
        }        
    }

    // Function to display data for a publication
    void displaydata()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

// Derived class 'Book' inheriting from 'Publication'
class Book : public Publication 
{
private:
    int pageCount;

public:
    // Function to get data for a book
    void getdata()
    {
        try {
            // Call the base class function to get common publication data
            Publication::getdata(); 

            cout << "Enter page count: ";
            cin >> pageCount;

            // Check if page count is less than or equal to 0, throw an exception
            if (pageCount <= 0) 
                throw pageCount;
        } catch (int v) {
            // Catch the exception and handle it by setting pageCount to 0
            cout << "Invalid page count";
            pageCount = 0;
        }
    }

    // Function to display data for a book
    void displaydata() 
    {
        // Call the base class function to display common publication data
        Publication::displaydata(); 
        cout << "Page Count: " << pageCount << " pages" << endl;
    }
};

// Derived class 'Tape' inheriting from 'Publication'
class Tape : public Publication 
{
public:
    float playingTime;

    // Function to get data for a tape
    void getdata() 
    {
        try {
            // Call the base class function to get common publication data
            Publication::getdata(); 

            cout << "Enter playing time (in minutes): ";
            cin >> playingTime;

            // Check if playing time is less than or equal to 0, throw an exception
            if (playingTime <= 0) 
                throw playingTime;
        } catch (int e) {
            // Catch the exception and handle it by setting playingTime to 0
            cout << "Invalid playing time ";
            playingTime = 0;
        }
    }

    // Function to display data for a tape
    void displaydata() 
    {
        // Call the base class function to display common publication data
        Publication::displaydata(); 
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

// Main function
int main() 
{
    Book book[10];  // Array to store book objects
    Tape tape[10];  // Array to store tape objects
    int ch, b_count = 0, t_count = 0;
    
    do {
        cout << "\nPublication Data:";
        cout << "\nMenu:";
        cout << "\n1. Add Information to Books";
        cout << "\n2. Add Information to Tapes";
        cout << "\n3. Display Books Information";
        cout << "\n4. Display Tapes Information";
        cout << "\n5. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> ch;

        switch(ch) {
            case 1:
                book[b_count].getdata();  // Get data for a book
                b_count++;
                break;
            case 2:
                tape[t_count].getdata();  // Get data for a tape
                t_count++;
                break;
            case 3:
                cout << "\nBook Information";
                for (int i = 0; i < b_count; i++) {
                    book[i].displaydata();  // Display data for each book
                }
                break;
            case 4:
                cout << "\nTape Information";
                for (int i = 0; i < t_count; i++) {
                    tape[i].displaydata();  // Display data for each tape
                }
                break;
            case 5:
                exit(0);  // Exit the program
        }
    } while (ch != 5);

    return 0;
}
