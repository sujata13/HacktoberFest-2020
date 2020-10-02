import java.util.Arrays;
import java.util.Stack;

public class Solution {

	public static int[] stockSpan(int[] price) {
		// Write your code here
        Stack<Integer> st =new Stack<Integer>();
        // st.push(1);
        int span[] =new int[price.length];
        for(int i=0;i<price.length;i++){
            // st.push[i];
            while(!st.isEmpty() && price[st.peek()]< price [i])
            {
           	 st.pop();
            }
            if(st.isEmpty()){
                span[i]=i+1;
            }
            else
                span[i]=i-st.peek();
            st.push(i);
            
            
        }
        return span;
       
	}
     
}