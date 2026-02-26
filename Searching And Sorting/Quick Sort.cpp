public class Main {

    static int partition(int[] arr, int s, int e) {
        int pivot = arr[s];

        int cnt = 0;
        for (int i = s + 1; i <= e; i++) {
            if (arr[i] <= pivot) cnt++;
        }

        // Place pivot at correct position
        int pivotIndex = s + cnt;
        swap(arr, pivotIndex, s);

        int i = s, j = e;

        while (i < pivotIndex && j > pivotIndex) {

            while (arr[i] <= pivot) i++;
            while (arr[j] > pivot) j--;

            if (i < pivotIndex && j > pivotIndex) {
                swap(arr, i++, j--);
            }
        }

        return pivotIndex;
    }

    static void quickSort(int[] arr, int s, int e) {
        if (s >= e) return;

        int p = partition(arr, s, e);

        quickSort(arr, s, p - 1);
        quickSort(arr, p + 1, e);
    }

    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        int[] arr = {2, 4, 1, 6, 9, 9, 9, 9, 9, 9};
        int n = arr.length;

        quickSort(arr, 0, n - 1);

        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}