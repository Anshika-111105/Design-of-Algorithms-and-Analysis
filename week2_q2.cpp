#include <iostream>
#include <vector>
using namespace std;
void findIndices(vector<int>& arr, int n) {
    for (int k = 2; k < n; k++) { // Start from third element
        int i = 0, j = k - 1; // Two pointers approach
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == arr[k]) {
                cout << "Indices: " << i << " " << j << " " << k << endl;
                return;
            } else if (sum < arr[k]) {
                i++; // Move left pointer forward
            } else {
                j--; // Move right pointer backward
            }
        }
    }
    cout << "No such indices found." << endl;
}
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    findIndices(arr, n);
    return 0;
}
