// 125. Valid Palindrome
// Easy
// A phrase is a palindrome if, after converting all uppercase letters into 
// lowercase letters and removing all non-alphanumeric characters, it reads 
// the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.
// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

class Solution {
public:
    //Here we used reference variable so changes in str will reflect on s
    void tolower(string &str){
        int n=str.size();
        for(int i=0;i<n;i++){
            if(str[i]>='A'&&str[i]<='Z') str[i]=str[i]+32;
        }
    }
    bool faltuchar(string str){
        string s1="";
        int n=str.size();
        for(int i=0;i<n;i++){
            if((str[i]>='0'&&str[i]<='9')||(str[i]>='a'&&str[i]<='z'))
                s1+=str[i];
        }
        int m=s1.size();
        int i=0;
        while(i<m/2){
            if(s1[i]!=s1[m-i-1]) return false;
            i++;
        }
        return true;
        
    }
    bool isPalindrome(string s) {
        //1st approach
        tolower(s);
        return faltuchar(s);
        
        //Simple approach is to use 2 pointers
        // This toupper and tolower method will not work now, as the specifics of those methods have been changed, the methods return type is void now, so we can not compare two voids, If (toupper(s[i]) != toupper(s[j])) return false; ``` ,will not work, now method argument is like this, ```void tolower(string &str)```, the datatype is string and its a reference variable so we can not like pass to_string(s[i]) to tolower funtion, as to_string(s[i]) will create string in temporary space , and reference variable can not point towards a temporary memory, so it throws non const l value error, instead what we have to do is convert s[i] and s[j] to string store it in variable then call tolower function on both of them, then compare if variable are same or not.
int l=0,h=s.size()-1;
        while(l<h){
            while(l<h&&!isalnum(s[l])) l++;
            while(l<h&&!isalnum(s[h])) h--;
            string x=s.substr(l,1),y=s.substr(h,1);
            tolower(x);tolower(y);
            if(x!=y) return false;
            l++;
            h--;
        }
        return true;
    }
};