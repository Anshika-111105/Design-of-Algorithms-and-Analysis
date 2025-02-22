#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findPairWithSum(int n, vector<int>& arr, int key) {
    sort(arr.begin(), arr.end()); // O(n log n)
    
    int left = 0, right = n - 1;
    while (left < right) {
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
    cin >> T; 
    while (T--) {
        int n;
        cin >> n; 
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }  
        int key;
        cin >> key;
        
        findPairWithSum(n, arr, key);
    }
    return 0;
}
