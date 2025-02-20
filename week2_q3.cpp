#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int countPairsWithDifference(vector<int>& arr, int k) {
    unordered_set<int> elements;
    int count = 0;
    
    for (int num : arr) {
        if (elements.count(num - k)) count++;
        if (elements.count(num + k)) count++;
        elements.insert(num);
    }
    
    return count;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cin >> k;
        cout << countPairsWithDifference(arr, k) << endl;
    }
    
    return 0;
}
