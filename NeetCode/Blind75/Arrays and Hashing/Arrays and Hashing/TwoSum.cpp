// SORTING -> TC -> O(NLOGN) SC->O(N)


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> A;
        for (int i = 0; i < nums.size(); i++) {
            A.push_back({nums[i], i});
        }

        sort(A.begin(), A.end());

        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int cur = A[i].first + A[j].first;
            if (cur == target) {
                return {min(A[i].second, A[j].second), 
                        max(A[i].second, A[j].second)};
            } else if (cur < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};

// HASHMAP -> ONE PASS SOLUTION
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>mpp;
    // using an hashmap 
    for(int i = 0 ; i < nums.size() ; i++){
        // calculating the diff to complete the pair 
        int diff = target - nums[i];
        // if the diff exists in the map (it doesn't point towards the end of the map)
        // return the index of the current and the index of the diff 
        if(mpp.find(diff)!=mpp.end()){
            return {mpp[diff],i};
        }
        // if it doesn't then just insert in the map 
        mpp.insert({nums[i],i});   
    }
    return {};
    }
};


// HASHMAP -> TWO PASS SOLUTION 
// TC -> O(N) , SC -> O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int>ind;
      // stores the elements of the array along with their frequencies 
      for(int i = 0 ; i < nums.size() ; i++){
        ind[nums[i]] = i ;
      }
      for(int i = 0 ; i < nums.size() ; i++){
        int diff = target - nums[i];
        // ind.count(diff) checks if the element is there in the map 
        // ind[diff] != i checks if the element has an different index 
        // we wanna check if it has the different index to avoid getting the same element twice 
        if(ind.count(diff) && ind[diff] != i){
            return {i,ind[diff]};
        }
      }
      return {};
    }
};
