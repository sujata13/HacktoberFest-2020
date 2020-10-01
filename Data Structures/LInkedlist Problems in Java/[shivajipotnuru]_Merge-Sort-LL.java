public class Solution {

public static LinkedListNode<Integer> mid(LinkedListNode<Integer>head)
	{
	LinkedListNode<Integer>fast=head.next;
		LinkedListNode<Integer>slow=head;
		while(fast!=null&&fast.next!=null)
		{
			fast=fast.next.next;
			slow=slow.next;
		}
		return slow; //slow will always point to the left mid in case of even no. of nodes in the linked list

	}
	public static LinkedListNode<Integer> mergeSortedLL(LinkedListNode<Integer>firstHead,LinkedListNode<Integer>secondHead){
		LinkedListNode<Integer>newHead=null;
		LinkedListNode<Integer>sorting=null;
		if(firstHead==null)
			return secondHead;
		else
			if(secondHead==null)
				return firstHead;
			else
			{
				if(firstHead.data<=secondHead.data)
					{
					sorting=firstHead;
					firstHead=firstHead.next;
					}
				else
				{
					sorting=secondHead;
					secondHead=secondHead.next;
				}
					newHead=sorting;
					while(firstHead!=null&&secondHead!=null)
					{
						if(firstHead.data<=secondHead.data)
						{
							sorting.next=firstHead;
							sorting=firstHead;
							firstHead=firstHead.next;
						}
						else
						{
							sorting.next=secondHead;
							sorting=secondHead;
							secondHead=secondHead.next;
						}
					}
						if(firstHead==null)
						{
							sorting.next=secondHead;
						}
						else if(secondHead==null)
						{
							sorting.next=firstHead;
								
						}
						return newHead;
						
					
			}
	}
	public static LinkedListNode<Integer> mergeSort(LinkedListNode<Integer> head) {
	if(head==null||head.next==null)
		{
			return head;
		}
			//do not use the list splitting method used in palindrome since the middle node will be lost;
		LinkedListNode<Integer>mid=mid(head);
	LinkedListNode<Integer>firstHalfTail=mid;
		LinkedListNode<Integer>secondHalfHead=mid.next;
		firstHalfTail.next=null;
	LinkedListNode<Integer>head1=mergeSort(head);
		LinkedListNode<Integer>head2=mergeSort(secondHalfHead);
		LinkedListNode<Integer>mergedListHead=mergeSortedLL(head1, head2);
		return mergedListHead;
		

	}

}