/*
    Problem Link : https://www.codingninjas.com/codestudio/problems/trapping-rain-water_8230693?challengeSlug=striver-sde-challenge
*/
#include<bits/stdc++.h>
using namespace std;

long getTrappedWater(vector<int> &height, int n){
    int low = 0, high = n-1, leftMax = 0, rightMax = 0;
    int waterTrap = 0;
    while(low<=high){
        if(height[low]<=height[high]){
            if(height[low] >= leftMax){
                leftMax = height[low];
            }
            else{
                waterTrap += leftMax - height[low];
            }
            low++;
        }
        else{
            if(height[high]>=rightMax){
                rightMax = height[high];
            }
            else{
                waterTrap += rightMax - height[high];     
            }
            high--;
        }
    }
    return waterTrap;

}

int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(auto &i:height){
        cin>>i;
    }
    cout<<getTrappedWater(height,n);
    return 0;
}