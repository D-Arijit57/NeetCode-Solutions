#include<bits/stdc++.h>
using namespace std;
vector<int> prod_of_array(vector<int>&nums){
    vector<int>ans(nums.size(),1);
    int pre = 1;
    for(int i = 0 ; i < nums.size() ; i++){
        ans[i] = pre;
        pre *= nums[i];
    }
    int post = 1;
    for(int i = nums.size() - 1 ; i >= 0 ; i-- ){
        ans[i] *= post;
        post *= nums[i];
    }
    return ans;

}

int main(){
    int n;
    cout<<"Enter the number of elements in the array : "<<'\n';
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements for the array : "<<'\n';
    for(int i = 0 ; i < n ; i++){
        cin>>nums[i];
    }
    vector<int> ans =  prod_of_array(nums);
    cout<<"Products of all the elements except nums[i] (current index) is : "<<'\n';
    for(auto const& num : ans){
        cout<<num<<" ";
    }
}