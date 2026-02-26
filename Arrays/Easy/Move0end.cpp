/*
Move 0 to end*/
import java.util.*;

class Solution {
    public ArrayList<Integer> moveZeroes(ArrayList<Integer> A) {
        int j = 0;

        for (int i = 0; i < A.size(); i++) {
            if (A.get(i) != 0) {
                Collections.swap(A, i, j);
                j++;
            }
        }

        return A;
    }
}
