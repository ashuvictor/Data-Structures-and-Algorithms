
Print all possible combinations of r elements in a given array of size n
Difficulty Level : Hard
Last Updated : 19 Jan, 2022
 
Given an array of size n, generate and print all possible combinations of r elements in array. For example, if input array is {1, 2, 3, 4} and r is 2, then output should be {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4} and {3, 4}.
Following are two methods to do this. 

https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

// C++ Program to print all combination of
// size r in an array of size n
public class Main {

    static void combinationUtil(int[] arr, int n, int r,
                                int index, int[] data, int i) {

        // combination ready
        if (index == r) {
            for (int j = 0; j < r; j++)
                System.out.print(data[j] + " ");
            System.out.println();
            return;
        }

        // no more elements
        if (i >= n) return;

        // include current
        data[index] = arr[i];
        combinationUtil(arr, n, r, index + 1, data, i + 1);

        // exclude current
        combinationUtil(arr, n, r, index, data, i + 1);
    }

    static void printCombination(int[] arr, int n, int r) {
        int[] data = new int[r];
        combinationUtil(arr, n, r, 0, data, 0);
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int r = 3;
        int n = arr.length;

        printCombination(arr, n, r);
    }
}





import java.util.*;

class Combinations {
    static void dfs(int[] arr, int r, int start,
                    List<Integer> temp) {
        if (temp.size() == r) {
            System.out.println(temp);
            return;
        }

        for (int i = start; i < arr.length; i++) {
            temp.add(arr[i]);
            dfs(arr, r, i + 1, temp);
            temp.remove(temp.size() - 1);
        }
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        dfs(arr, 3, 0, new ArrayList<>());
    }
}