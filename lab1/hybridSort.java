

public class hybridSort {
    public int hSort(int arr[], int S){ //S is the threshold
        int length_arr = arr.length;
        int comp = 0;
        if (length_arr <= S){
            comp = insertionSort.iSort(arr);
        }
        else
            comp = mergeSort.mSort(0,length_arr-1,arr);
        
        return comp;
    }
}