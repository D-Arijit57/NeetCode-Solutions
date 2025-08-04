class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Step 1: Count frequencies using hashmap
        unordered_map<int, int> freq;
        for(int i = 0 ; i < n ; i++) {
            freq[nums[i]]++;
        }
        
        // Step 2: Create buckets where index = freq
        // bucket[i] contains all elems with freq i
        vector<vector<int>> bucket(n + 1);
        
        for(auto& pair : freq) {
            int elem = pair.first;
            int freq = pair.second;
            bucket[freq].push_back(elem);
        }
        
        // Step 3: Collect k most frequent elems from highest freq buckets
        vector<int> result;
        
        // Start from highest possible freq and go down
        for(int i = n; i >= 0 && result.size() < k; i--) {
            for(int elem : bucket[i]) {
                result.push_back(elem);
                if(result.size() == k) {
                    break;
                }
            }
        }
        
        return result;
    }
};
