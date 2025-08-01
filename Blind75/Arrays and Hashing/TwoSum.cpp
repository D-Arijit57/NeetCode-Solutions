// SORTING -> TC -> O(NLOGN) SC->O(N)




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

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//       unordered_map<int,int>ind;
//       // stores the elements of the array along with their frequencies 
//       for(int i = 0 ; i < nums.size() ; i++){
//         ind[nums[i]] = i ;
//       }
//       for(int i = 0 ; i < nums.size() ; i++){
//         int diff = target - nums[i];
//         // ind.count(diff) checks if the element is there in the map 
//         // ind[diff] != i checks if the element has an different index 
//         // we wanna check if it has the different index to avoid getting the same element twice 
//         if(ind.count(diff) && ind[diff] != i){
//             return {i,ind[diff]};
//         }
//       }
//       return {};
//     }
// };
