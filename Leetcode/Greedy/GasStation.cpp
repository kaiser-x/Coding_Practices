// 134. Gas Station
// Medium
// There are n gas stations along a circular route, 
// where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs 
// cost[i] of gas to travel from the ith station to its 
// next (i + 1)th station. You begin the journey with an 
// empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting
// gas station's index if you can travel around the circuit 
// once in the clockwise direction, otherwise return -1. 
// If there exists a solution, it is guaranteed to be 
// unique

// Example 1:

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
// Therefore, return 3 as the starting index.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int gasSum=accumulate(gas.begin(),gas.end(),0);
        int costSum=accumulate(cost.begin(),cost.end(),0);
        //the cost can never be greater then the available gas amount
        // just basic 100IQ move
        if(costSum>gasSum) return -1;
        int current=0,start=0;
        //now we are trying to find the point from where the gas[i]- cost[i]
        //is not going negative,if it goes negative means we cannot move to 
        //that point so we start from next point by incrementing start
        // you might be wondering what if at some index the current is positive 
        //  but gets negative later without reaching n(size) 
        //  ,then there might be another index (the answer wala index) after the one 
        //  which is considered now ,if it fails at the end i.e at n that means the 
        //  costSum is Greater the gasSum so it would have already returned -1, 
        //  now also why we are not checking cycle is because its mentioned there's 
        //  only unique solution so if a particular path is found then that gotta be the 
        //  answer, the path infers starting at a index and kept current being positive 
        //  till the n(size) end.
        for(int i=0;i<n;i++){
            current+=gas[i]-cost[i];
            if(current<0){
                start=i+1;
                current=0;
            }
        }
        return start;
    }
};