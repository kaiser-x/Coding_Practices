// Smallest distinct window
// Medium
// Given a string 's'. The task is to find the smallest window length that contains all the 
// characters of the given string at least one time.
// For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.
// Example 1:
// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"
// Example 2:
// Input : "aaab"
// Output : 2
// Explanation : Sub-string -> "ab"

int findSubString(string s)
    {
        /*The idea is to find the number of distinct chars in the string, we need atleast one of each distinct
        char in our substring, but we need the one with the minimum length, so once we hit the windo we will
        start reducing window size from the left.So we take the total number of distinct chars, then we have 
        a frequency vector of size 256, as all chars are alphabetts of lower an uppercase,after fidniding total
        distinct chars, we iterate over the string, and we have a current_distinct chars number set to 0, as
        we iterate we we increase the corresponding frequency, but if the freq set is one that means it is a 
        new char that was not previously present in the substring, then we increase current_distinct with 1,
        then we check if the current_distict is equal to total_distinct, if it is ,that means we have hit the
        first substring where we have at least one char of all the distinct char in string s,but we need
        minimum length so we will start removing the char at i if their freq is greater than 1, we keep on 
        doing that untill we find a char whose freq is 1, that means that particular char has only 1 occurence
        in that substring,so we we remove that then distinct char who have freq at least one will be reduced
        ,thats why we stop at the first time itself when a char of freq with 1 is encountered while reducing
        length from left side. now if you imagine, once we hit the window where we have at least one occurence
        of each distinct char in string, then when we move ahead we will still have atleast one occurence of each
        char, and we only delete from left till we encounter a char which has atleast 1 freq. so once the 
        current_distinct is equal to total_distinct window is hit, we keep hitting the window every time we move
        j.*/
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        int total_distinct=mp.size(),current_distinct=0;
        int i=0,j=0,n=s.size(),mn=INT_MAX;
        //for marking frequency and calculating current distinct
        vector<int> vis(256,0);
        while(j<n){
            vis[s[j]]++;
            //if vis is 1 that means a new char has entered the substring and the current number of distinct 
            //char is increased by 1. so we increase current_distinct
            if(vis[s[j]]==1) current_distinct++;
            //if current is equal to total that means we have hit the window
            if(current_distinct==total_distinct){
                //as we need minimum window, we remove redundant or unwanter chars from left untill we
                //encounter a element thaat has freq as 1
                while(vis[s[i]]>1) {
                    vis[s[i]]--;
                    i++;
                }
                mn=min(mn,j-i+1);
            }
            j++;
        }
        return mn;
    }