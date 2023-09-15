// TC = O(n)
// SC = O(1)

// Dutch National Flag Algorithm
/*
low, mid, high

arr[mid] == 
0 -> swap(arr[low], arr[mid]);
     mid++; low++;

1 -> mid++;

2 -> swap(arr[mid], arr[high]);
     high--;
*/


void sortArray(vector<int>& arr, int n)
{
    // Write your code here
    int low = 0, mid = 0, high = n-1;

    while(mid<=high)
    {
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            // mid++;
            high--;
        }
        else{
            mid++;
        }
    }
}