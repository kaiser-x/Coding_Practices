// 11. Container With Most Water
// Medium
// You are given an integer array height of length n. 
// There are n vertical lines drawn such that the two 
// endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a 
// container, such that the container contains the most 
// water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Example 1:

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1

//two pointer greedy approach, start 0 and end n-1 li ke always,
// find the area and check for max area 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int max=INT_MIN;
        int i=0,j=n-1;
        while(i<j){
            int mn=min(height[i],height[j]);
            int area=mn*(j-i);
            if(area>max){
                max=area;
            }
            //as max area can only be obtained if height is greater,
            //so we check if height of i is greater or j is greater
            if(height[i]>height[j]) j--;
            else i++;
        }
        return max;
    }
};