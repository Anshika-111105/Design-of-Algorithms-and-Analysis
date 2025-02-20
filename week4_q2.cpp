#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

long long comparisons = 0, swaps = 0;

void swapElements(int &a, int &b) {
    swaps++;
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swapElements(arr[randomIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swapElements(arr[i], arr[j]);
        }
    }
    swapElements(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        
        comparisons = 0;
        swaps = 0;
        quickSort(arr, 0, n - 1);
        
        for (int num : arr) cout << num << " ";
        cout << "\n";
        cout << "Comparsion = "<<comparisons << "\n";
        cout << "Swaps = "<<swaps << "\n";
    }
    return 0;
}
