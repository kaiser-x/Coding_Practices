// 1309. Decrypt String from Alphabet to Integer Mapping
// Easy
// You are given a string s formed by digits and '#'. We want to map s to English lowercase 
// characters as follows:
// Characters ('a' to 'i') are represented by ('1' to '9') respectively.
// Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
// Return the string formed after mapping.
// The test cases are generated so that a unique mapping will always exist.
// Example 1:
// Input: s = "10#11#12"
// Output: "jkab"
// // Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
class Solution {
public:
    string freqAlphabets(string s) {
        int n=s.size();
        string res="";
        //traversing from the last , checking if we encounter # or not.
        for(int i=n-1;i>=0;){
            if(s[i]!='#'){
                //we are subtracting by -1 bcs a starts from 1 here not 0
                res+=(char((s[i]-'0')+'a'-1));
                i--;
            }else{
                int x=stoi(s.substr(i-2,2));
                res+=(char(x+'a'-1));
                i=i-3;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
class Solution {
    public String freqAlphabets(String s) {
        int n=s.length();
        StringBuilder res=new StringBuilder("");
        for(int i=n-1;i>=0;){
            if(s.charAt(i)!='#'){
                //we are subtracting by -1 bcs a starts from 1 here not 0
                char ch=(char)(Integer.parseInt(s.substring(i,i+1))+'a'-1);
                res.append(ch);
                i--;
            }else{
                int x=Integer.parseInt(s.substring(i-2,i));
                res.append((char)(x+'a'-1));
                i=i-3;
            }
        }
        res.reverse();
        return res.toString();
    }
}