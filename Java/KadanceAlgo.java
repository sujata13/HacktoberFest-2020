package Java;

public class KadanceAlgo {

    public static int maxSubArray(int[] nums) {
        
        int maxEndingHere = nums[0];
        int maxSoFar = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            int x = nums[i];
            maxEndingHere = Math.max(x, maxEndingHere + x);
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }
        
        return maxSoFar;
        
    }

    public static void main(String args[]) {
        final int arr1[] = {1, 2, 4, 5, 7, 8};
        System.out.println(maxSubArray(arr1));
        
    }
}