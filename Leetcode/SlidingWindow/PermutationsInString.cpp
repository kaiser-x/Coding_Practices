// 567. Permutation in String
// Medium
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, 
// or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.
// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
// Constraints:
// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

CPP Code:

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //What approach we are trying is to follow sliding window tecnique, here the sliding
        // sliding window size  will be the size of s1.
        int k=s1.size();
        unordered_map<char,int> mp;
        //we take freq of all the elements in s1
        for(char c:s1) mp[c]++;
        //take the count of all the distinct elements in s1
        int count=mp.size();
        
        int i=0,j=0,n=s2.size();
        //starting the slid
        while(j<n){
            //here in calculation part we are trying to see if the char from s2 is present 
            //in the map
            if(mp.find(s2[j])!=mp.end()){
                //if it is preseent in the map then wwe reduce the freq by one as it is
                //encountered and canceled
                mp[s2[j]]--;
                //we check if the freq of the eelement became 0 , if it foes then we reduce
                //the count by 1, bcs the number of distinct elements has reduced by 1
                if(mp[s2[j]]==0) count--;
            }
            //if the window is not hit the keep moving forward
            if(j-i+1<k) j++;
            //when window is hit
            else if(j-i+1==k){
                //deriving answer from the calculation  part
                //we check if the count is 0, that is if all the elements of s1 have been
                //canceled out, and the number of distinct elements became 0,then return
                //true
                if(count==0) return true;
                
                //sliding the window part
                //Now before sliding the window we check if the leaving element is present in 
                //the map or not,if it does then we increase its freq, as it is gonna leave
                //the window
                if(mp.find(s2[i])!=mp.end()) {
                    mp[s2[i]]++;
                    //now we check if the previous freq of the leaving element was 0
                    //if it was then we increase the count by 1,as the number of distinct 
                    //element that needs to be canceled increased by 1
                    if(mp[s2[i]]==1) count++;
              }
                //then slide the window
                i++;j++;
            }
        }
        //if count never became 0 while hitting the window the return false;
        return false;
    }
};
//Another approach maintainin two maps for seeng if they are equal whenever we hit a window
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size(),k=s1.size();
        vector<int> hashs1(26,0);
        for(int i=0;i<k;i++) hashs1[s1[i]-'a']++;
        vector<int> hashs2(26,0);
        int i=0,j=0;
        while(j<n){
            hashs2[s2[j]-'a']++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(hashs1==hashs2) return true;
                hashs2[s2[i]-'a']--;
                i++;
                j++;
                
            }
        }
        return false;
    }
};

Java Code:

class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int k=s1.length(),n=s2.length();
        int i=0,j=0;
        HashMap<Character,Integer> hm=new HashMap<>();
        for(char c:s1.toCharArray()) hm.put(c,hm.getOrDefault(c,0)+1);
        int count=hm.size();
        while(j<n){
            if(hm.containsKey(s2.charAt(j))){
                hm.replace(s2.charAt(j),hm.get(s2.charAt(j))-1);
                if(hm.get(s2.charAt(j))==0) count--;
            }
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(count==0) return true;
                if(hm.containsKey(s2.charAt(i))){
                    if(hm.get(s2.charAt(i))==0) count++;
                     hm.replace(s2.charAt(i),hm.get(s2.charAt(i))+1);
                 }
                i++;j++;
            }
        }
        return false;
    }
}
```