// Given two binary strings a and b, return 
// their sum as a binary string.

// Input: a = "11", b = "1"
// Output: "100"

// Input: a = "1010", b = "1011"
// Output: "10101"

class Solution {
public:
    string addBinary(string a, string b) {
        string s="";
        int i=a.size()-1,j=b.size()-1,carry=0;
        while(i>=0||j>=0||carry>0){
            // instead having while as while(1) and having this break if statement
            //just change the while loop to while(i>=0||j>=0||carry>0)
            // if(i<0&&j<0&&carry==0) break;
            int sum=0;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }
            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            sum+=carry;
            if(sum>1)
            carry=1;
            else
                carry=0;
            s+=sum%2+'0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
};