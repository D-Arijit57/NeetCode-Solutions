class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        for (auto const& str : strs){
            // format : length + '#' + actual_string
            // e.g :  "neet" - > 4#neet
            enc += to_string(str.length())+ "#" + str;
        }
        return enc;
    }

    vector<string> decode(string s) {
        vector<string>dec;
        int i = 0;
        while( i < s.length()){
            // find the '#' in the string
            int hashPosition = s.find('#' , i);
            // extract the length
            // the stoi is used to convert the length in string to a integer value 
            int length = stoi(s.substr(i,hashPosition - i));
            // extract the string of the speicified length after '#'
            string str = s.substr(hashPosition + 1, length);
            dec.push_back(str);
            // move to the next encoded string
            i = hashPosition + 1 + length;  
        }
        return dec ;
    }
};
