import java.util.*;

public class Main {

    public static double median(int[] a, int[] b) {
        int n1 = a.length, n2 = b.length;

        // Ensure a is the smaller array
        if (n1 > n2) return median(b, a);

        int n = n1 + n2;
        int left = (n + 1) / 2;

        int low = 0, high = n1;

        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = Integer.MIN_VALUE, l2 = Integer.MIN_VALUE;
            int r1 = Integer.MAX_VALUE, r2 = Integer.MAX_VALUE;

            if (mid1 < n1) r1 = a[mid1];
            if (mid2 < n2) r2 = b[mid2];
            if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

            // correct partition
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return Math.max(l1, l2);
                else
                    return (Math.max(l1, l2) + Math.min(r1, r2)) / 2.0;
            }
            // move left
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            // move right
            else {
                low = mid1 + 1;
            }
        }
        return 0; // dummy
    }

    public static void main(String[] args) {
        int[] a = {1, 4, 7, 10, 12};
        int[] b = {2, 3, 6, 15};

        System.out.printf("The median of two sorted array is %.1f%n", median(a, b));
    }
}