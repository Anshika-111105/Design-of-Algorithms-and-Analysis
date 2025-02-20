#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    comparisons = 0;
    swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }
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
        
        int comparisons = 0, swaps = 0;
        selectionSort(arr, comparisons, swaps);
        
        for (int num : arr) {
            cout << num << " ";
        }
        cout << "\n";
        cout <<"Comparsion = "<< comparisons << "\n";
        cout <<"Swaps = "<<swaps << "\n";
    }
    return 0;
}