#include<iostream>
#include<fstream>
using namespace std;

// Class 'student' to represent student information
class student {
public:
    int roll;
    char name[20];
    char std[10];

    // Function to get data for a student
    void getdata() {
        cout << "Enter the name of student: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter standard: ";
        cin >> std;
    }

    // Function to display student information
    void display() {
        cout << "Name of student: " << name;
        cout << "\nRoll no. of student: " << roll;
        cout << "\nStandard: " << std << endl;
        cout << "\n\n";
    }
};

int main() {
    int n, num, pos;
    student s1;
    cout << "\nEnter total number of student entries: ";
    cin >> n;

    // Writing student information to a file named "a"
    ofstream out("a");

    for (int i = 0; i < n; i++) {
        s1.getdata();
        out.write((char*)&s1, sizeof(s1));
    }
    out.close();

    // Reading and displaying student information from the file "a"
    ifstream in("a");
    for (int i = 0; i < n; i++) {
        in.read((char*)&s1, sizeof(s1));
        s1.display();
    }
    in.close();

    // Searching for a specific student by position in the file
    ifstream fin("a");

    cout << "\n\n\nEnter the number of student you want to search: ";
    cin >> num;

    pos = (num - 1) * sizeof(s1);
    fin.seekg(pos);
    fin.read((char*)&s1, sizeof(s1));

    // Displaying the information of the searched student
    s1.display();

    fin.close();
}
