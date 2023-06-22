/*
    Problem Link: https://www.codingninjas.com/studio/problems/0-1-knapsack_8230801?challengeSlug=striver-sde-challenge&leftPanelTab=1
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &values, vector<int> &weights, int n, int maxWeight)
{
	    vector<int> prev(maxWeight+1,0);
    //base Case
    // We can take every value which has weight less than maz weight, so from weight of 0 index to maxWeight we can take
    for(int i = weights[0]; i<=maxWeight;i++) prev[i] = values[0];

    //Nested Loops
    //Recursion start from n-1 to 0
    for(int i=1;i<n;i++){
        //In Recursion weight is from MaxWeight to 0
        for(int w = maxWeight;w>=0;w--){
            int notTake = 0 + prev[w];
            int take = -1e9;
            if(weights[i] <= w)  take = values[i] + prev[w- weights[i]];

            prev[w] = max(take,notTake);
        }
    }
    return prev[maxWeight];
}

int main(){
    int n,maxWeight;
    cin>>n>>maxWeight;
    vector<int> values(n), weights(n);
    for(auto &i:values) cin>>i;
    for(auto &i:weights) cin>>i;

    cout<<maxProfit(values,weights,n,maxWeight);
    return 0;
}