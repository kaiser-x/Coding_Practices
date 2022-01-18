class Solution {
public:
    vector<vector<int>>res;
     void  helper(vector<int>&arr,int i,int k,vector<int>&ds,int n){
         if(k<0) return;
         if(k==0) {
             res.push_back(ds);
             return;
         }
         if(i>=n) return;
         k=k-arr[i];
         ds.push_back(arr[i]);
         helper(arr,i,k,ds,n);
         k=k+arr[i];
         ds.pop_back();
         helper(arr,i+1,k,ds,n);
         
     }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<int>ds;
        int n=arr.size();
        helper(arr,0,k,ds,n);
        return res;
    }
};