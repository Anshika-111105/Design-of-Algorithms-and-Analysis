#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void maxFrequency(char arr[]){
    int n=arr.length();
    int freq[26]={0};
    for(int i=0;i<n;i++){

    }
    char ans;
    char ch='a';
    int max=INT16_MIN;
    for(int i=0;i<26;i++){
        if(freq[i]>max){
            max=freq[i];
            ans=ch;
        }
        ch++;
    }

}

