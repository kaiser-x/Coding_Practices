class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int sum=0,n=nums.size();
        // if(n==1&&nums[0]==k) return 1;
        // vector<int> prefix(n,0);
        // prefix[0]=nums[0];
        // for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
        // int count=0;
        // for(int i=0;i<n;i++){
        //     if(prefix[i]==k) count++;
        //     if(i!=n-1){
        //         for(int j=i+1;j<n;j++){
        //              if(prefix[j]-prefix[i]==k) count++;
        //         }
        //     }
        // }
        // return count;
        int sum=0;
        int count=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];            
            if(sum==k)
                count++;
            // cout<<"sum"<<sum<<" ";
            // cout<<endl<<"count:"<<count<<" "<<endl;
            // cout<<"sum-k:"<<sum-k<<" ";
            
            //it can't be else if becuse let's  say sum is equal to k,but we still need to 
            //find sum-k in map ,because of negative numbers the sum became 
            //0 at some point while traversing frwd ,so we have to add that we have to check
            //sum has became 0 ever and add it to the count
            if(m.find(sum-k)!=m.end())
                count+=m[sum-k];
            cout<<endl<<"count:"<<count<<" ";
            m[sum]++;
            cout<<endl<<"m["<<sum<<"]"<<m[sum]<<" "<<endl<<endl;
        }
        return count;
    }
};