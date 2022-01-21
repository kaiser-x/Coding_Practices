// 875. Koko Eating Bananas
// Medium

// Koko loves to eat bananas. There are n piles of bananas, 
// the ith pile has piles[i] bananas. The guards have gone 
// and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. 
// Each hour, she chooses some pile of bananas and eats k 
// bananas from that pile. If the pile has less than k bananas, 
// she eats all of them instead and will not eat any more 
// bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating 
// all the bananas before the guards return.

// Return the minimum integer k such that she can eat all 
// the bananas within h hours.

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
 
// Constraints:
// 1 <= piles.length <= 104
// piles.length <= h <= 109
// 1 <= piles[i] <= 109

class Solution {
public:
    //striver method with blackbox and stuff
    int blackbox(vector<int>nums,int &n,int &mid){
        int hr=0;
        for(int i=0;i<n;i++){
                // hr+=ceil((double)nums[i]/(double)mid);
                hr+=(nums[i]+mid-1)/mid;
        }
        // cout<<hr<<" ";
        return hr;
    }
    int minEatingSpeed(vector<int>& piles, int hour) {
        int n=piles.size();
        auto mn=min_element(piles.begin(),piles.end());
        auto mx=max_element(piles.begin(),piles.end());
        int l=1;
        int h=*mx;
        int ans=0;
        while(l<=h){
             int mid=l+(h-l)/2;
            int k=blackbox(piles,n,mid);
            if(k<=hour){
                ans=mid;
                h=mid-1;
            }else 
                l=mid+1;
        }
        return ans;
    }
    
};