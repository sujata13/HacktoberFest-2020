/*A number of balls are kept in a basket each named in the range [1,n]. some students picked few balls randomly and changed
their numbers to existing numbers in the box and then added back. Now box has unique numbers + duplicate numbers.
Find the original numbers on the balls whose numbers were changed.

Input variables:-
   int t: no. of test cases
   int n: range
   int arr[]: array conatining the original and duplicate numbered balls

Input Description:
-First line of input consists of t, the number of test cases
-Next each lines consist of n the range
-Next line consist of the array conatining the original and duplicate numbered balls

Output Description:-
   Print the balls whose numbers were changed

Constraints:-
 -> 1<=t,n<=10
 ->1<= value of each array element <=10

 Sample Input:
2
8
4 3 2 7 8 2 3 1
2
1 1

Sample Output:
5 6
2
 */



import java.util.*;

public class multiple_dup {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t, i, j, n;
        t = s.nextInt();
        for (i = 0; i < t; i++) {
            n = s.nextInt();
            int[] arr = new int[n];

            for (j = 0; j < n; j++) {
                arr[j] = s.nextInt();
            }

            int[]reg = new int[arr.length+1];

            for (int k:arr){
                reg[k]=1;
            }

            for (j=1;j<reg.length;j++)
            {
                if (reg[j]==0)
                {
                    System.out.print(j+" ");
                }
            }
            System.out.println();
        }
    }
}

