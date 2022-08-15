CPP Code:

/*so the idea is kinda base on dictionary, lexographical array will kinda look
like a rotated sorted array,not exactly like it,but the last its and linearly
increasing fation, then a peak element then a drop and it continues,there may
-be another peak or it may be fully decreasing, or the array can be completley
sorted in asc order(the first permutation) or the elements can be sorted in
desc order(the last permutation) ,so we check the first dip point from the 
last after a peak point( note that array: 2134,4 is the peak point and 3 is
dip point,as sigle element is also cosidered to be linearly incresing{from last }),after
find dip point, we find the first element from the last that is greater than 
the dip point lets call it num,after that we swap the dip point and num point
then we get the next possible dictionary permutation, but to make it even 
smaller and make it the next permutation, we need reverse the elements after
dip till the last,bcs as they are in linearliy dec sp if we reverse it we get 
a small number
NOTE: theres a edge case,if the whole array has no dip point,that is array is 
linearly dec,then the next permutation will be the first permutaion - all
elements sorted or the reverse of given array(both are equal) bcs the 
guven array is last permutaion and th  next would be first permutation,its 
like a cycle*/
vector<int> nextPermutation(vector<int> &arr, int n)
{
    //  Write your code here.
//     int i=n-2,dip=-1,num;
//     while(i>=0){
// //         cout<<arr[i]<<" "<<arr[i+1];
//         if(arr[i]<arr[i+1]) {dip=i; break;}
//         i--;
//     }
//     if(dip==-1) {reverse(arr.begin(),arr.end());
//                 return arr;}
//     i=n-1;
//     while(i>=0){
//         if(arr[i]>arr[dip]) { num=i;break;}
//         i--;
//     }
//     swap(arr[dip],arr[num]);
//     reverse(arr.begin()+dip+1,arr.end());
//     return arr;
    
    //more concise manner
    int i=n-2;
    while(i>=0&&arr[i]>=arr[i+1]) i--;
    if(i>=0){
        int j=n-1;
        while(j>=0&&arr[j]<=arr[i]) j--;
        swap(arr[i],arr[j]);
    }
    reverse(arr.begin()+i+1,arr.end());
    return arr;
}

Java Code: 

class Solution {
    static void swap(int nums[],int i,int j){
        int t=nums[i];
        nums[i]=nums[j];
        nums[j]=t;
    }
    static void reverse(int nums[],int i,int j){
        while(i<j) swap(nums,i++,j--);
    }
    public void nextPermutation(int[] nums) {
        int n=nums.length;
        if(n<=1) return;
        int i=n-2;
        while(i>=0&&nums[i]>=nums[i+1]) i--;
        if(i>=0){
        int j=n-1;
        while(j>=0&&nums[j]<=nums[i]) j--;
            swap(nums,i,j);
        }
        reverse(nums,i+1,n-1);
      }
}