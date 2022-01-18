class Solution {
public:
    vector<vector<int>>res;
     void  helper(vector<int>&arr,int ind,int k,vector<int>&ds,int n){
          if(k==0) {
                    res.push_back(ds);
                 return;
             }
            for(int i=ind;i<n;i++){
                if(i>ind&&arr[i]==arr[i-1]) continue;
                if(arr[i]>k) break;
                     k=k-arr[i];
                     ds.push_back(arr[i]);
                     helper(arr,i+1,k,ds,n);
                     k=k+arr[i];
                     ds.pop_back();
            }
         
     }
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        
        vector<int>ds;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        helper(arr,0,k,ds,n);
        return res;
    }
};