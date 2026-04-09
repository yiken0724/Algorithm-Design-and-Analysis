//normal insertionSort implementation based on lecture slides

public class insertionSort {
    public int iSort (int arr[]){
        int len = arr.length;
        int comparisons = 0;

        for (int i = 1; i < len; i++)
        {
            for (int j = i; j > 0; j--)
            {
                comparisons++; //when test case fail, there would also be a comparison
                if (arr[j] < arr[j-1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                } 
                else       
                    break;
            }
        }
        return comparisons;
    }
}