// So the Basic Idea is to know that Sum of any two side should be greater 
// than the third side , only then a triangle can be formed, 
// For eg 1,1,2 here we take 2 as base and 1 as side1 and 1 as side2 ,
// then we can see try to form a triangle with those sides as you place it
//  at the edges of the base and try to form triangle the sides will never
// intersect and when they do the three lines form a single line.

// SO we take a greedy approach, sort the array and check from last 3 number,
// and if they satisfy above rule, if it does then return a+b+c, as the array
// is sorted so that perimeter will be the largest.

class Solution {
public:
    //Sum of any two side of a trinangle must always be greater than third side
    int largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // for(int i=n-3;i>=0;i--){
        //     int a=nums[i],b=nums[i+1],c=nums[i+2];
        //     if(a+b>c&&a+c>b&&b+c>a) return a+b+c;
        // }
        
        //So now instead of checking all sum greater than third side, we can just sort
        //the array and iterate from last, check if nums[i]< nums[i-1]+nums[i-2],
        //this works becs nums[i] obviously greater than nums[i-1],nums[i-2],but
        //only individualiy, so if sum of nums[i-1]+nums[i-2] >nums[i], that means
        //nums[i]+nums[i-1]>nums[i-2], similarly nums[ii]+nums[i-2]>nums[i-1], this
        //is bcs array is sorted, and nums[i-1]+nums[i-2]>nums[i]; and aslo as array
        //is sorted so that perimeter would be the lasrgest.
        for(int i=n-1;i>=2;i--){
            int c=nums[i],b=nums[i-1],a=nums[i-2];
            if(a+b>c) return a+b+c;
        }
        return 0;
    }
};