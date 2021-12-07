
#include<bits/stdc++.h>
using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i*2-1;j++){
//             if(j&1) cout<<i;
//             else cout<<"*";
//         }
//         cout<<endl;
//     }
//     for(int i=n;i>=0;i--){
//         for(int j=1;j<=i*2-1;j++){
//             if(j&1) cout<<i;
//             else cout<<"*";
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     int k=n,l=n;
//     for(int i=1;i<=n;i++){
//         l=n;
//         for(int j=1;j<=n;j++){
//             if(j==k) cout<<"*";
//             else cout<<l;
//             l--;
//         }
//         k--;
//         cout<<endl;
//     }
// }
vector<bool> isprime(10000008, true);
int main(){
    int n;
    cin>>n;
    for(int i=2;i*i<=10000008;i++){
        if(isprime[i]==true){
            for(int j=i*i;j<=10000008;j+=i){
              isprime[j]=false;
            }
        }
    }
vector<int> arr[10008];
int k=0;
    for(int i=1;i<=n;i++){
        if(n%i==0)
            arr[k++].push_back(i);
    }
    int prod=1;
    for(int i=0;i<arr.size();i++){
        int count=0;
        if(isprime(arr[i]))
            {
                for(int j=0;j<arr.size();j++ ){
                    if(arr[i]%arr[j])
                        count++;
                }
                prod*=count;
            }  
    }
    cout<<prod%10000003;
}