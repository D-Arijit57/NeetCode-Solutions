#include<bits/stdc++.h>
using namespace std;

int main(){
    // input from the user 
    int n ;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    // pre compute
    int hash[13] = {0} ; // since the total number of elements in the array are 12 and we need to represent all the elements as indices in the hasharray we have to take the hash array size as 13 [in general [n+1]]
    for(int i = 0 ; i < n ; i++){
        hash[arr[i]] += 1; // storing the frequency for each element 
    }
    int q ; // number of queries for the numbers in the array to find out their frequencies 
    cout << "Enter the total number of queries : ";
    cin >> q ;
    while(q--){
        int number ; // the number of which's frequency you wanna find out 
        cout << "Enter a number from the array : ";
        cin >> number;
        // fetch 
        cout<<"The number appears ";
        cout<<hash[number]<<" times"<<endl;
    }
    
    return 0;
}