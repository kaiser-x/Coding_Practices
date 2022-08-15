pp Code:

//NOTE: How many numbers can occur more than n/2 times in an array? 
//Only one. Either its there or not, that is number of majority element is
//either min:0 or max:1 .
// moore's algorithm, we see a element as the candidate and havee a count 
//variable that counts its freq, and iterate further and check if elements are 
//same as candidate or not, if they are then increase count if not the decreasse
//count, if count becomes 0 then take the incoming element as the candiate and
//continue the process,it works because if we mark all the place where the count 
//becomes 0, if we see those subarrays, the number of majority elements and 
//minority elements are same, so for example let;s say bcs of count 0 we have 
//4 subarrays, if in the question its given that there will be mandatory majority element then att the ened of the iteration the candidate will have the majority element, bcs 3 of 4 subarrays will have majority=minority, and if there
//is for sure a majority element then it must be the majority element in tha last
// subarray that is 4th subarray, but in question its given there can be 0
//majority element too, then at the end of the iteration we need to iterate
//arraay again and see if that candidate occurs more than n/2 times or not.
class Solution {
public:
    //just like majority element 1,but here we are facing floor(n/3), so at min there can
    //be 0 elements or at max 2 elements that can have freq over floor(n/3);
    vector<int> majorityElement(vector<int>& arr) {
        int n1,n2,c1=0,c2=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==n1) c1++;
            else if(arr[i]==n2) c2++;
            else if(c1==0) {
                n1=arr[i];
                c1=1;
            }
            else if(c2==0){
                n2=arr[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        cout<<n1<<" "<<n2<<endl;
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==n1) c1++;
            else if(arr[i]==n2) c2++;
        }
        vector<int>res;
        cout<<c1<<" "<<c2<<endl;
        if(c1>n/3) res.push_back(n1);
        if(c2>n/3) res.push_back(n2);
        return res;
    }
};

Java Code:

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n=nums.length;
        int n1=0,n2=0,c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==n1) c1++;
            else if(nums[i]==n2) c2++;
            else if(c1==0) {
                n1=nums[i];
                c1=1;
            }else if(c2==0){
                n2=nums[i];
                c2=1;
            }else {
                c1--;
                c2--;
            }
        }
        c1=0;c2=0;
        for(int i:nums){
            if(i==n1) c1++;
            else if(i==n2) c2++;
        }
        List<Integer> res=new ArrayList<Integer>();
        if(c1>n/3) res.add(n1);
        if(c2>n/3) res.add(n2);
        return res;
    }
}