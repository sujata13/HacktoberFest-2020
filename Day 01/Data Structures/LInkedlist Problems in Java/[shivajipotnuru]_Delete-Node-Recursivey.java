/*************** 
 * Following is the Node class already written 
class LinkedListNode<T> {
	T data;
	LinkedListNode<T> next;

	public Node(T data) {
		this.data = data;
	}
}
 ***************/

public class Solution {

    public static LinkedListNode<Integer> deleteIthNodeRec(LinkedListNode<Integer> head, int i){
        /* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
	 	 * Taking input and printing output is handled automatically.
		*/
        if (head == null)  
            return null;  
        if (i == 0)  
        {  
            LinkedListNode<Integer> res = head.next;  
            return res;  
        }  
        LinkedListNode<Integer> del =  deleteIthNodeRec(head.next, i-1);  

        head.next=del;
        return head;

    }
}