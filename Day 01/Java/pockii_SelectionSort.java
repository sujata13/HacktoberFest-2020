import java.util.Scanner;

class pockii_SelectionSort {

    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int minIndex = i;
            
            // Finding the smallest element
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            // Swap smallest element with current index
            int minNum = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = minNum;
        }
    }

    private static void printArray(int[] arr) {
        System.out.println("Sorted array: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println("\n");
    }

    public static int[] readArray() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int size = sc.nextInt();
        int[] arr = new int[size];

        System.out.println("Enter array elements: ");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }

        sc.close();
        return arr;
    }
    public static void main(String[] args) {
        int[] arr = readArray();
        selectionSort(arr);
        printArray(arr);
    }
}