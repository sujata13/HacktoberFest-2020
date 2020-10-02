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

	public static LinkedListNode<Integer> deleteIthNode(LinkedListNode<Integer> head, int position){
		/* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
	 	 * Taking input and printing output is handled automatically.
		*/
     LinkedListNode<Integer> current = head;
  LinkedListNode<Integer>  parent = null;
    int index = 0;
    
    while (current != null && index < position) {
        parent = current;
        current = current.next;
        
        index++;
    }
    
    if (current != null && parent == null) {
        // Delete head.
        if (current.next != null) {
            // Move head to next value.
            head = current.next;
        }
        else {
            // Just set the head to null.
            head = null;
        }
    }
    else if (current != null) {
        // Delete current, link parent to child..
        parent.next = current.next;
    }
    
    return head;
    }
}