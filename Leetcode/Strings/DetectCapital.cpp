// 


class Solution {
public:
    bool detectCapitalUse(string s) {
      int n=s.size();
      int cap=0,small=0;
      int first=(s[0]>='A'&&s[0]<='Z')?1:0;
      for(int i=0;i<n;i++){
        if(s[i]>='A'&&s[i]<='Z')
            cap++;
        else
          small++;
      }
      return (cap==n)||(small==n)||(first==1&&small==n-1);
    }
};