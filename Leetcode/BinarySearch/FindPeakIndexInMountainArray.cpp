// 852. Peak Index in a Mountain Array
// Medium
// An array arr a mountain if the following properties hold:
// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that 
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// arr is guaranteed to be a mountain array.

// You must solve it in O(log(arr.length)) time complexity.
// Example 1:

// Input: arr = [0,1,0]
// Output: 1
// Example 2:

// Input: arr = [0,2,1,0]
// Output: 1

class Solution {
public:
    /* it's a simple binary search but we just need to take care of few edge cases,thing
    is get, mid, then check if arr[mid] is greater than arr[mid-1] and arr[mid+1], i.e to 
    check if it's a peak element , if it is then return mid, now ehy this works is, because
    in this question there can only be one peak element, bcs the element are linearly
    increases til peak element and then linearly decreases till lasst element so, there can
    only be 1 peak element, now if arr[mid] is not peak then check which side is greater
    than arr[mid] and move pointer accordingly, if its mid-1, then h=mid-1 ,if its mid+1
    then l= mid+1,now the edge case is if mid is 0 or n-1, the if will throw error, so
    I though may put an mid1=0&&mid!=n-1 check in first if, but then we also have to
    check mid-1 and mid+1 for moving h and l, and if w put the same condition in all then
    mid ,l and h will remain same, so what can we do to avoid mid being 0 and n-1, simple
    assign l=1 and h=n-2.*/
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=1,h=n-2;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]) return mid;
            else if(arr[mid-1]>arr[mid]) h=mid-1;
            else l=mid+1;
        }
        return -1;
        /*Since the array size is 3 minimum, so there always will be mid+1,we can use that
        for our binary search, here if mid=0 then also its not a problem, and mid will
        never be n-1,as we are going on higher range ,i.e doing l=mid+1, only when 
        arr[mid]<arr[mid+1], and we know that the part from peak to end of array is linearly
        decreasing, so the condtion will never happen.*/
        int l=0,h=n-1;
        while(l<h){
            int mid=l+(h-l)/2;
            if(arr[mid]>arr[mid+1]) h=mid;
            else l=mid+1;
        }
        return l;
        
        //or to simply put they want maximum element in array
        return max_element(arr.begin(),arr.end())-arr.begin();
    }
};