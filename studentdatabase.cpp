#include<iostream>
#include<string.h>
using namespace std;

class student {
public:
    int roll;
    char name[10];
    char div[10];
    char Class[10];
    char dob[10];
    char bg[10];
    char contactadd[20];
    char tele[10];
    char dl[10];
    static int count;  // Static member variable to keep track of the number of students

    // Default constructor with default values
    student() {
        roll = 123;
        strcpy(name, "ABC");
        strcpy(div, "div");
        strcpy(Class, "3");
        strcpy(dob, "11/03/2005");
        strcpy(bg, "A");
        strcpy(contactadd, "Sangamner");
        strcpy(tele, "12345678");
        strcpy(dl, "68646856438");
        count++;
    }

    // Copy constructor
    student(student &s) {
        roll = s.roll;
        strcpy(name, s.name);
        strcpy(div, s.div);
        strcpy(Class, s.Class);
        strcpy(dob, s.dob);
        strcpy(bg, s.bg);
        strcpy(contactadd, s.contactadd);
        strcpy(tele, s.tele);
        strcpy(dl, s.dl);
        count++;
    }

    // Friend function to display student details
    friend void display(student *s);

    // Member function to get data from the user
    void getdata() {
        cout << "\nEnter your Roll no " << "\nName " << "\ndiv " << "\nClass " << "\nDOB " << "\nBG " << "\nContactaddress " << "\nTelephone " << "\nDrivl";
        cin >> roll >> name >> Class >> dob >> bg >> contactadd >> tele >> dl;
        count++;
    }

    // Static member function to show the count of students
    static int countshow() {
        cout << "\nNo. of students " << count;
    }
};

// Initialize static member variable count
int student::count = 0;

// Friend function to display student details
void display(student *s) {
    cout << s->roll << endl << s->name << endl << s->Class << endl << s->dob << endl << s->contactadd << endl << s->tele << endl << s->dl;
}

int main() {
    // Create two student objects, s1 and s2, using the default constructor and copy constructor
    student s1, s2(s1);

    int n, i;

    cout << "Enter number of students";
    cin >> n;

    // Create an array of pointers to student objects dynamically
    student *p[n];
    for (i = 0; i < n; i++) {
        p[i] = new student;
        p[i]->getdata();
    }

    // Display details for s1 and s2
    display(&s1);
    display(&s2);

    // Display details for each dynamically created student object
    for (i = 0; i < n; i++) {
        display(p[i]);
    }

    // Show the count of students using the static member function
    student::countshow();

    // Deallocate memory for dynamically created student objects
    for (i = 0; i < n; i++) {
        delete p[i];
    }

    return 0;
}
