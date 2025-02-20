#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int jumpSearch(vector<int> &arr, int key, int &comparisons) {
    int n = arr.size();
    int step = sqrt(n); // Block size
    int prev = 0;
    while (arr[min(step, n) - 1] < key) {
        comparisons++; 
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    while (arr[prev] < key) {
        comparisons++;
        prev++;
        if (prev == min(step, n)) return -1; 
    }
    comparisons++;
    if (arr[prev] == key) return prev;
    return -1;}
int main() {
    int T;
    cin >> T; 
    while (T--) {
        int n, key, comparisons = 0;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> key;
        int index = jumpSearch(arr, key, comparisons);
        if (index != -1)
            cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }
    return 0;}
