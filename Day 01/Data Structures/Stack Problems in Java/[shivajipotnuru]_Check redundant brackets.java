import java.util.Stack;

public class solution {
	
	public static boolean checkRedundantBrackets(String s) {
		// Write your code here
        Stack<Character> st = new Stack<>(); 
        char[] str = s.toCharArray(); 
         
        for (char ch : str) { 
  
             
            if (ch == ')') { 
                char top = st.peek(); 
                st.pop(); 
  
                boolean flag = true; 
  
                while (top != '(') { 
   
                    if (top == '+' || top == '-'|| top == '*' || top == '/') { 
                        flag = false; 
                    } 
                    top = st.peek(); 
                    st.pop(); 
                } 
  
                 
                if (flag == true) { 
                    return true; 
                } 
            } else { 
                st.push(ch);  
            }                 
        } 
        return false; 

	}
}