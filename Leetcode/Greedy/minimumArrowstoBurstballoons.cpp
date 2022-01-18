// There are some spherical balloons taped onto a flat 
// wall that represents the XY-plane. The balloons are 
// represented as a 2D integer array points where 
// points[i] = [xstart, xend] denotes a balloon whose 
// horizontal diameter stretches between xstart and xend. 
// You do not know the exact y-coordinates of the balloons.

// Arrows can be shot up directly vertically 
// (in the positive y-direction) from different 
// points along the x-axis. A balloon with xstart and 
// xend is burst by an arrow shot at x if xstart <= x <= xend. 
// There is no limit to the number of arrows that can be shot.
//  A shot arrow keeps traveling up infinitely, bursting
//   any balloons in its path.

// Given the array points, return the minimum number
//  of arrows that must be shot to burst all balloons.

// Example 1:

// Input: points = [[10,16],[2,8],[1,6],[7,12]]
// Output: 2
// Explanation: The balloons can be burst by 2 arrows:
// - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
// - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

class Solution {

public:
   static bool compare(vector<int> &a,vector<int> &b){
       return a[1]<b[1];
    if(a[1]<b[1]) return true;
    else if(a[1]>b[1]) return false;
    else if(a[0]<b[0]) return true;
    else return false;
}
    int findMinArrowShots(vector<vector<int>>& p) {
        int n=p.size();
        if(n==0) return 0;
        sort(p.begin(),p.end(),compare);
        int count=1,prevend=p[0][1];
        for(int i=1;i<n;i++) {
            if(p[i][0]>prevend){
            count++;prevend=p[i][1];}
        }
        return count;
    }

};