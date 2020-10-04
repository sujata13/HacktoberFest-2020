/*  "Next greater element on the right" of an element x is defined as the first element to right of x having value greater than x.
Note -> If an element does not have any element on it's right side greater than it, consider -1 as it's "next greater element on right"
e.g.
for the array [2 5 9 3 1 12 6 8 7]
Next greater for 2 is 5
Next greater for 5 is 9
Next greater for 9 is 12
Next greater for 3 is 12
Next greater for 1 is 12
Next greater for 12 is -1
Next greater for 6 is 8
Next greater for 8 is -1
Next greater for 7 is -1    */

import java.util.*;
public class NextGreaterElementToRight{
  public static void display(int[] arr){
    for(int i=0;i<arr.length;i++){
      System.out.println(arr[i]);
    }
    System.out.println();
  }

  public static int[] solve(int[] arr){
   Stack<Integer> st=new Stack<>();
   int[] ans=new int[arr.length];
   for(int i=arr.length-1;i>=0;i--){
       while(st.size()>0 && st.peek()<=arr[i]){
           st.pop();
       }
       if(st.size()==0){
           ans[i]=-1;
       }else{
           ans[i]=st.peek();
           
       }
       st.push(arr[i]);
   }
   return ans;
 }

public static void main(String[] args)  {
    Scanner scn=new Scanner(System.in);
    int n=scn.nextInt();
    int[] arr=new int[n];
    for(int i=0;i<arr.length;i++){
      arr[i]=scn.nextInt();
    }
   
    int[] nge = solve(arr);
    
    display(nge);
 }

}