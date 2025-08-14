#include<bits/stdc++.h>
using namespace std;

//Here , we are going to solve Number of subarrays with sum k question to understand prefix sum 
int solve_prefixsum(vector<int>arr, int k ){
    map<int, int>mpp;
    mpp[0] = 1; // initializing the default sum
    int presum = 0 , cnt = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        presum+=arr[i];
        int remove =  presum  - k;
        cnt += mpp[remove];
        mpp[presum]++;
    }
    return cnt;
    
}
int main(){
    int n , k;
    cout<<"Enter the number of elements : "; 
    cin>>n; 
    cout<<"Enter the value of k : ";
    cin>>k;
    vector<int>arr(n);
    cout<<"Enter the elements of the array : ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    cout<<"The number of subarrays with the sum k is : " <<solve_prefixsum(arr,k)<<endl;

}