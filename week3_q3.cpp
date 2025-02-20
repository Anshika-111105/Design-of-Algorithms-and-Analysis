#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool hasDuplicates(vector<int>& arr) {
    sort(arr.begin(), arr.end()); 
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            return true;
        }
    }
    return false;
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
        if (hasDuplicates(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
