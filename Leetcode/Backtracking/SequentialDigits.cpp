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
// Cpp Code:

class Solution {
public:
    //we check for k bcs when prev digit is 9 then adding 10 to it will not work,and will give wrong answers
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
    //it is bcs we need to add the answer where the last digit is 9, so when if base_if is above
    //and we have condition that k>9, the answer where last digit is 9 will not be pushed in res,
    //so we need k>10, and when range_if is above  the we check if k>9 then return, bcs k>10 will
    //give redundant answer where coonsecutive digits will not have difference of 1, but answer would be
    //in range, as we are inserting the answer then checking the base case.
    void dfs(int n,int &l,int &h,int k, vector<int> &ans){
         /*now we can check if num is in range or not ,if it is then we add it, we will not return, bcs
        imagine for example range is 100 3000, now 234 is 3 digit number so even if we return, bcs
        of bacracking all the numbers between 100 to 999 wil be formed, but 1000 to 3000 will not be
        formed, so we dont return , instead we can check if num is out of range or the next digit is
        greater than 9, in either case we can return but not when num is in range.*/
        // if(n>h|| k>10) return ;
        if(n>=l&&n<=h) 
            ans.push_back(n); 
        if(n>h|| k>9) return ;
        dfs(n*10+k,l,h,k+1,ans);
    }
    void bfs(int low,int high,vector<int> &ans){
        //we can only have 1 to 8 as starting digit of the number, first loop to set the stating digit
        //lowest low value is 10 and also because 10 is two digit number so we cant realy make it a single
        //digit numver and say 10 is 1 more than 9.
        for(int i=1;i<9;i++){
            //we need the current digit to be 1 more than the previous digit, so we start the loop from
            //i+1, bcs only then that condition will be satisfied, this loop is to set the  2nd the 3rd and
            //so forth digits untill the num doesnt cross high range.
            //digits other than starting can have 9
            int num=i;
            for(int j=i+1;j<10;j++){
                num=num*10+j;
                if(num>=low&&num<=high) ans.push_back(num);
                if(num>high) break;
            }
        }
    }
    vector<int> sequentialDigits(int low, int high) {
         vector<int>ans;
        //dfs
        for(int i=1;i<9;i++)
            dfs(i,low,high,i+1,ans);
        //bfs
        bfs(low,high,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// Java Code:

class Solution {
    static List<Integer> al=new ArrayList<>();
    static void dfs(int num,int low,int high,int next,List<Integer> al){
        /*now we can check if num is in range or not ,if it is then we add it, we will not return, bcs
        imagine for example range is 100 3000, now 234 is 3 digit number so even if we return, bcs
        of bacracking all the numbers between 100 to 999 wil be formed, but 1000 to 3000 will not be
        formed, so we dont return , instead we can check if num is out of range or the next digit is
        greater than 9, in either case we can return but not when num is in range.*/
        if(num>=low&&num<=high) al.add(num);
        if(num>high||next>9) return;
        //Basic math, number *10 +reminder, then for creating next element we have curr_next+1.
        dfs(num*10+next,low,high,next+1,al);
    
    }
    static void bfs(int low,int high, List<Integer> al){
        //we can only have 1 to 8 as starting digit of the number, first loop to set the stating digit
        //lowest low value is 10 and also because 10 is two digit number so we cant realy make it a single
        //digit numver and say 10 is 1 more than 9.
        for(int i=1;i<9;i++){
            //we need the current digit to be 1 more than the previous digit, so we start the loop from
            //i+1, bcs only then that condition will be satisfied, this loop is to set the  2nd the 3rd and
            //so forth digits untill the num doesnt cross high range.
            //digits other than starting can have 9
            int num=i;
            for(int j=i+1;j<10;j++){
                num=num*10+j;
                if(num>=low&&num<=high) al.add(num);
                if(num>high) break;
            }
        }
    }
    public List<Integer> sequentialDigits(int low, int high) {
         List<Integer> al=new ArrayList<>();
        /*this for loop is for settign the first number, the next digits numbers can be fixed by
        adding 1 to the current digit, as then only we will have consecutive digits difference as 1
        so we dont need a loop to set digits in the helper funtion, we dont include 9 bcs 9's next number
        is 10, 10 is not a single digit and cant be considered ,so 9 is omitted in consideration of 
        posible first digit, but 9 can happen in other digit place,8+1 wll give 9, so recursivily
        9 can happen.*/
        //dfs
        for(int i=1;i<9;i++) dfs(i,low,high,i+1,al);
        //bfs
        // bfs(low,high,al);
        Collections.sort(al);
        return al;
    }
}
