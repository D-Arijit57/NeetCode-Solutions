
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      // get the size of the row and col
      int n = matrix.size() , m = matrix[0].size();
      // assign the two pointers in the start and in the end
      int low = 0 , high = (n*m - 1);
      while(low <= high){
        int mid = low + (high - low) / 2;
        // calculate the row and col 
        int row = mid / m , col = mid % m;
        if(matrix[row][col] == target) return true; // if the element is found return true
        else if(matrix[row][col] > target) high = mid - 1; // if the element is greater than the target decrease right pointer
        else low = mid + 1;// if the element is smaller then increase the left pointer
      }
      return false ; // since the element is not found return false
    }
};


/*
class Solution {
    // Recursive Version
public:
    bool bs(vector<vector<int>>&matrix , int low, int high , int target, int m){
        if(low > high) return false;
        int mid = low + (high - low) / 2;
        int row = mid / m , col = mid % m;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) return bs(matrix , low , mid - 1 ,target,m);
        else return bs(matrix, mid+1, high, target,m);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();
        return bs(matrix,0,(n*m - 1),target,m);
    }
};

*/