class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long  l=min(a,b);
        long long int h=(long)n*min(a,b);
        int gcd;
        int A=a,B=b;
        while(B>0){
            int temp=A;
            A=B;
            B=temp%B;
        }
        gcd=A;
        int lcm=(a*b)/gcd;
        while(l<h){
            long long int mid=l+(h-l)/2;
            int number_of_divisors=(mid/a)+(mid/b)-(mid/lcm);
             if(number_of_divisors<n) l=mid+1;
            else h=mid;
        }
        return l%(1000000007);
    }
    
};