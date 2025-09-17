class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int low = 1,high = *max_element(piles.begin(),piles.end());
       int rate = high;
       while(low <= high){
        int mid = low + (high - low) / 2;
        long long hoursTaken = 0;
        for(int pile : piles){
             hoursTaken += ceil((double)pile / mid);
        }
        if(hoursTaken <= h){
            rate = mid;
            high = mid - 1;
        }
        else low = mid + 1;
       }
       return rate;
    }
};
