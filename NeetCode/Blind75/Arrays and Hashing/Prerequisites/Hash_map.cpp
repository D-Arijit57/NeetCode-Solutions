#include<bits/stdc++.h>
using namespace std;
int main(){
    // implementing hashmap or unordered map 
    vector<int> arr = {1,2,3,3,2,1,2,2,2};
    // map<int, int>mpp; // the map stores all the key and val pairs in a sorted order 
    unordered_map<int,int>mpp; // order can be anything 
    // precompute
    for(int i = 0 ; i < arr.size() ; i++){
        mpp[arr[i]]++;
    }
    // visuliazation of mapping 
    cout<<"Inside the Hashmap : "<<endl;
    for(auto it : mpp){
        cout<<it.first<<" - >"<<it.second<<endl;
    }
    int q;
    cin>>q;
    while(q--){
        int n ;
        cin>>n;
        cout<<mpp[n]<< " times"<<endl;
    }
    return 0;
}