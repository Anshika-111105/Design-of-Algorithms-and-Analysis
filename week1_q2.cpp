#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binarySearch(vector<int> &arr, int key, int &comparisons) {
    int left = 0, right = arr.size()-1;
    while (left <= right){
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == key)
            return mid; // Element found
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1; // Element not found
}
int main(){
    int n, key, comparisons = 0;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the key to search: ";
    cin >> key;
    // Sorting the array (O(n log n))
    sort(arr.begin(), arr.end());
    int index = binarySearch(arr, key, comparisons);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
    cout << "Total comparisons: " << comparisons << endl;
    return 0;}
