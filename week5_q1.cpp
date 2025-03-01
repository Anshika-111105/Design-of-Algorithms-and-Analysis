#include <iostream>
#include <vector>
using namespace std;
void findMaxOccurrence(int n, vector<char> &arr) {
    vector<int> count(26, 0); // Count array for 26 lowercase alphabets
    // Count occurrences of each character
    for (char ch : arr) {
        count[ch - 'a']++;
    }
    int maxFreq = 0;
    char maxChar = ' '; 
    bool duplicates = false;
    for (int i = 0; i < 26; i++) {
        if (count[i] > maxFreq) {
            maxFreq = count[i];
            maxChar = 'a' + i;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] > 1) {
            duplicates = true;
            break;
        }
    }
    if (!duplicates) {
        cout << "No Duplicates Present" << endl;
    } else {
        cout << maxChar << " " << maxFreq << endl;
    }
}
int main() {
    int T;
    cin >> T; 
    while (T--) {
        int n;
        cin >> n; 
        vector<char> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        findMaxOccurrence(n, arr);
    }
    return 0;
}
