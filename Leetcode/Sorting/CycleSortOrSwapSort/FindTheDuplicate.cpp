// 287. Find the Duplicate Number
// Medium

// Given an array of integers nums containing n + 1 integers 
// where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this 
// repeated number.

// You must solve the problem without modifying the array 
// nums and uses only constant extra space.

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
Cpp Code:

class Solution {
public:
    //We make use of cyclic sort, and after sorting we check whatever the element does not
    //match with corresponding index is the duplicate number.
    //But the problem is the question has mentioned we cant modify given array and we ant use
    //extra space too.
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;){
            if(nums[i]!=nums[nums[i]-1]) swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        for(int i=0;i<n;i++) {
            if(nums[i]!=i+1) return nums[i];
        }
        return -1;
        
        //So we use tortois and hare method of Cycle Detection
        int slow=nums[0],fast=nums[0];
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast) break;
        }
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};

Java Code:

class Solution {
    static void swap(int nums[],int i,int j){
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
    public int findDuplicate(int[] nums) {
        int n=nums.length;
        for(int i=0;i<n;){
            if(nums[i]!=nums[nums[i]-1]) swap(nums,i,nums[i]-1);
            else i++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return nums[i];
        }
        return -1;
        
    //As we cant modify input we have to use Cycle detect tortoise and hare method
        
        int slow=nums[0],fast=nums[0];
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast) break;
        }
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
}