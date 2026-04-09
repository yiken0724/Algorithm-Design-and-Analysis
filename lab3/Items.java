public class Items {
    private int weight;
    private int profit;

    //constructor
    public Items (int weight, int profit) {
        this.weight = weight;
        this.profit = profit;
    }

    //getter and setter
    public int getWeight() {
        return this.weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getProfit() {
        return this.profit;
    }

    public void setProfit(int profit) {
        this.profit = profit;
    }
}
