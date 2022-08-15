
void sort012(int arr[], int n)
{
    int low=0,mid=0,high=n-1,t=0;
    while(mid<=high){
        if(arr[mid]==0){
            t=arr[low];
            arr[low]=arr[mid];
            arr[mid]=t;
            low++;
            mid++;
        }
        else if(arr[mid]==1)
            mid++;
        else{
            t=arr[mid];
            arr[mid]=arr[high];
            arr[high]=t;
            high--;
        }
    }
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}