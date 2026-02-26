class Solution {
    private long count = 0;

    public long inversionCount(long[] arr, long N) {
        mergeSort(arr, new long[(int) N], 0, (int) N - 1);
        return count;
    }

    private void mergeSort(long[] arr, long[] temp, int l, int r) {
        if (l >= r) return;

        int m = (l + r) / 2;
        mergeSort(arr, temp, l, m);
        mergeSort(arr, temp, m + 1, r);
        merge(arr, temp, l, m, r);
    }

    private void merge(long[] arr, long[] temp, int l, int m, int r) {
        int i = l, j = m + 1, k = l;

        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
                count += (m - i + 1);
            }
        }

        while (i <= m) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];

        for (int idx = l; idx <= r; idx++) arr[idx] = temp[idx];
    }
}