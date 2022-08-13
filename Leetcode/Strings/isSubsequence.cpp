// 392. Is Subsequence
// Easy
// Given two strings s and t, return true if s is a subsequence of t, 
// or false otherwise.
// A subsequence of a string is a new string that is formed from the 
// original string by deleting some (can be none) of the characters
// without disturbing the relative positions of the remaining characters.
// (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
// Example 1:
// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:
// Input: s = "axc", t = "ahbgdc"
// Output: false
// Example 3:
// Input: s = "", t = ""
// Output: true
// Example 4:
// Input: s = "", t = "ahbgdc"
// Output: true
// Example 5:
// Input: s = "abc", t = ""
// Output: false

// The idea is to take an index for s and iterate for t, as we traverse check 
// if char at t and s match ,if they do then increase the index of s, then check 
// if index of s is equal to size of s ,if it is then return true, after iterating
// all chars in t then return false.

CPP Code:
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ss=s.size(),ts=t.size();
        //in cpp we are not checking for string size 0 and all bcs the code below
        // itslef will take care of it, bcs s[j] here will give some garbage value or null
        //but explicitly checking size of string is more optimal ,ad code should not access
        //somethiing thats unecessary.
        if(ss==0&&ts==0) return true;
        if(ss==0&&ts>0) return true;
        if(ss>0&&ts==0) return false;
        int j=0;
        for(int i=0;i<ts;i++){
            if(s[j]==t[i]) j++;
            if(j==ss) return true;
        }
        return false;
    }
};
Java Code:

class Solution {
    public boolean isSubsequence(String s, String t) {
        int ss=s.length(),ts=t.length();
        //Unlike cpp here s.charAt(j) will throw error as out of bound or referece error
        //it will not give any garbage value.
        if(ss==0&&ts==0) return true;
        if(ss==0&&ts>0) return true;
        if(ss>0&&ts==0) return false;
        int j=0;
        for(int i=0;i<ts;i++){
            if(s.charAt(j)==t.charAt(i)) j++;
            if(j==ss) return true;
        }
        return false;
    }
}