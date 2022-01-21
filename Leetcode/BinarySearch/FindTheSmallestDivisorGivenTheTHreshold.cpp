class Solution {
    private:
    int Summation(vector<int>&nums,int div,int n){
        int sum=0;
        //to find cieled summation.
        for(int i=0;i<n;i++){
            // val = (a + b - 1) / b;
            sum+=(nums[i]+div-1)/div;
            // if(nums[i]%div!=0)
            //     sum+=nums[i]%div;
        }
        return sum;
    }
public:
//the minimum divisor will be 1 and maximum will be max(nums) array ,
// because after that the summation will become constant
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        cout<<mx;
        int res;
        int l=1,h=mx;
        while(l<h){
            long long int mid=l+(h-l)/2;
            int sum=Summation(nums,mid,n);
            if(sum<=threshold) {
                h=mid;
            }
            else l=mid+1;;   
        }
        return l;
    }
};