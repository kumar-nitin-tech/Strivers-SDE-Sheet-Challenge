/*
 Problem Link : https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_8230746?challengeSlug=striver-sde-challenge
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfitOp(vector<int> &prices){
    if(prices.size() == 1) return 0;
    int minPrice = prices[0];
    int profit = 0, maxProfit = INT_MIN;
    for(int i=1;i<prices.size();i++){
        minPrice = min(minPrice, prices[i]);
        profit = prices[i] - minPrice;
        maxProfit = max(maxProfit,profit);
    }
    return maxProfit;
}


int main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for(auto &i:prices){
        cin>>i;
    }
    cout<<maxProfitOp(prices);
    return 0;
}