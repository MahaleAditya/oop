#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, p;
    string s, key;

    map<string, int> state;  // Declare a map to store state names and populations

    cout << "\nHow many state names do you want to add: ";
    cin >> n;

    // Loop to input state names and populations
    for (int i = 0; i < n; i++) {
        cout << "\nEnter the name of state: ";
        cin >> s;

        cout << "Enter the population: ";
        cin >> p;

        // Insert the state name and population into the map
        state.insert(make_pair(s, p));
    }

    cout << "\nEnter the state you want to search: ";
    cin >> key;

    cout << "State population:" << endl;

    // Loop to search for the specified state and display its population
    for (auto itr = state.begin(); itr != state.end(); itr++) {
        if (itr->first == key) {
            cout << itr->first << " " << itr->second << endl;
        }
    }

    return 0;
}
