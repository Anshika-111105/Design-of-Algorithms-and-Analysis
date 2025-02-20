/*Counting Sort is a non-comparison-based sorting algorithm that works efficiently when the range of numbers is known and relatively small. 
It has a time complexity of O(n + k), where n is the number of elements and k is the range of input values.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform Counting Sort
void countSort(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return; // Edge case: Empty array

    // Step 1: Find the maximum element in the array
    int maxElement = *(max_element(arr.begin(), arr.end()));

    // Step 2: Create a count array of size (maxElement + 1) initialized to 0
    vector<int> count(maxElement + 1, 0);

    // Step 3: Store the frequency of each element
    for (int num : arr) {
        count[num]++;
    }

    // Step 4: Modify the count array to store cumulative sum
    for (int i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build the output sorted array
    vector<int> sortedArr(n);
    for (int i = n - 1; i >= 0; i--) {
        sortedArr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: Copy sorted elements back to the original array
    arr = sortedArr;
}

// Driver function
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (nonnegative integers only): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform Counting Sort
    countSort(arr);

    // Output the sorted array
    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
