class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //this map ways is not working dont know why
        //i found out why,becuase there are let's say 3 distinct character is
        //pattern string,but there are 4 distinct characters in given string s
        //for example s = "cbaebabacd", p = "abc" ,,the op is[0,61]
        //at 1(op-0),2,3,4,5,6 window no problem, but 7th window where the op has to be
        //6 nothing is printed because,even thogh we are decreasing the mp[i],
        //the mp would be 1=1 b=1 c=1 e=0 d=0 and pmp a=1,b=1,c=1 ,and clearly 
        //mp !=pmp,so if mp[i]==0 we have to erase it.
       //  int n1=s.size();
       //  int k=p.size();
       //  int i=0,j=0;
       //  vector<int> res;
       // unordered_map<char,int>mp;
       // unordered_map<char,int> pmp;
       // for(int i=0;i<k;i++) pmp[p[i]]++;
       //  while(j<n1){
       //      mp[s[j]]++;
       //      if(j-i+1<k) j++;
       //      else if(j-i+1==k){
       //          if(mp==pmp) res.push_back(i);
       //          mp[s[i]]--;
       //  // corection line
       //  if(mp[s[i]]==0) mp.erase(s[i]);
       //          i++;
       //          j++;
       //      }
       //  }
       //  return res;
        
        //so we using a hash of vector
          int n1=s.size();
        int k=p.size();
        int i=0,j=0;
        vector<int> res;
       // map<char,int>mp;
       // map<char,int> pmp;
        vector<int> mp(26);
        vector<int> pmp(26);
       for(int i=0;i<k;i++) pmp[p[i]-'a']++;
        while(j<n1){
            mp[s[j]-'a']++;
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(mp==pmp) res.push_back(i);
                mp[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return res;
    }
};