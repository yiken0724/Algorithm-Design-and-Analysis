//normal mergeSort implementation based on lecture slides

public class mergeSort {

    private int total_comp;

    public int mSort (int n, int m, int arr[]){
        int comparisons = 0;
        int mid = (n+m)/2;
        if (m-n <= 0)
            return comparisons;
        else if  (m - n > 1)
        {
            int a = mSort(n, mid, arr);
            int b = mSort(mid + 1, m, arr);
            total_comp = a+b;
        }
        merge(n,m,arr);
        return total_comp;
    }

    public int merge(int n, int m, int arr[]){ //n is the initial index, m is the last index
        int comparisons = 0;
        int mid = (n+m)/2;
        int a = n;
        int b = mid + 1;
        int temp, i;
        
        if (n-m <= 0)
            return comparisons;       
        
        while ( a<= mid && b <= m){
            comparisons ++;
            if (arr[a] > arr[b])
            {
                temp = arr[b++];
                for (i = ++mid; i > a; i--)
                {
                    arr[i] = arr[i-1];
                    arr[a++] = temp;
                }    
            }
            else if (arr[a] < arr[b])
            {
                a++;
            }
            else if (arr[a] == arr[b])
            {
                if (a == mid && b == m)
                    break;
                temp = arr[b++];
                a++;
                for (i = ++mid; i > a; i--)
                    arr[i] = arr[i-1];
                arr[a++] = temp;
            }
        }
        return comparisons;
    }
}
