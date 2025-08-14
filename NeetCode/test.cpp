#include<bits/stdc++.h>
using namespace std;

   string encode(vector<string>& strs) {
        string enc = "";
	for(auto const& it : strs){
		enc += to_string(strs.size()) + "#" + it;
        }
    return enc;

    }

    vector<string> decode(string s) {
       vector<string>decoded;
	    int i = 0;
    while( i < s.length()) {
		int hashPos = s.find("#",i) ;
	    int length = stoi(s.substr(i,hashPos - i)) ;
	    string st = s.substr(hashPos + 1, length);
	    decoded.push_back(st);
	    i  = hashPos + 1 +  length;  
        }
    return decoded;
    }
int main(){
    vector<string>strs;
    for(int i = 0  ; i < 4 ; i++){
        string temp ;
        cin>>temp;
        strs.push_back(temp);
    }
    string encoded = encode(strs);
    cout<<"The encoded string is: "<<encoded<<'\n';
    vector<string>dec = decode(encoded);
    cout<<"The decoded String is: ";
    for(auto it : dec){
        cout<<it<<" ";
    }
    return 0;
}