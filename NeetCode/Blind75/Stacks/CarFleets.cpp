  /*
    Approach :
    -> Create a pair of position and respective speed for each car 
    -> Sort them up so that , the car having the longest distance from the target is at the first (car[0])
    and the one having the sortest distance is at the last car[n-1]
    -> Iterate it from the back of the pairs 
    -> Make sure you keep a slowesTime variable to keep the track of the last longest arrival time of a car 
    -> for each arrival time check for the last time taken 
        if its greater (arrivalTime > slowesTime) means the current car cannot match
        with the speed of the car which is ahead of it then its a fleet (individual)
        -> also make sure you update the new longest arrival time (slowestTime)

        if its lesser or equal to (arrivalTime <= slowestTime) then for sure we know it'll
        get merged to the fleet with the car ahead of it which we have already counted , so we 
        don't need to do anything here 
    -> return the fleet cnt;
    
    */
   // Approach 1 : Iterative Approach 
   class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0) return 0;
        int fleets = 0; double slowestTime = 0;
        vector<pair<int, int>>cars(n);
        for(int i = 0 ; i < n ; i++){
            cars[i] = {position[i] , speed[i]};
        }
        sort(cars.begin() , cars.end());
        for(int i = n - 1 ; i >= 0 ; i--){
            double timeToArrive = static_cast<double>(target - cars[i].first) / cars[i].second;
            if(timeToArrive > slowestTime){
                fleets++;
                slowestTime = timeToArrive;
            }
        }
        return fleets;
    }
};
// Approach 2 : Stack 
   class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0) return 0;
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = ({position[i], speed[i]});
        }
        
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());
        // till here its the same as the before approach 
        stack<double> st;
        
        for (const int& car : cars) {
            int pos = car.first;
            int spd = car.second;
            double timeTaken = (double)(target - pos) / spd;
            
            if (st.empty() || timeTaken > st.top()) {
                st.push(timeTaken);
            }
            // if its equal or less to the top of the stack (last arrival time) then we don't need to do anything 
            // since the car having the same speed and position will get merged into the already defined fleet 
        }
        
        return st.size();        
    }
};