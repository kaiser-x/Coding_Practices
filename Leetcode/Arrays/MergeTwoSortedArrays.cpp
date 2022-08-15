Cpp Code:

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        /*The Idea is to fill the first array from back, so we iterate from the back of both 
        array and see which one is greater then insert that at the back of first array*/
        
        //The first while loop will take care of possiblities when first array is larger than
        //second array adn if they are equal
        while(i>=0&&j>=0){
            if(A[i]>B[j]){
                A[k--]=A[i];
                i--;
            }else {
                A[k--]=B[j];
                j--;
            }
        }
        //this loop is to take care of left over elements if second array is larger than first
        //array
        while(j>=0) A[k--]=B[j--];
    }
};

Java Code:

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>nums2[j]) nums1[k--]=nums1[i--];
            else nums1[k--]=nums2[j--];
        }
        while(j>=0) nums1[k--]=nums2[j--];
    }
}