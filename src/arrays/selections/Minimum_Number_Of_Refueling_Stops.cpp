/*
Problem Statement:
A car travels from a starting position to a destination which is target miles east of the starting position.
There are gas stations along the way. 
The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates 
that the ith gas station is "positioni" miles east of the starting position and has "fueli" liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. 
It uses one liter of gas per one mile that it drives. 
When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station 
into the car.

Return the minimum number of refueling stops the car must make in order to reach its destination. 
If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. 
If the car reaches the destination with 0 fuel left, it is still considered to have arrived.
*/

/*
Algorithm:

Greedy Algorithm: (Max-Heap)
        1.  Priority_queue is used as max_heap to store the capacity of the gas stations we driven by.
        2.  Only when we out of fuel, we pick the gas station with largest capacity we have visited so far
            to refuel.
        3.  If we can't reach the station/target even after all possible refuels, then we return -1.

    Dynamic Programming:
        1.  dp[i] is farthest location we can get to using "i" refueling stations.
        2.  Result is smallest "i" for which "dp[i] >= target".
        3.  With no stations, we can reach startFuel i.e "dp[0] = startFuel"
        4.  When adding a Station, anytime we would reach this station with "t" refueling stops,
            now we can reach capacity further with "t+1" refueling stops.
*/

/* Problem/Solution link
    * https://leetcode.com/problems/minimum-number-of-refueling-stops/
*/

class Solution {
public:
    int minRefuelStopsGreedy(int target, int startFuel, vector<vector<int>>& stations) {
        int refuelCount = 0, prevStation =0;
        int currentFuel = startFuel;
        priority_queue<int> pqCapacity;
        
        for(vector<int> &station : stations)
        {
            currentFuel -= station[0] - prevStation;
            while(!pqCapacity.empty() && currentFuel < 0)
            {
                refuelCount++;
                currentFuel += pqCapacity.top(); pqCapacity.pop();
            }
            if(currentFuel < 0)
                return -1;
            
            prevStation = station[0];
            pqCapacity.push(station[1]);
        }
        
        currentFuel -= target - prevStation;
        while(!pqCapacity.empty() && currentFuel < 0)
        {
            refuelCount++;
            currentFuel += pqCapacity.top(); pqCapacity.pop();
        }
        if(currentFuel < 0)
            return -1;
        
        return refuelCount;
    }

    int minRefuelStopsDP(int target, int startFuel, vector<vector<int>>& stations) {
        int totalStations = stations.size();
        vector<long> dpMaxReach(totalStations+1, 0);
        dpMaxReach[0] = startFuel;
        
        for(int i = 0; i < totalStations; i++)
        {
            for(int t = i; t >= 0; t--)
            {
                if(dpMaxReach[t] >= stations[i][0]) // If this station is reachable
                {
                    dpMaxReach[t+1] = max(dpMaxReach[t+1], dpMaxReach[t] + stations[i][1]);
                }
            }
        }
        
        for(int i = 0; i <= totalStations; i++)
        {
            if(dpMaxReach[i] >= target)
                return i;
        }
        return -1;
    }
};