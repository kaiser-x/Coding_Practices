// Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must appear as many times as it shows in both arrays and
//  you may return the result in any order.
// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        unordered_map<int,int> om,tm;
        vector<int> res;
        for(int i:nums1) om[i]++;
        for(int i:nums2) tm[i]++;
        
        for(auto i:om){
            if(tm.find(i.first)!=tm.end()){
                int mn=min(i.second,tm[i.first]);
                while(mn>0) {res.push_back(i.first); mn--;}
            }
        }
        return res;
        
        //efficient map approach 
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i:nums1) mp[i]++;
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]>0){ 
                mp[nums2[i]]--;
                res.push_back(nums2[i]);
            }
        }
        return res;
        //two pointer aproach
				sort(nums1.begin(), nums1.end());
				sort(nums2.begin(), nums2.end());
				int i = 0, j = 0;
				vector<int> res;
				while(i < nums1.size() && j < nums2.size()){
                    if(nums1[i] == nums2[j]){
                        res.push_back(nums1[i]);
                        i++;
                        j++;
                    }
                    else if(nums1[i] < nums2[j]){
                        i++;
                    }
                    else if(nums1[i] > nums2[j]){
                        j++;
                    }
				}
				return res;
    }
};