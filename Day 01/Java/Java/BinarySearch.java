package Java;

/**
 * Regular binary search
 */
public class BinarySearch {

    public static int BinarySearch( int input[], int search) {
        int low = 0;
        int high = input.length - 1;
        int mid;
        while (low <= high) {
            mid = low + ((high - low) / 2);
            if (input[mid] == search) {
                return mid;
            } else if (input[mid] < search) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String args[]) {
        final int arr1[] = {1, 2, 4, 5, 7, 8};
        System.out.println(BinarySearch(arr1, -1));
        System.out.println(BinarySearch(arr1, 1));
        System.out.println(BinarySearch(arr1, 8));
        System.out.println(BinarySearch(arr1, 2));
    }
}