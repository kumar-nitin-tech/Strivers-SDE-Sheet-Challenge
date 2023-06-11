/*
   problem link : https://www.codingninjas.com/codestudio/problems/sort-0-1-2_8230695?challengeSlug=striver-sde-challenge
*/
#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr){
    int left = 0, end = arr.size()-1, mid = 0;
    while(mid<=end){
        if(arr[mid] == 0){
            swap(arr[left],arr[mid]);
            left++; mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid] , arr[end]);
            end--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    sort012(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}