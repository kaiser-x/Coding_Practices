// 1291. Sequential Digits
// Medium
// An integer has sequential digits if and only if each digit
//  in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range 
// [low, high] inclusive that have sequential digits.

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]

//sequential digit so after one theres one choice only thats 2
//similar for all numbers till8 but for 9 10 is not option
//so take each number from 1 to 9 and generate sequential digit and
// check it the are in the range,if they are add em to answer,if its less 
// than low range or inbetween range call the recursive call for next
//sequential digit is made ,if num is greater than high range then just
//return 
class Solution {
public:vector<int>ans;
    // void helper(int n,int &l,int &h,int k){
    //     if(k==11) return;
    //     if(n<l) helper(n*10+k,l,h,k+1);
    //     else if(n>=l&&n<=h) {
    //         ans.push_back(n);
    //         helper(n*10+k,l,h,k+1);
    //     }else if(n>h) return ;
    // }
    // vector<int> sequentialDigits(int low, int high) {
    //     for(int i=1;i<9;i++)
    //         helper(i,low,high,i+1);
    //     sort(ans.begin(),ans.end());
    //     return ans;
    // }
    
    //optimal way,if start from 1 like nums as 1
    //  void helper(int n,int &l,int &h,int k){
    //      if(n>h|| k>10) return ;
    //      if(n>=l&&n<=h) 
    //         ans.push_back(n);    
    //         helper(n*10+k,l,h,k+1);
    // }
    // vector<int> sequentialDigits(int low, int high) {
    //     for(int i=1;i<9;i++)
    //         helper(i,low,high,i+1);
    //     sort(ans.begin(),ans.end());
    //     return ans;
    // }
    
    //optimal way if you start from 0 like num as 0
    //and also if you put base case above the if case of checking range
    //then we need to use k>10 if range if above and 
    //base if down then k>9 needs to be used
    void helper(int n,int &l,int &h,int k){
        if(n>=l&&n<=h) 
            ans.push_back(n); 
         if(n>h|| k>9) return ;
        helper(n*10+k,l,h,k+1);
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<9;i++)
            helper(0,low,high,i);
        sort(ans.begin(),ans.end());
        return ans;
    }
};