#include<bits/stdc++.h>
using namespace std;
int main(){
    string s ;
    cin>>s;
    //precompute 
    int hash_char[26] = {0};
    for(int i = 0 ; i < s.size() ; i++){
        hash_char[s[i] - 'a'] ++; // formula to store the char in its speicified index 
    }
    int q;
    cin>>q;
    while(q--){
        char find_char;
        cin>>find_char;
        // fetching 
        cout<<hash_char[find_char - 'a']<<" times"<<endl; //to fetch you must use the index formula

    }
    return 0;

}