
public class DoubleLL {
	
	DNode head = null;
	
	public void addFirst(int val) {  // add at begin method
		DNode node = new DNode(val);
		
		if(head==null) {
			head = node;
			return;
		}
		
        head.prev = node;		
		node.next = head;
		head = node;
	}
	
	public void addLast(int val) {  // add method at end
		DNode node = new DNode(val);
		
		if(head==null) {
			head = node;
			return;
		}
		
		DNode temp = head;
		while(temp.next!=null)
			temp = temp.next;
		node.prev = temp;
		temp.next = node;
		
	}
	
	public int getFirst() {    // get method at begin
		if(head==null) return -1;
		
		return head.data;
	}
	
	public int getLast() {    // get method at end
		if(head==null) return -1;
		
		DNode temp = head;
		while(temp.next!=null) 
			temp = temp.next;
		return temp.data;
	}
	
	public int removeFirst() {    // remove method at begin
		if(head==null) return -1;
		
		int val = head.data;
		head = head.next;
		head.prev = null;
		return val;
	}
	
	public int removeLast() {     // remove method at end
		if(head==null) return -1;
		else if(head.next==null) {
			int val = head.data;
			head = head.next;
			return val;
		}
		
		DNode temp = head;
		while(temp.next!=null)
			temp = temp.next;
		int val = temp.data;
		temp.prev.next = null;
		return val;
	}
	
	public void reverse() {    // reverse method
		if(head==null) return;
		
		DNode cursor = head;
		DNode current = head;
		while(current!=null) {
			cursor = current.prev;
			current.prev = current.next;
			current.next = cursor;
			current = current.prev;
		}	
		head = cursor.prev;
	}		
	
	public void displayNodes() {  // display method
		if(head==null) {
			System.out.println("Empty!");
			return;
		}
		
		DNode temp = head;
		while(temp!=null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
		System.out.println();
	}
	
	public int length() {   // length method
		if(head==null) return -1;
		
		int count = 0;
		DNode temp = head;
		while(temp!=null) {
			temp = temp.next;
			count++;
		}
		return count;
	}
	 
}

class DNode {
	int data;
	DNode prev;
	DNode next;
	
	public DNode(int _data) {
		this.data = _data;
		this.prev = null;
		this.next = null;
	}
}

/* 
   Advantage : Traverse forward and backward
   Disadvantage: Extra Memory
   note: To access any thing in heap u have a pointer.
   
*/
	