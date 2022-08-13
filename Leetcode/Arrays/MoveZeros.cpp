// 283. Move Zeroes
// Easy
// Given an integer array nums, move all 0's to the end of it while
//  maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.
// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

class Solution {
    //The First approach idea is to find first 0 index,then iterate array, find everytime
    //encountering non 0 elements, swap it with that 0 ,then look for next 0 index and so on.
    static void swap(int a,int b){
        int t=a;
        a=b;
        b=t;
    }
    public void moveZeroes(int[] nums) {
        int n=nums.length;
        int i=0,j;
        //Index of First occurence of 0
        while(i<n&&nums[i]!=0) i++;
        j=i+1;
        while(j<n){
            //non 0 element swap it with 0 at i
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                //find the next index where the value is 0
                i++;
                while(i<n&&nums[i]!=0) i++;
            }
            j++;
        }
        //Second approach less operations
        //Another way is to make Count of 0's and try to move them as whole whenever a
        //non 0 element is encountered
        
        int count0=0;
        for(int i=0;i<n;i++){
            //check if element is 0,if it is then increase count
            if( nums[i]==0) count0++;
            
            //if non zero element then, chech if we have any zeros before it,
            //if we do then assign nums[i] value to the first 0 in those grp of 0's
            //and change current nums[i] to 0 to maintain same number of 0's
            else if(count0>0||count0!=0){
                //to acces first 0 in the group of 0's, subtract current index with number 
                //of 0's
                nums[i-count0]=nums[i];
                nums[i]=0;
            }
        }
    }
    
}