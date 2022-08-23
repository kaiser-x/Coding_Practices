// Longest K unique characters substring
// Easy
// Given a string you need to print the size of the longest possible substring 
// that has exactly K unique characters. If there is no possible substring then print -1.

// Example 1:
// Input:
// S = "aabacbebebe", K = 3
// Output: 7
// Explanation: "cbebebe" is the longest 
// substring with K distinct characters

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n=s.size(),i=0,j=0,max=-1;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()<k) j++;
            else if(mp.size()==k){
                int len=j-i+1;
                if(len>max) max=len;
                j++;
            }else if(mp.size()>k){
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                if(mp.size()==k) if(j-i+1>max) max=j-i+1;
                j++;
            }
        }
        return max;
    }
};