// 1710. Maximum Units on a Truck
// Easy

// You are assigned to put some amount of boxes onto one 
// truck. You are given a 2D array boxTypes, where 
// boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

// numberOfBoxesi is the number of boxes of type i.
// numberOfUnitsPerBoxi is the number of units in each 
// box of the type i.
// You are also given an integer truckSize, which is the 
// maximum number of boxes that can be put on the truck. 
// You can choose any boxes to put on the truck as long as
//  the number of boxes does not exceed truckSize.

// Return the maximum total number of units that can be 
// put on the truck.

// Example 1:

// Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
// Output: 8
// Explanation: There are:
// - 1 box of the first type that contains 3 units.
// - 2 boxes of the second type that contain 2 units each.
// - 3 boxes of the third type that contain 1 unit each.
// You can take all the boxes of the first and second types, and one box of the third type.
// The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.

bool compare(vector<int>&a,vector<int>&b){
        if(a[1]>b[1]) return true;
        else if(a[1]<b[1]) return false;
        else if(a[0]>b[0]) return true;
        return false;
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int res=0;
        int n=boxTypes.size();
        for(int i=0;i<n;i++){
            if(truckSize==0) break;
            int boxes=boxTypes[i][0];
            int units=boxTypes[i][1];
            if(truckSize>=boxes){
                res+=boxes*units;
                truckSize-=boxes;
            }else if(truckSize<boxes){
                res+=truckSize*units;
                truckSize=0;
            }
        }
        return res;
    }
};