// 3. Longest Substring Without Repeating Characters
// Medium
// Given a string s, find the length of the longest substring without repeating 
// characters.
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Sliding window approach
        /*We take a map and store all the freq of the char,we do things similar to
        those anagram question or permutation question or k unique character question
        ,the map size will give use the number of ditinct charac,in k unique ques,we
        know we needed a map size of k,but here we need to apprach this question
        like largest subarray with all unique characters, so for all of them to be
        unique the map size need to be length of the subarray, that what we do here
        if subbarray length equals map size, that means all elements are unique,so
        chack if lenght is max  or not, if the map size is less than subbarray length,
        that means we have duplicate in the subarray, so we start erasing from
        the start that is i, unless the size becomes equal to subbarray, after that
        we again check if mpsize equals subarray lengght, if it is then we take max,
        then slid the window j++;*/
        
        int n=s.size(),i=0,j=0,mx=0,count=0;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()==j-i+1){
                mx=max(mx,j-i+1); j++;
            }else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) {mp.erase(s[i]);}
                    i++;
                }
                if(mp.size()==j-i+1) mx=max(mx,j-i+1);
                j++;
            }
        }
        return mx;
        
        //Another way is to use a set
        /* Take a set, traver array with start and end at 0, we traverse, we check if
        the encountered element is already present in the set, if it is then we 
        start removing element present from start of the index, that is i, untill
        the previous occurence of the current element is deleted,then all char
        in subarray will be unique ,so either this or if the current encountere
        element is not present in the set, then we insert it into set,then we check 
        for max, and then move j++(this wiil take care of both thigs, when subbarray
        becomes unique after emoval of i characters  and also of curr element is 
        unique*/
        unordered_set<char> st;
        int i=0,j=0,n=s.size(),mx=0;
        while(j<n){
            if(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }else{
                st.insert(s[j]);
                mx=max(mx,j-i+1);
                j++;
            }
        }
        return mx;
        
        //Another way is to use constant space that vector of size 256
        /* what we will do is ,in prev way we seen that when a duplicare element is
        encountered, then we remove the occurence at i then increeement i untill 
        the previous ocurence of the current encountered value is removed,instead
        what we can do is we can store the index of that array and then increament
        i to that index + 1 , but you would haave also noticed, when we do this
        we dont delete the inbetween characters index or delete then like in the 
        previous approach, so what we need to check is everytime we encounter a 
        duplicate or already present character, we check if its previous value is
        greater than i, if an only then we process it, else we dont need, as that 
        previous occured character will not be present in the current substring*/
        
        vector<int> mp(256,-1);
        int i=0,j=0,mx=0,n=s.size();
        while(j<n){
            if(mp[s[j]]!=-1){
                i=max(mp[s[j]]+1,i);
            }
            mp[s[j]]=j;
            mx=max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};