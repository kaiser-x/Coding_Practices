205. Isomorphic Strings
Easy
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character 
while preserving the order of characters. No two characters may map 
to the same character, but a character may map to itself.
Example 1:
Input: s = "egg", t = "add"
Output: true
Example 2:
Input: s = "foo", t = "bar"
Output: false
Example 3:
Input: s = "paper", t = "title"
Output: true
Input: s = "egd", t = "add"
Output: false


CPP Code:

class Solution {
public:
    //This question is related to word pattern
   /* So the basic ideea is to map char from s at an index(which will be key) to respective
    char at index in t(which will acct as value), and iterate, if key doesnt not exist then
    create key and map the value, if key is present then check if value is same as char 
    at t[i],if not then return false */
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        //But if we follow the above procedure with normal single map, it will fail
        /* For eg: s=egg, t= add, e not present in map so insert e->a in map, g not present
        in map, g->d insert in map, then g is present in map, check if mp[g]==t[i],d==d,true
        so at last will return true;
        Now we take s=egh,t=add, same e->a, g->d then h is also not present in map so h->d,
        but d is already a value for a key so we need to return false, here expected is false
        but output produced is true,so when s[i] is not present in map, before inserting
        into map we need to check if t[i] is a value for any key or not, to check that in
        cpp it will take few extra unnecesory time,but we can check if map contains value
        or not in java hashmap though*/
        unordered_map<char,char> mp;
         for(int i=0;i<n;i++){
             if(mp.find(s[i])!=mp.end()){
                 if(mp[s[i]]!= t[i]) return false;
            }else {
                 mp[s[i]]=t[i];
             }
         }
         return true;
        
        /*So instead of creating a single map and assigning key as s[i] and value as t[i],
        we have to create two maps for s and t,map of size 256 as all ascii chars are
        valid, and for each map key will be s[i] and t[i], but value will be common, it can
        anything that is unique for each set of s[i] and t[i], so that we dont have direct
        link but indirect link, in this case we have taken index itself as unique value,
        this type of two map allows us to check if value is already present when key is not
        present in the map like above discussed, but it will not be necessary here, as we 
        are not checking if key is present or not in map then map key's value is to t[i]
        or not, we are not checking those, instead we are directly checking the contens of
        two maps with s[i] and t[i], and see if they point to same number/index or not,to 
        reduce code and avoid checking if s[i] and t[i] are present in respective map or
        not ,we just dill map with -1,(here map is actualy a vector,but we can use a 
        unordered map too, but then we will have to check if key exists or not), instead
        we directly check if both keys point to same number/index or not, and if its first key
        entry then it does not return false as we filled map with -1.
            
        So yeah, have two vectors for s and t of size 256, each filled with -1, iterate,
        check if each map with respective key as s[i] and t[i] have same value or not,
        if they dont then return false, if the do then assign.overwrite the value as index,
        if iterated fully then return true.*/
        
        
        vector<int> sm(256,-1),tm(256,-1);
        for(int i=0;i<n;i++){
            if(sm[s[i]]!=tm[t[i]]) return false;
            else {
                sm[s[i]]=tm[t[i]]=i;
            }
        }
        return true;
         //another approach is to have a Set that will check if the value is present or not
        //whenever a key is not present and we have to map key to value aand before that we
        //have to check if that value is already a value for a key or not
        
        unordered_map<char,char> mp;
        unordered_set<char> valuesSet;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i]) return false;
            }else{
                if(valuesSet.find(t[i])!=valuesSet.end()) return false;
                mp[s[i]]=t[i];
                valuesSet.insert(t[i]);
            }
        }
        return true;
        
    }
};

Java Code:

class Solution {
    public boolean isIsomorphic(String s, String t) {
        int ss=s.length(),ts=t.length();
        /*So in here we can map s[i] as key and t[i] as value in single map, as we can
        check if map contains value i.e t[i] or not whenever the key i.e s[i] is not
        preseent in the map*/
        HashMap<Character,Character> hm=new HashMap<>();
        for(int i=0;i<ss;i++){
            if(hm.containsKey(s.charAt(i))){
                if(hm.get(s.charAt(i))!=t.charAt(i)) return false;
            }else{
                if(hm.containsValue(t.charAt(i))) return false;
                hm.put(s.charAt(i),t.charAt(i));
            }
        }
        return true;
        
    }
}