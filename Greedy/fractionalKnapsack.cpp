https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
import java.util.*;

class Item {
    int value, weight;
    Item(int v, int w) {
        value = v;
        weight = w;
    }
}

class Solution {
    double fractionalKnapsack(int W, Item[] arr, int n) {
        double ans = 0;

        // Sort by value/weight ratio descending
        Arrays.sort(arr, (a, b) -> {
            double r1 = (double) a.value / a.weight;
            double r2 = (double) b.value / b.weight;
            return Double.compare(r2, r1); // descending
        });

        for (int i = 0; i < n; i++) {
            if (arr[i].weight >= W) {
                double unit = (double) arr[i].value / arr[i].weight;
                ans += W * unit;
                break;
            }
            ans += arr[i].value;
            W -= arr[i].weight;
        }

        return ans;
    }
}