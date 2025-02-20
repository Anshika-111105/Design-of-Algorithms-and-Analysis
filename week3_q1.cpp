#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int& comparisons, int& shifts) {
    int n = arr.size();
    comparisons = 0;
    shifts = 0;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j]; 
            shifts++;
            j--;
        }
        if (j >= 0) comparisons++; 
        
        arr[j + 1] = key;
        shifts++; // Placing key in its correct position
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int comparisons = 0, shifts = 0;
        insertionSort(arr, comparisons, shifts);
        
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
        cout << "Comparsion = "<< comparisons << endl;
        cout << "Shifts = "<<shifts << endl;
    }
    
    return 0;
}
