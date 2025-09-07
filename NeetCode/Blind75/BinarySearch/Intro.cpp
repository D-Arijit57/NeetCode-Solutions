#include<bits/stdc++.h>
using namespace std;
int implement_binary_search(vector<int>&nums,int low, int high, int target){
    if(low > high) return -1;
    int mid = low + (high - low) / 2;
    if(nums[mid] < target) return implement_binary_search(nums,mid+1,high,target);
    else if(nums[mid] > target) return implement_binary_search(nums, low, mid - 1, target);
    return mid;
}
int main(){
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
    int target;
    cout<<"Enter your target: ";
    cin>>target;
    sort(nums.begin() , nums.end());
    int ans = implement_binary_search(nums,0,n-1,target); 
    cout<<"The element's index is : "<<ans;
}