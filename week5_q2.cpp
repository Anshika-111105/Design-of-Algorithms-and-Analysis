#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findPairWithSum(vector<int>& arr, int key) {
    sort(arr.begin(), arr.end()); // O(n log n)
    int left = 0, right = arr.size() - 1;
    
    while (left < right) { // O(n)
        int sum = arr[left] + arr[right];
        if (sum == key) {
            cout << arr[left] << " " << arr[right] << endl;
            return;
        } else if (sum < key) {
            left++;
        } else {
            right--;
        }
    }
    cout << "No Such Elements Exist" << endl;
}

int main() {
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int n;
        cin >> n; // Size of array
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // Array elements
        }
        int key;
        cin >> key; // Target sum
        findPairWithSum(arr, key);
    }
    return 0;
}
