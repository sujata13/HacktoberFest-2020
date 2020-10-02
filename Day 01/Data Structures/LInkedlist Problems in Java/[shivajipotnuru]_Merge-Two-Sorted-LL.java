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

	public static LinkedListNode<Integer> mergeTwoList(LinkedListNode<Integer> headA, LinkedListNode<Integer> headB) {
		/* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
	 	 * Taking input and printing output is handled automatically.
		*/
      LinkedListNode<Integer> dummynode =new LinkedListNode<Integer> (0);
    LinkedListNode<Integer> tail =dummynode;
        while(true)  
        { 
          
        /* if either list runs out,  
        use the other list */
        if(headA == null) 
        { 
            tail.next = headB; 
            break; 
        } 
        if(headB == null) 
        { 
            tail.next = headA; 
            break; 
        } 
             if(headA.data <= headB.data) 
        { 
            tail.next = headA; 
            headA = headA.next; 
        }  
        else
        { 
            tail.next = headB; 
            headB = headB.next; 
        } 
          
        /* Advance the tail */
        tail = tail.next; 
        }
        return dummynode.next;
    }

}