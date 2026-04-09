import java.util.*;

public class Knapsack {
    private Items[] items;
    private int C; //C is the maximum capacity
    private static int profit[][];
    public static final int INT_MIN = - 1;
    
    int n = items.length;
    Scanner sc = new Scanner(System.in);

    //constructor
    public Knapsack (Items[] items, int C){
        this.items = items;
        this.C = C;
        this.profit = new int[n][C+1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < C; j++) {
                if (i != 0 || j != 0)
                    this.profit[i][j] = INT_MIN;
                else {
                    this.profit[j][0] = 0;
                    this.profit[0][i] = 0;
                }
            }
        }
    }
    
    public static int knapsackRecursive(int[] w, int C, int n){ //not using memoization
        if (n == 0 || C == 0)
            return 0;
        else 
            return max (knapsackRecursive(w,C, n-1), knapsackRecursive(w, C - w[n], n-1) + w[n]);
    }

    public static int knapsackDynamicProgramming (int[] w, int [] p, int C, int n){ //using memoization
        for (int r = 1; r < C; r ++){
            for (int c = 1; c < n; c++){
                profit[r][c] = profit[r][c-1];
                if (w[c] <= r)
                {
                    int new_profit = profit[r-w[c]][c-1] + p[c];
                    if (new_profit > profit[r][c])
                        profit[r][c] = new_profit;
                }         
            }
        }
        return profit[n][C+1]; //bottom rightmost element
    }

    public static Items addItems (int weight, int profit){ //to add items into array
        return new Items (weight, profit);
    }

    private static int max (int a, int b){
        if (a >= b)
            return a;
        else
            return b;
    }

    public void printProfit(){
        for (int i = 0; i < profit.length; i++){
            var p = profit[i];
            for (int j = 0; j < p.length; j++)
                System.out.println(p[j] + " ");
            System.out.println();
        }
    }
}
