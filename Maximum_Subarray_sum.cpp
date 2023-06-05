#include<bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[], int n){
    long long sum = 0, maxSum =INT_MIN;
    for(long long i=0;i<n;i++){
        sum += arr[i];
        maxSum = max(maxSum,sum);
        if(sum<0) sum =0;
    }
    if(maxSum<0){
        return 0;
    }
    return maxSum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];}
    cout<<maxSubarraySum(arr,n);
    return 0;
}