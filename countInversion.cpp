/*
    Problem Link : https://www.codingninjas.com/codestudio/problems/count-inversions_8230680?challengeSlug=striver-sde-challenge
*/
#include<bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int start, int end, int mid){
    int left = start, right = mid+1;
    int count = 0;
    vector<int> temp;
    while(left <= mid && right <=end){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            count += mid - left + 1;
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=end){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=start; i<=end;i++){
        arr[i] = temp[i-start];
    }
    return count;
}

int mergeSort(vector<int> &arr, int start, int end){
    int count = 0;
    if(start>=end) return count;
    int mid = (start+end)/2;
    count += mergeSort(arr,start,mid);
    count += mergeSort(arr,mid+1,end);
    count += merge(arr,start,end,mid);
    return count;
}

//Optimized Approach 
int countInversion(vector<int> &arr){
    return mergeSort(arr,0,arr.size()-1);
}
int main(){
     int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    cout<<countInversion(arr);
    return 0;
}