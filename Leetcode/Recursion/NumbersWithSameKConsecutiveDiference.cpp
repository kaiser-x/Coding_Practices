// 967. Numbers With Same Consecutive Differences
// Medium
// Return all non-negative integers of length n such that the absolute difference between 
// every two consecutive digits is k.
// Note that every number in the answer must not have leading zeros. For example, 01 has one 
// leading zero and is invalid.
// You may return the answer in any order.
// Example 1:
// Input: n = 3, k = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.
// Example 2:
// Input: n = 2, k = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

// CPP CODE:

class Solution {
public:
    /*I seriously have no idea how I got this question right, First what wee need to understand is this
    //question is similar to the Sequential digit, where we are given a range low and high and have to 
    return all the numbers that are each digit in the number is one more than the previous digit.
    so the difference between consecutive digits is 1,so the idea in that is to have a helper funtion that
    will recursively select the next element and check if it is in the range or not, if it is then
    we add it to result, if the number is higher than high then return, or if the next element is greater
    than 9 then return. now here we are given that instead of consecutive difference to be 1 here we have
    k, so same as sequential digit, we can set a loop for the first digit, then rest of the digit place
    can be filled recursivily, nw here we have to consider 9 unike sequential digits ques,so loop for 1 to
    9, then call helper function, now in hlper funtion base condition would be when number's length is 
    equal ton, then we add num to reslut vector, else we need to set the 2nd ,3rd and so on digit places
    ,for that we run a loop from 0 to 9, here 0 is included as the abs diff of k with 0 will be k, we 
    if there are any number from 0 to 9 that have abs diference of curent digit and i equal to k, if it
    does then call helper funtion with num updated as num*10+i, and current updated as i.,now we can 
    reduce the loop part, bcs if you notice carefully, at max only two i values are gonna have abs equal k
    curr-k and current+k,  so we check if current_digit-k>=0, if it is update num and curr and call 
    recursive helper, or if cur+k<10 the update and call helper, but theres a edge case, if k is 0, then
    both case will satisfy and answer will be inserted two time, to avoid is hae k!=0 condition in any
    of the two if's.*/
    //TC: O(n) and SC= O(n) for k<=4 as we will only do one call, 
    //TC: O(2^n) and SC: O(2^n) for k>=5 as we will do the  as we will make 2 recursive calls
    // NOTE: we are given n>=2 so we dont need to wory about return {} when we have n=1,this would not
    //have had any difference in dfs but in bfs we start from level 0 with all numbers from 1 to 9
    //and if n= 1 then we cant just return that arraay, bcs array gotta be empty.
    vector<int> res;
    void dfs(int num,int curr,int &k,int &n){
        if(to_string(num).size()==n){
            res.push_back(num); return;
        }
        //to set 2nd 3rd and so on digit places.
        // for(int i=0;i<=9;i++){
        //     if(abs(curr-i)==k)
        //     helper(num*10+i,i,k,n);
        // }
        //i found this condition on my own dude , i cant believe it, even the k!=0 i found on my own
        //the above conditon of abs(curr-i) will be satsified for only two times at max, curr+k and curr-k
        if(curr+k<10) dfs(num*10+(curr+k),curr+k,k,n);
        if(k!=0&&curr-k>=0) dfs(num*10+(curr-k),curr-k,k,n);
        //Note we can avoid storing curr, by using % operator to get the last digit of num.
        
    }
    vector<int> bfs(int n,int k){
        //BFS SOlution, will have sam TC and SC as dfs
        //the bfs idea is to first have we will have the numbers in level 1 as the numbes range from 1 to 9
        //we can have array of 1 to 9, then as we progress the levels we will add a new digit to it, 
        // ..untill we reach the number of digits to be n, then at the last the elements of array will
        // be those who satisfy the given conditions and we return that array as answer.
        /*For bfs we can have have the similar for loop that runs from 0 to 9 while selecting the next 
        digit for num, but as we discussed earlier there can only be two possiblities curre_digit+k
        and curr_digit -k, if they are in range of 0 to 9 then we can add them to the list and update the 
        new list to previous list, we do this n times.*/
        //again we are checking for k!+0 only bcs it is an edge case, if k==0, both if will be satisfied
        //and we will have duplicates in the answer teach element will occur twice, to avoid this we
        //are putting the condition k!=0 in any one of the two if's.
            vector<int> nums={1,2,3,4,5,6,7,8,9};
            for(int i=2;i<=n;i++){
                vector<int> inter;
                for(int ele:nums){
                    int curr_digit=ele%10;
                    if(curr_digit+k<10) inter.push_back(ele*10+curr_digit+k);
                    if(k!=0&&curr_digit-k>=0) inter.push_back(ele*10+curr_digit-k);
                }
                nums=inter;
            }
        return nums;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        //dfs
        // for setting first digit and calling recursive call to set other digit places.
        for(int i=1;i<=9;i++)
            dfs(i,i,k,n);
        return res;
        
        //bfs 
        return bfs(n,k);
        
    }
};

// Java CODE:

class Solution {    
    static void dfs(int num,int k,int n,List<Integer> al){
        if(String.valueOf(num).length()==n){
            al.add(num);
            return;
        }
        int curr_tail=num%10;
        //is current_tail -k is greater means we are at a point where we need to reduce curr_tail value by
        //k in ordere to get k consecutive difference.
        if(curr_tail-k>=0) dfs(num*10+(curr_tail-k),k,n,al);
        if(k!=0&&curr_tail+k<10) dfs(num*10+(curr_tail+k),k,n,al);
    }
    static int[] bfs(int n,int k){
        //since we cant initialize an arraylist we will use an array and its property array as list
        List<Integer> nums=Arrays.asList(1,2,3,4,5,6,7,8,9);
        for(int i=2;i<=n;i++){
            List<Integer> inter=new ArrayList<>();
            //you could use int ele too, java will do its boxing thing
            for(Integer ele:nums){
                //curr digit or curr tail both same we need last digit
                int curr_digit=ele%10;
                if(curr_digit+k<10) inter.add(ele*10+curr_digit+k);
                if(k!=0&&curr_digit-k>=0) inter.add(ele*10+curr_digit-k);
            }
            nums=inter;
        }
        return nums.stream().mapToInt(i->i).toArray();
    }
    public int[] numsSameConsecDiff(int n, int k) {
        //dfs
        List<Integer> al=new ArrayList<>();
            for(int i=1;i<=9;i++) dfs(i,k,n,al);
        return al.stream().mapToInt(ele->ele).toArray();
        //bfs
        return bfs(n,k);
        
    }
}