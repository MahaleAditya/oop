#include<iostream>
using namespace std;

// Template function for bubble sort
template <class T1>
void bubblesort(T1 a[10], int s) {
    int i, j;
    T1 temp;
    
    // Outer loop for passes
    for (i = 0; i < s - 1; i++) {
        // Inner loop for comparisons
        for (j = 0; j == s - i - 1; j++) {
            // Swap if the element at current position is greater than the next element
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "\n Sorted Array by bubble sort : " << endl;

    // Display the sorted array
    for (i = 0; i < s; i++) {
        cout << " " << a[i];
    }
}

// Template function for selection sort
template <class T2>
void selectionsort(T2 a[10], int s) {
    int i, j, min;
    T2 temp;

    // Outer loop for passes
    for (i = 0; i < s - 1; i++) {
        min = i;
        
        // Inner loop for finding the minimum element
        for (j = i + 1; j < s; j++) {
            if (a[min] > a[j])
                min = j;
        }

        // Swap the minimum element with the current element
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    cout << "\n Sorted Array by Selection sort : " << endl;

    // Display the sorted array
    for (i = 0; i < s; i++) {
        cout << " " << a[i];
    }
}

int main() {
    int x[10], n, ch;

    // Input size and elements for the integer array
    cout << "Enter the size of the integer array: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    float y[10], m;

    // Input size and elements for the float array
    cout << "Enter the size of the float array: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }

    cout << "Enter your choice \n 1.Selection sort \n 2.Bubble sort\n";
    cin >> ch;

    // Switch statement to choose the sorting algorithm based on user input
    switch (ch) {
        case 1:
            selectionsort(x, n);  // Call selection sort for integer array
            selectionsort(y, m);  // Call selection sort for float array
            break;

        case 2:
            bubblesort(x, n);  // Call bubble sort for integer array
            bubblesort(y, m);  // Call bubble sort for float array
            break;
    }

    return 0;
}
