/*
Problem Link : https://www.codingninjas.com/codestudio/problems/next-permutation_8230741?challengeSlug=striver-sde-challenge
*/


#include <bits/stdc++.h> 
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n){
    int pivot = -1;
    for(int i=n-2;i>=0;i--){
        if(permutation[i] < permutation[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1){
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    for(int i=n-1;i>=0;i--){
        if(permutation[i] > permutation[pivot]){
            swap(permutation[i], permutation[pivot]);
            break;
        }
    }
    reverse(permutation.begin()+pivot+1, permutation.end());
    return permutation;
}

int main(){
    int n;
    cin>>n;
    vector<int> permutation(n);
    for(auto &i:permutation){
        cin>>i;
    }
    vector<int> ans = nextPermutation(permutation,n);
    for(auto i:permutation){
        cout<<i<<" ";
    }
    return 0;
}