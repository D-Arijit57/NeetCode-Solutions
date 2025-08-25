class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/"){
                // FIX 1: Changed from stoi(st.pop()) to st.top(); st.pop();
                // because st.pop() doesn't return a value in C++
                int elem1 = st.top(); st.pop();
                int elem2 = st.top(); st.pop();
                int ans = 0;
                
                if(tokens[i] == "+"){
                    ans = elem1 + elem2; // FIX 2: Changed from += to = (no need to add to 0)
                    st.push(ans);
                }
                else if(tokens[i] == "*"){
                    ans = elem1 * elem2; // FIX 2: Changed from += to =
                    st.push(ans);
                }
                else if(tokens[i] == "/"){
                    // FIX 3: Fixed order - elem2/elem1 because elem2 was popped second (so it's first operand)
                    // FIX 4: Removed the comparison logic - division should respect actual order
                    ans = elem2 / elem1;
                    st.push(ans);
                }
                else { // subtraction
                    // FIX 3: Fixed order - elem2-elem1 because elem2 was popped second (so it's first operand)  
                    // FIX 4: Removed the comparison logic - subtraction should respect actual order
                    ans = elem2 - elem1;
                    st.push(ans);
                }
            }
            // FIX 5: Moved the else outside the operator if-block (was incorrectly nested)
            else {
                st.push(stoi(tokens[i]));
            }
        }
        // FIX 6: Changed from st.pop() to st.top() since pop() doesn't return value
        return st.top();
    }
};