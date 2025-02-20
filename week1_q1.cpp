#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key) {
    int comparisons = 0; 
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            cout << "Total comparisons: " << comparisons << endl;
            return;
        }
    }
    // If element is not found
    cout << "Element not found" << endl;
    cout << "Total comparisons: " << comparisons << endl;
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;
    linearSearch(arr, n, key);

    return 0;
}
