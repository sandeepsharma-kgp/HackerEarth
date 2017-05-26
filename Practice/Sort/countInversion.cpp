#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18



ll _merge(ll arr[], ll l, ll m, ll r)
{
    ll cnt=0;
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;

    /* create temp arrays */
    ll L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] > R[j])
        {
            arr[k] = R[j];
            j++;
            cnt=cnt+n1-i; ////// IMPORTANT POINT USED IN COUNTING

        }
        else
        {
         arr[k] = L[i];
            i++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return cnt;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
ll mergeSort(ll arr[], ll l, ll r)
{
    ll lc=0,rc=0,cnt=0;
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        ll m = l+(r-l)/2;

        // Sort first and second halves
        lc= mergeSort(arr, l, m);
        rc=mergeSort(arr, m+1, r);

        cnt=_merge(arr, l, m, r);
    }
    else
        return 0;

    return(cnt+lc+rc);
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
//void printArray(int A[], int size)
//{
//    int i;
//    for (i=0; i < size; i++)
//        printf("%d ", A[i]);
//    printf("\n");
//}

/* Driver program to test above functions */
int main()
{
//    int arr[] = {12, 11, 13, 5, 6, 7};
//    int arr_size = sizeof(arr)/sizeof(arr[0]);
//
//    printf("Given array is \n");
//    printArray(arr, arr_size);
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    ll cnt=mergeSort(arr, 0, n - 1);
    cout<<cnt;
//    printf("\nSorted array is \n");
//    printArray(arr, arr_size);
    return 0;
}
