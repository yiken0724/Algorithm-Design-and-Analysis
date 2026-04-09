import java.util.*;

public class implementationClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        System.out.println("How many types of items are there?: ");
        int n = sc.nextInt();
        Items[] items = new Items[n]; //an array storing items
        int [] w = new int[n];
        int [] p = new int[n];

        System.out.println("What is the maximum capacity of the Knapsack?: ");
        int C  = sc.nextInt(); 

        for (int i = 0; i < n; i++){
            System.out.println("Insert weight for item " + i + " (weight):");
            int a = sc.nextInt();
            System.out.println("Insert weight for item " + i + " (profit):");
            int b = sc.nextInt();
            items[i] = Knapsack.addItems(a,b);
            w[i] = a; //constructing w array
            p[i] = b; //constructing p array
        }

        Knapsack kn1 = new Knapsack (items, C);
        //recursive approach
        int max_profit_recur = kn1.knapsackRecursive(w, C, n);
        kn1.printProfit();

        Knapsack kn2 = new Knapsack (items, C);
        int max_profit_dp = kn2.knapsackDynamicProgramming (w, p, C, n);
        kn2.printProfit();
        
        sc.close();
    }
}
