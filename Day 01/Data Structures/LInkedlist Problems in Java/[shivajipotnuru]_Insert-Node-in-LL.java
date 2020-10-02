/*************** 
 * Following is the Node class already written 
class Node<T> {
	T data;
	Node<T> next;

	public Node(T data) {
		this.data = data;
	}
}
***************/

public class Solution {

    public static Node<Integer> insert(Node<Integer> head, int data, int pos){
        /* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
	 	 * Taking input and printing output is handled automatically.

		*/
        Node <Integer> nodeToBeInserted =new Node<Integer> (data);
        Node<Integer> prev =head;
        int count=0;
        if(pos==0){
            nodeToBeInserted.next=head;
            return nodeToBeInserted;
        }else


            while(count<pos-1 && prev !=null){
                count++;
                prev =prev.next;

            }
        if(prev!= null){
            nodeToBeInserted.next=prev.next;
            prev.next=nodeToBeInserted;
        }return head;

    }
}
