class Solution {
public:
    //just like majority element 1,but here we are facing floor(n/3), so at min there can
    //be 0 elements or at max 2 elements that can have freq over floor(n/3);
    vector<int> majorityElement(vector<int>& arr) {
        int n1,n2,c1=0,c2=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==n1) c1++;
            else if(arr[i]==n2) c2++;
            else if(c1==0) {
                n1=arr[i];
                c1=1;
            }
            else if(c2==0){
                n2=arr[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        cout<<n1<<" "<<n2<<endl;
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==n1) c1++;
            else if(arr[i]==n2) c2++;
        }
        vector<int>res;
        cout<<c1<<" "<<c2<<endl;
        if(c1>n/3) res.push_back(n1);
        if(c2>n/3) res.push_back(n2);
        return res;
    }
};