#include <iostream>
#include <vector>
using namespace std;
vector<int> commonElements(vector<int> &v1, int n1, vector<int> &v2, int n2){
    vector<int> commons;
    int i = 0, j = 0;
    while (i < n1 && j < n2){
        if (v1[i] == v2[j]){
            commons.push_back(v1[i]);
            i++;
            j++;
        }
        else if (v1[i] < v2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return commons;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int n1, n2;
        cin >> n1;
        vector<int> list1, list2;
        for (int i = 0; i < n1; i++){
            int ele;
            cin >> ele;
            list1.push_back(ele);
        }
        cin >> n2;
        for (int i = 0; i < n2; i++){
            int ele;
            cin >> ele;
            list2.push_back(ele);
        }
        vector<int> commons = commonElements(list1, n1, list2, n2);
        if (commons.empty()){
            cout << "No common element is present !!" << endl;
        }
        else{
            cout << "Common elements are : " << endl;
            for (auto c : commons)
                cout << c << " ";
            cout << endl;
        }
    }
return 0;}