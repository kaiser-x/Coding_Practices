// 15. 3Sum
// Medium
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such 
// that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:
// Input: nums = []
// Output: []
// Example 3:
// Input: nums = [0]
// Output: []
 
class Solution {
public:
    //Obviously the brute would be to use three loops,and check if they sum to 0
    //but TC would be O(n3) ,which is a no no.
    //Another way would be to keep a+b in two loop and creating a hash for the 
    //third var c suchthat c=-(a+b),and then sort the abc and insert them into set
    //bad idea but it works ,O(n2*logm) m is number of unique answers,and SC O(M+N)
    //Equation is a+b+c=0,a+b is taken from loop,c is needed to be found using the
    //hash, because c=-(a+b) //this would lead to tle too.
    vector<vector<int>> threeSum(vector<int>& nums) {
//         unordered_map<int,int> hash;
//         vector<vector<int>>res;
//         set<vector<int>> st;
//         int n=nums.size();
//         for(int i=0;i<n;i++) hash[nums[i]]++;
//         for(int i=0;i<n;i++){
//             //as the nums[i] is considered as a it has to be removed from hashmap
//             //so that it does not come in value of c
//             hash[nums[i]]--;
//             for(int j=i+1;j<n;j++){
//                 //Similarly we consider nums[j] as b,so remoe it from hash
//                 hash[nums[j]]--;
//                 int c=-1*(nums[i]+nums[j]);
//                 if(hash[c]){ 
//                     vector<int> tup{nums[i],nums[j],c};
//                     //sort the vector
//                     sort(tup.begin(),tup.end());
//                     //check if it's unque
//                     if(st.find(tup)==st.end()){
//                         res.push_back(tup);
//                         st.insert(tup);
//                         }
                    
//                     }
//                 //as considereation is over we add those value are added back
//                 hash[nums[j]]++;
//                 }
//             hash[nums[i]]++;
//             }
//         sort(res.begin(),res.end());
//     return res;      

        
        //now the optimal way is to like keep a fixed using loop and applying two pointer for 
        //b and c, b+c=-a
        //sort the array ,because answer is in sorted order and it helpes in removing 
        //duplicates as we can just check the prev element ,if its same then move else
        //calculate .
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int l,h,n=nums.size();
        int i=0;
        while(i<n-2){
            int a=nums[i];
            l=i+1,h=n-1;
            while(l<h){
                int sum=nums[l]+nums[h];
                if(sum==-1*a){
                    res.push_back({a,nums[l],nums[h]});
                    //to avoid duplicates we are going to move l and h so that it's not equal
                    //to the previous l and h
                    // i forgot to add this l++,h-- and bottom i++ line,So the idea is
                    //to not select the number which are already there in the result
                    //for that we need to move from the selected indices ,so we need
                    //to move then check
                    l++;h--;
                    // while(l<h&&l!=i+1&&nums[l]==nums[l-1]) l++;
                    // while(l<h&&h!=n-1&&nums[h]==nums[h+1]) h--;
                    //that i+1 and n-1 check is not necessary,as we are inc i and dec h,
                    //it'd be never equal to i+n or n-1
                    while(l<h&&nums[l]==nums[l-1]) l++;
                    while(l<h&&nums[h]==nums[h+1]) h--;
                }
                else if(sum<-1*a) l++;
                else if(sum>-1*a) h--;
            }
            //I forgot this line too,like l and h, if we have considered a number as a
            //we need to move from tha index and then check for duplicates
            i++;
            //similar to l and h,to remove duplicates we are moving i
            // while(i<n-2&&i!=0&&nums[i]==nums[i-1]) i++;
            //that i!=0 check is not necesary as we are increasing i,it can never be 0
            while(i<n-2&&nums[i]==nums[i-1]) i++;
        }
        return res;
    }
};

// Java

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> al=new ArrayList<>();
        int n=nums.length;
        int i=0;
        while(i<n-2){
            int l=i+1,h=n-1;
            //a+b+c=a0,b+c=-1*a.
            int a=nums[i];
            while(l<h){
                int sum=nums[l]+nums[h];
                if(sum==-1*a){
                    al.add(Arrays.asList(nums[i],nums[l],nums[h]));
                    l++;
                    h--;
                    while(l<h&&nums[l]==nums[l-1]) l++;
                    while(l<h&&nums[h]==nums[h+1]) h--;
                }else if(sum<-1*a) l++;
                else h--;
            }
            i++;
            while(i<n-2&&nums[i]==nums[i-1]) i++;
        }
        return al;
    }
}