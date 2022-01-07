// 410. Split Array Largest Sum
// Hard
// Given an array nums which consists of non-negative 
// integers and an integer m, you can split the array 
// into m non-empty continuous subarrays.

// Write an algorithm to minimize the largest sum 
// among these m subarrays.

class Solution {
    private:
    int SubArrays(vector<int>&v,int mid,int n){
        int count=1,sum=0;
        for(int i=0;i<n;i++){
            if(sum+v[i]>mid){
                sum=v[i];
                count++;
            } else
                sum+=v[i];
        }
        cout<<count<<" ";
        return count;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        //the worst case would be to split the array int n sub arrays,at that time the low 
        //will be max element of the array,similary if n=1 the the high will be sum of total
        //array,so lowest possible answer is max element of array and highest answer
        //is sum of the whole array;
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        // cout<<
        cout<<"sum:"<<h;
        int ans;
        while(l<=h){
            long long int mid=l+(h-l)/2;
            int subarrays_count=SubArrays(nums,mid,n);
            if(subarrays_count<=m) {ans=mid;h=mid-1;}
            else l=mid+1;
        }
        return ans;
    }
};