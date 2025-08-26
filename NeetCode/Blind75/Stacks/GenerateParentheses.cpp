#include<bits/stdc++.h>
using namespace std;
void backtrack(vector<string>&ans,string curr, int open , int close, int n){
    if(curr.length() == 2 * n){
        ans.push_back(curr);
        return;
    }
    if(open < n){
        curr += '(';
        backtrack(ans, curr, open + 1, close, n);
        curr.pop_back();
    }
    if(close < open){
        curr += ')';
        backtrack(ans,curr,open, close + 1, n);
        curr.pop_back();
    }
}
vector<string>generateParentheses(int n){
    string curr = "";
    vector<string> ans;
    backtrack(ans,curr,0,0,n);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of pairs of parentheses : ";
    cin>>n;
   vector<string> res = generateParentheses(n);
   for(auto it : res){
    cout<<it<<" ";
   }
}