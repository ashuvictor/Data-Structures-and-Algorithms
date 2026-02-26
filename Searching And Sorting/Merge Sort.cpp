class Solution {

    public void merge(int[] arr, int l, int m, int r) {
        int start = l, center = m, end = r;
        int[] merged = new int[r - l + 1];

        int i = 0;
        int right = m + 1;

        // Merge two sorted halves
        while (l <= center && right <= r) {
            if (arr[l] <= arr[right]) {
                merged[i++] = arr[l++];
            } else {
                merged[i++] = arr[right++];
            }
        }

        // Remaining left half
        while (l <= center) {
            merged[i++] = arr[l++];
        }

        // Remaining right half
        while (right <= r) {
            merged[i++] = arr[right++];
        }

        // Copy back to original array
        i = 0;
        for (int j = start; j <= end; j++) {
            arr[j] = merged[i++];
        }
    }

    public void mergeSort(int[] arr, int l, int r) {
        if (l >= r) return;

        int m = (l + r) >> 1;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}