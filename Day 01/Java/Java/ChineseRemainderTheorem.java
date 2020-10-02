package Java;
/*
Input:  num[] = {5, 7}, rem[] = {1, 3}
Output: 31
Explanation: 
31 is the smallest number such that:
  (1) When we divide it by 5, we get remainder 1. 
  (2) When we divide it by 7, we get remainder 3.

Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}
Output: 11
Explanation: 
11 is the smallest number such that:
  (1) When we divide it by 3, we get remainder 2. 
  (2) When we divide it by 4, we get remainder 3.
  (3) When we divide it by 5, we get remainder 1.
*/

public class ChineseRemainderTheorem {
    static int findMinX(int num[], int rem[], int k) 
    { 
        int x = 1; // Initialize result 
       
        // As per the Chinese remainder theorem, 
        // this loop will always break. 
        while (true) 
        { 
            // Check if remainder of x % num[j] is  
            // rem[j] or not (for all j from 0 to k-1) 
            int j; 
            for (j=0; j<k; j++ ) 
                if (x%num[j] != rem[j]) 
                   break; 
       
            // If all remainders matched, we found x 
            if (j == k) 
                return x; 
       
            // Else try next numner 
            x++; 
        } 
       
    } 
       
    // Driver method 
    public static void main(String args[]) 
    { 
        int num[] = {3, 4, 5}; 
        int rem[] = {2, 3, 1}; 
        int k = num.length; 
        System.out.println("x is " + findMinX(num, rem, k)); 
    } 
}
