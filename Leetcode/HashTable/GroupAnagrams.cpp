// 49. Group Anagrams
// Medium

// Given an array of strings strs, group the anagrams together. You can return the answer 
// in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different 
// word or phrase, typically using all the original letters exactly once.
// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:
// Input: strs = [""]
// Output: [[""]]
// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        /*The first approach you should say to interviewer is the brute force approach,here we know the 
        strings consist of only lowecase english allphabet, so we can make use of the count 26 array kind
        of map or hash,but what is required, we need to group all anagrams ,so what we do is, we iterate
        throught the vectors of string,that is i loop, then we make count hash for chars in string at ith 
        index,now we run a loop, j from i to n, then we create hash for all the strings in j loop, then 
        compare the tow hashes of ith string and jth string,if they are equal then we add em to the group
        ,then after j loop, add the grp vector into res vec, now the problem with this is,we add the first
        anagram in rder from the group, but again the second or third occuring anagram from any group
        will again be recognized by the i loop, and again it will create a new gropu and insert all the
        string that are anagram ahead of it in the vector,to avoid this we use set, to see if a string has
        already been used to check for anagrams in the vector, if it is then we iterate forwad,else we 
        do the j loop, and while checking if two hashes are equal and adding them to grp, we add the
        strin into grp as they are already became a anagram grp, and we dont need to grp them again in
        i loop, but the issue now is thiis approach will throw, TLE, as it is an O(n^2) solution*/
        
        //O(n^2) for loop, O(d) to make c2 hash, O(k) for creating c3 hash, O(1) in c1 c2 equality
        //check when c1 length is not same as c2 length, O(d) when length are same.
        //TC O(n^2)+O(d)+O(k)+O(d)
        //this method paases 111/117 test cases, now we need to reduce time complexity or the number of
        //comparisons.
        int n=str.size();
        if(n==0) return {{""}};
        vector<vector<string>> res;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(!st.empty()&&st.find(i)!=st.end()) continue;
            vector<string> grp;
            vector<int> c1(26,0);
            for(char c: str[i]) c1[c-'a']++;
            for(int j=i;j<n;j++){
                vector<int> c2(26,0);
                for(char c: str[j]) c2[c-'a']++;
                if(c1==c2) {grp.push_back(str[j]);st.insert(j);}
            }
            res.push_back(grp);
        }
        return res;
        //The 2nd approach is to use the ssort to make anagram group, but hashmap to sorted
        //string as key and they all sorted string equal to this as a value in vector of string
        //this is useful to remove the j loop;
        //Idea is to take a string str[i], store it in a strin variable s, sort s,then cheak if it
        //is present in the map, if it is the pushback str[i] in mp[i] key vector of string,
        //if not present then add the s as key and str[i] as value, see the sorted string s is the key.
        //then iterate map and add all value to the res vector
        //TC O(n) to loop the str,O(dlogd) to sort a string, di is size of string, the O(k) for 
        //traversing map and add value to res, k is map size, or number of anagram groups.
        //TC: O(n*dlogd)
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        int n=str.size();
        if(n==0) return {{""}};
        for(int i=0;i<n;i++){
            string s=str[i];
            sort(s.begin(),s.end());
            if(mp.find(s)!=mp.end()) mp[s].push_back(str[i]);
            else mp[s]={str[i]};
        }
        for(auto i=mp.begin();i!=mp.end();i++) res.push_back(i->second);
        return res;
        
        //To reduce that logd in above solution and make it d, we can make use of one of the important
        //constraints give, i.e, the chars are lower case english leter,so we make use of count 26 hash
        //and use that count itself as the key.
        // unordered_map<vector<int>,vector<string>> mp;
        // NOTE: You cant create unordered_map with vector<int> as a key, because unordered map works
        //with hash and it cant hash vector<int> ,for this we will need to create a custom hash func.
        //instead we can use map which uses red black tree, but it will take log(size of map) for all
        //operations
        // map<vector<int>,vector<string>> mp;
        
        //now the easy thing to do is using counting sort, create count hash 26, then iterate it and sort
        //string then store the string as ket, this way that log d will be removed, and 
        //TC : O(n*d*26); 26 for creating sorted string
        int n=str.size();
        if(n==0) return {{""}};
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(int i=0;i<n;i++){
            vector<int> count(26,0);
            for(char c:str[i]) count[c-'a']++;
            string s;
            for(int j=0;j<26;j++) 
                if(count[j]!=0) 
                    //first argument how many times, second argument ascii code for the char
                    s+=string(count[j],j+'a');
            if(mp.find(s)!=mp.end()) mp[s].push_back(str[i]);
            else mp[s]={str[i]};
        }
        for(auto i: mp) res.push_back(i.second);
        return res;
    }
};