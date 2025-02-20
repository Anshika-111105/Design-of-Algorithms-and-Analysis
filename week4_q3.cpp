#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthSmallestUsingCountSort(vector<int>& arr, int K) {
    int maxElement = *max_element(arr.begin(), arr.end());
    vector<int> count(maxElement + 1, 0);
    for (int num : arr) {
        count[num]++;
    }
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
    int Testcases;
    cin >> Testcases;
    while (Testcases--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int K;
        cin >> K;    
        if (K > 0 && K <= n) {
            cout<<kthSmallestUsingCountSort(arr, K)<<endl;
        } else {
            cout<<"Not present"<<endl;;
        }
    }
    return 0;
}
