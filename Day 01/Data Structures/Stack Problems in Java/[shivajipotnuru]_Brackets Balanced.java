public class Solution {

	public static boolean checkBalanced(String exp) {
		// Write your code here
Stack st=new Stack();
        boolean val=false;
        
        for(int i=0;i<exp.length();i++){
           
            if(exp.charAt(i)=='{' || exp.charAt(i)=='[' ||exp.charAt(i)=='('){
                val=false;
                st.push(exp.charAt(i));
            }else if(exp.charAt(i)=='}' || exp.charAt(i)==']' || exp.charAt(i)==')'){
                char c=st.pop();
                
               // System.out.print(c);
                if(c=='x'){
                    return false;
                }
                if(exp.charAt(i)==')'){
                    if(c=='('){
                        val=true;
                        continue;
                    }//if there is any other brackets found set val to false;
                    val=false;
                    break;
                }else if(exp.charAt(i)==']'){
                    if(c=='['){
                        val=true;
                        continue;
                    }
                    val=false;
                    break;
                }else if(exp.charAt(i)=='}'){
                    if(c=='{'){
                        val=true;
                        continue;
                    }
                    val=false;
                    break;
                }
                else{
                    val=false;
                    break;
                }
                
            }
        }
        // ex- ([] here it will return true as the last it was found matched
        //but there is still one element left in the stack and there is no
        //brackets to match further so we keep condition if and only if
        //top will go to null such that everything is matched
        if(st.top!=null){
            return false;
        }
        return val;
	}
}

class Node{
    
    char data;
    Node next;
    Node(char data){
        this.data=data;
    }
}

class Stack{
    
    Node top;
    
    public void push(char data){
        Node newNode=new Node(data);
        if(top==null){
            newNode.next=null;
            top=newNode;
            return;
        }
        newNode.next=top;
        top=newNode;
    }
  
    public char pop(){
        if(top==null){
           return 'x'; 
        }
        char c=top.data;
        top=top.next;
       // System.out.println(c);
return c;
	}
}