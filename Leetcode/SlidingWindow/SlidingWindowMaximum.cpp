// 239. Sliding Window Maximum
// Hard
// You are given an array of integers nums, there is a sliding window of size k 
// which is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. 
// Each time the sliding window moves right by one position.
// Return the max sliding window.
// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7


class Solution {
public:
     /* The intution for this ques has to be fully focused on the Aditya vema priciples for
    sliding window, so the idea is same as for finding the first negative number in 
    an subbarray of size k ,we create a list and store only the elements that will be usefull
    to us from the array, and simultaniously remove elements from the list that become not
    usefull in next cycles, all this is done in calculation part itself. we keep list such
    that max element of that window is at front, so while picking every nums[j]
    we will check and remove every number thats smaller than that nums[j] and insert it
    at back if the list, this maintains and decreaasing order of list,then fixed SW thing,
    the while deriving answer, we just need to push the front of list to answer, check if
    nums[i] is the maxif so the remove it from the list and sslide the window.*/
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size=nums.size();
        int i=0,j=0,max=INT_MIN;
        list<int> l;
        vector<int> res;
        while(j<size){
            //calculation part
            //this is wrong becs first we are checking same condition in if and while so
            //if is not nnecessary, and as mentioned above to remove all elements from the
            //list that are smaller than nums[j],instead of going from front we shloud go
            //back, bcs front is for max so for eg is the window is 3 1 2, while pushing
            //2 1 will never be removed , but in next slide window 1 will be shown as 
            //maximum but it's not 2 is maximum, so we should delete  all the elements 
            //smaller than 2 by looking from backand yeah check for list empty check too.
            
            // if(!l.empty()&&l.front()<nums[j]){
            //     while(!l.empty()&&l.front()<nums[j]) l.pop_front();
            
            while(!l.empty()&&l.back()<nums[j]) l.pop_back();
            
            l.push_back(nums[j]);
            
            //fixed SW thing
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                //answer from caculation
                res.emplace_back(l.front());
                //taking care of i ,checking if the element at i is the max element, if so 
                //then its removed from the list and sliding the window part
                if(nums[i]==l.front()){ l.pop_front();}
                i++;j++;
            }
        }
        return res;
    }
};