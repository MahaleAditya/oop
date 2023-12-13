#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent personal records
struct PersonalRecord {
    string name;
    string dob;
    string phoneNumber;
};

// Function to display a personal record
void displayRecord(const PersonalRecord& record) {
    cout << "Name: " << record.name << "\tDOB: " << record.dob << "\tPhone Number: " << record.phoneNumber << endl;
}

// Function to compare personal records for sorting
bool compareRecords(const PersonalRecord& record1, const PersonalRecord& record2) {
    return record1.name < record2.name;
}

int main() {
    vector<PersonalRecord> records; // Vector to store personal records

    char addMore;
    do {
        PersonalRecord newRecord;

        // Input for a new personal record
        cout << "Enter Name: ";
        getline(cin, newRecord.name);

        cout << "Enter Date of Birth (DD-MM-YYYY): ";
        getline(cin, newRecord.dob);

        cout << "Enter Phone Number: ";
        getline(cin, newRecord.phoneNumber);

        records.push_back(newRecord); // Add the new record to the vector

        cout << "Do you want to add another record? (y/n): ";
        cin >> addMore;
        cin.ignore(); // Ignore the newline character in the buffer
    } while (addMore == 'y' || addMore == 'Y');

    cout << "\nUnsorted Records:\n";
    for (const auto& record : records) {
        displayRecord(record); // Display unsorted records
    }

    sort(records.begin(), records.end(), compareRecords); // Sort records based on names

    cout << "\nSorted Records:\n";
    for (const auto& record : records) {
        displayRecord(record); // Display sorted records
    }

    string searchName;
    cout << "\nEnter a name to search: ";
    getline(cin, searchName);

    // Binary search for the entered name in the sorted records
    auto it = lower_bound(records.begin(), records.end(), PersonalRecord{searchName, "", ""}, compareRecords);

    if (it != records.end() && it->name == searchName) {
        cout << "Record found:\n";
        displayRecord(*it); // Display the found record
    } else {
        cout << "Record not found.\n";
    }

    return 0;
}
