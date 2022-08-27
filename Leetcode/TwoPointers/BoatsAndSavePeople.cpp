// 881. Boats to Save People
// Medium

// You are given an array people where people[i] is the weight of the ith person, and an 
// infinite number of boats where each boat can carry a maximum weight of limit. 
// Each boat carries at most two people at the same time, provided the sum of the weight 
// of those people is at most limit.
// Return the minimum number of boats to carry every given person.
// Example 1:
// Input: people = [1,2], limit = 3
// Output: 1
// Explanation: 1 boat (1, 2)
// Example 2:
// Input: people = [3,2,2,1], limit = 3
// Output: 3
// Explanation: 3 boats (1, 2), (2) and (3)

class Solution {
public:
    /*the approach is to maintain a greedy way, imagin if there are two people, there are 3 possibilities
     that could happen, both of their weight is less than limit, both of their weight is equal to limit,
     both of their weight is greater than limit, then in first two scenarios we can directly put
     two people in the boat, but in last case, we can only put one person, and greedyly speaking, we 
     would want to get done with the heavy guy,so thats why we sort the array then travers using two
     pointers method,, we check above scenarios and increase the pointers accordingly*/
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int boat=0;
        //sort 
        sort(people.begin(),people.end());
        int l=0,h=n-1;
        // while(l<=h){
        //     //in some case the l becomes equal to h and in some it doesnt, we cant predict ir, actully
        //     //we can, if the number of distinct numbers is odd the l will be equal to h in osme point
        //     //if number of distinct numbers is even then l and h will directly cross each other
        //     //not gettin l==h,but yeah findind number od distinct element is extra work,instead we can
        //     //just increase boat in case l==h
        //     if(l==h){
        //         boat++;
        //         break;
        //     }
        //     int weight=people[l]+people[h];
        //     //if weight is <= limit, then we just need one boat for two people
        //     //so we increase both l and h
        //     if(weight<=limit) {
        //         boat++;
        //         l++;
        //         h--;
        //     }
        //     //if weight>limit, then we need 1 boat but can only put 1 person that to the heavy one
        //     //so we increase only h
        //     else{
        //         boat++;
        //         h--;
        //     }
        // }
        // return boat;
        
        //Now from the above approach you would have noticed that we always increase boat by 1 only,
        //and the main workd is done using the pointers l and h,so we can do this
        
        while(l<=h){
            if(people[l]+people[h]<=limit) l++,h--;
            else h--;
            boat++;
        }
        return boat;
    }
};