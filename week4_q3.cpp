#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}
int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k) {
            return arr[pivotIndex];
        } else if (pivotIndex > k) {
            return quickSelect(arr, low, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, high, k);
        }
    }
    return INT_MIN; // If K is out of range
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
        int K;
        cin >> K;    
        if (K > 0 && K <= n) {
            int kthElement = quickSelect(arr, 0, n - 1, K - 1);
            cout << kthElement << "\n";
        } else {
            cout << "not present\n";
        }
    }
    return 0;
}
