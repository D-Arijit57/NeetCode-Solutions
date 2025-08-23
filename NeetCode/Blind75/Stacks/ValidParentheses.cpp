class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
       // maintain a hashmap for each pair of parentheses 
       // key -> closing bracket , val -> opening bracket
       unordered_map<char, char>closetoopen = {
        {')','('},{']','['},{'}','{'}
       };
       // now for each character 
       // check if its exist in the hashmap 
       // if it does and the stack is not empty along with the its top is same as the key of the hashmap (according to the char ) -> pop the element
       for(char c:s){
        if(closetoopen.count(c)){
            if(!st.empty() && st.top() == closetoopen[c]){
                st.pop();
            }
            else{
                return false ;
            }
        }
        // if it doesn't exist in the stack push it into the stack 
        else{
            st.push(c);
        }
       }
       // return the stack status 
       return st.empty();
    }
};
