import java.util.Stack;

public class Solution {
    public static void helper(Stack<Integer> s1,Stack<Integer> s2)
    {
        if(s1.isEmpty())
            return;
        int temp=s1.pop();
        helper(s1,s2);
        s2.push(temp);
    }
    public static void reverseStack(Stack<Integer> s1, Stack<Integer> s2) {
        helper(s1,s2);
        while(!s2.isEmpty())
            s1.push(s2.pop());
    }
}