class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Create a answer vector
       vector<int>ans(nums.size(),1);
       // initialize the prefix with 1 (since we are going to find the products)
       int pre = 1;
       // for each element in the array calculate the prefix product for it
       // the product will be calculated , for every element except for nums[i] (currnet index)
      for(int i = 0 ; i < nums.size() ; i++){
        ans[i] = pre;
        pre *= nums[i];
      }       
      // for each element calculate the postfix products (starting from the end the array)
      int post = 1;
      for(int i = nums.size() - 1 ; i >= 0 ; i--){
        ans[i] *= post;
        post *= nums[i];
      }
       return ans;
    }
};
