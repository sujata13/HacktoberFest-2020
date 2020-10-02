import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Achsion_MergeSort {
    public static void main(String[] args) {
        List<Integer> arr = readArray();
        mergeSort(arr);
        printArray(arr);
    }

    private static List<Integer> mergeSort(List<Integer> list) {
        if (list.size() <= 1) {
            return list;
        }

        List<Integer> left = mergeSort(
            list.subList(0, Math.floorDiv(list.size(), 2))
        );
        List<Integer> right = mergeSort(
            list.subList(Math.floorDiv(list.size(), 2), list.size())
        );

        return merge(left, right);
    }

    private static List<Integer> merge(List<Integer> left, List<Integer> right) {
        List<Integer> merged = new ArrayList<>();
        int leftI = 0;
        int rightI = 0;

        while (leftI < left.size() && rightI < right.size()) {
            if (left.get(leftI) > right.get(rightI)) {
                merged.add(right.get(rightI));
                rightI++;
            } else {
                merged.add(left.get(leftI));
                leftI++;
            }
        }

        for (; leftI < left.size(); leftI++) {
            merged.add(left.get(leftI));
        }
        for (; rightI < right.size(); rightI++) {
            merged.add(right.get(rightI));
        }

        return merged;
    }

    private static List<Integer> readArray() {
        Scanner sc = new Scanner(System.in);
        List<Integer> arr = new ArrayList<>();

        System.out.print("Enter array size: ");
        int size = sc.nextInt();

        System.out.println("Enter array elements: ");
        for (int i = 0; i < size; i++) {
            arr.add(sc.nextInt());
        }

        sc.close();
        return arr;
    }

    private static void printArray(List<Integer> arr) {
        System.out.println("Sorted array: ");
        arr.forEach(item -> System.out.println(item + " "));
        System.out.println("\n");
    }
}
