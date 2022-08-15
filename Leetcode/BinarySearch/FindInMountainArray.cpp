// 1095. Find in Mountain Array
// Hard
// (This problem is an interactive problem.)
// You may recall that an array arr is a mountain array if and only if:
// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array mountainArr, return the minimum index 
// such that mountainArr.get(index) == target. If such an index does not exist, return -1.

// You cannot access the mountain array directly. You may only access 
// the array using a MountainArray interface:

// MountainArray.get(k) returns the element of the array at index k (0-indexed).
// MountainArray.length() returns the length of the array.
// Submissions making more than 100 calls to MountainArray.get will be 
// judged Wrong Answer. Also, any solutions that attempt to circumvent the 
// judge will result in disqualification.
// Example 1:
// Input: array = [1,2,3,4,5,3,1], target = 3
// Output: 2
// Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
// Example 2:
// Input: array = [0,1,2,4,2,1], target = 3
// Output: -1
// Explanation: 3 does not exist in the array, so we return -1.

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
/*The target can be at two places in the array, one is linearly increases array from 0 to
peak, and linearly decreasing from peak+1 to n-1,So the idea is to find the peak index, then
binary search target from 0 to peak and if target not fund then reverse binary search 
target from peak+1 to n-1. if not found in both place then return -1.*/
class Solution {
public:
    int findPeakIndex(MountainArray &ma,int n){
        int l=0,h=n-1;
        while(l<h){
             int mid=l+(h-l)/2;
             if(ma.get(mid)>ma.get(mid+1)) h=mid;
             else l=mid+1;
        }
        return l;
    }
     int binarySearch( MountainArray &ma,int l,int h,int target){
    
        while(l<h){
             int mid=l+(h-l)/2;
             if(ma.get(mid)>=target) h=mid;
             else l=mid+1;
        }
        return l;
    }
     int reverseBinarySearch( MountainArray &ma,int l,int h,int target){
    
        while(l<h){
             int mid=l+(h-l)/2;
             if(ma.get(mid)<=target) h=mid;
             else l=mid+1;
        }
        return l;
    }
    //instead of two seperate binary search we can have, a bool flag and check with in
    //same binary search function
    
    int BinarySearchWithFlag(MountainArray &ma,int l,int h,int target,bool flag){
        while(l<=h){
            int mid=l+(h-l)/2;
            int val=ma.get(mid);
            if(val==target) return mid;
            // else if(flag==true){
            //     if(val>target) h=mid-1;
            //     else l=mid+1;
            // }else{
            //     if(val<target) h=mid-1;
            //     else l=mid+1;
            // }
            //we can combine  the else if and else statement
            // else if(flag&&val>target||!flag&&val<target) h=mid-1;
            //even simpler else if
            else if(flag==val>target) h=mid-1;
            else l=mid+1;
        }
         return -1;
    }
    int findInMountainArray(int target, MountainArray &ma) {
        int n=ma.length();
        int l=0,h=n-1;
        int peak= findPeakIndex(ma,n);
        // int res1=binarySearch(ma,0,peak,target);
        //flag true increase subbarray false decreasing subarray
        int res1=BinarySearchWithFlag(ma,0,peak,target,true);
        if(res1!=-1&&ma.get(res1)==target) return res1;
        // int res2=reverseBinarySearch(ma,peak+1,n-1,target);
        int res2=BinarySearchWithFlag(ma,peak+1,n-1,target,false);
        if(res2!=-1&&ma.get(res2)==target) return  res2;
        return -1;
        
    }
};

/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    int findPeakElement(MountainArray ma,int l,int h){
        while(l<h){
            int mid=l+(h-l)/2;
            if(ma.get(mid)>ma.get(mid+1)) h=mid;
            else l=mid+1;
        }
        return l;
    }
    int BinarySearchWithFlag(MountainArray ma,int l,int h,int target){
        boolean flag= ma.get(l)<ma.get(h);
        while(l<=h){
            int mid=l+(h-l)/2;
            int val=ma.get(mid);
            if(val==target) return mid;
            else if(flag==val>target) h=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    public int findInMountainArray(int target, MountainArray ma) {
        int n=ma.length();
        int peak=findPeakElement(ma,0,n-1);
        int res1=BinarySearchWithFlag(ma,0,peak,target);
        if(res1!=-1) return res1;
        int res2=BinarySearchWithFlag(ma,peak+1,n-1,target);
        if(res2!=-1) return res2;
        return -1;
        
    }
}