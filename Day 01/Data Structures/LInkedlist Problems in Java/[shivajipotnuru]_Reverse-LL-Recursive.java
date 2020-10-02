
/*
class LinkedListNode<T> {
	public T data;
	public LinkedListNode<T> next;

	public LinkedListNode(T data) {
		this.setData(data);
		this.next = null;
	}

	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}

}
* */
public class Solution {
	
	public static LinkedListNode<Integer> reverse_R(LinkedListNode<Integer> head) {
       if (head == null || head.next == null)  
            return head;  
  
        /* reverse the rest list and put  
        the first element at the end */
         LinkedListNode<Integer>  rest = reverse_R(head.next);  
        head.next.next = head;  
  
        /* tricky step -- see the diagram */
        head.next = null;  
  
        /* fix the head pointer */
        return rest;
	}
}
