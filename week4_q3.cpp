#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthSmallestUsingCountSort(vector<int>& arr, int K) {
    // Find the maximum element to define the range
    int maxElement = *max_element(arr.begin(), arr.end());

    // Create and initialize the count array
    vector<int> count(maxElement + 1, 0);

    // Fill the count array with frequency of elements
    for (int num : arr) {
        count[num]++;
    }

    // Find the Kth smallest element
    int countSum = 0;
    for (int i = 0; i <= maxElement; i++) {
        countSum += count[i];
        if (countSum >= K) {
            return i;
        }
    }

    return -1; // If K is out of bounds
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) cin >> arr[i];

        int K;
        cin >> K;    

        if (K > 0 && K <= n) {
            cout << kthSmallestUsingCountSort(arr, K) << "\n";
        } else {
            cout << "K is out of bounds\n";
        }
    }
    return 0;
}
