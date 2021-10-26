public class SingleLL {
	
	Node head = null;
	
	public void add(int val, int pos) {  // add method with position
		int len = length();
		if(pos==0 || pos > len) return;
		
		Node node = new Node(val);
		if(pos == 1) {
			head = node;
			return;
		}
		Node temp = head;
		for(int i=1; i<pos-1; i++)
			temp = temp.next;
		node.next = temp.next;
		temp.next = node;
	}
	
	public void addFirst(int val) {  // add method at begin
		Node node = new Node(val);
		
		if(head==null) {
			head = node;
			return;
		}
		node.next = head;
		head = node;
	}
	
	public void addLast(int val) {  // add method at end
		Node node = new Node(val);
		
		if(head==null) {
			head = node;
			return;
		}
		
		Node temp = head;
		while(temp.next!=null)
			temp = temp.next;
		temp.next = node;
	}
	
	public int get(int pos) {   // get method with position
		int len = length();
	    if(pos==0 || pos>len) return -1;
		else if(pos == 1) return head.data;
		
		Node temp = head;
		for(int i=1; i<pos; i++)
			temp = temp.next;
		return temp.data;
	}
	
	public int getFirst() {    // get method at begin
		if(head==null) return -1;
		
		return head.data;
	}
	
	public int getLast() {    // get method at end
		if(head==null) return -1;
		
		Node temp = head;
		while(temp.next!=null) 
			temp = temp.next;
		return temp.data;
	}
	
	public int remove(int pos) {  // remove method with position
		int len = length();
	    if(pos==0 || pos>len) return -1;
		else if(pos == 1) {
			int val = head.data;
			head = head.next;
			return val;
		}
		
		Node temp = head;
		for(int i=1; i<pos-1; i++)
			temp = temp.next;
		int val = temp.next.data;
		temp.next = temp.next.next;
		return val;
	}
	
	public int removeFirst() {    // remove method at begin
		if(head==null) return -1;
		
		int val = head.data;
		head = head.next;
		return val;
	}
		
	public int removeLast() {     // remove method at end
		if(head==null) return -1;
		else if(head.next==null) {
			int val = head.data;
			head = head.next;
			return val;
		}
		
		Node temp = head;
		while(temp.next.next!=null)
			temp = temp.next;
		int val = temp.next.data;
		temp.next = null;
		return val;
	}
	
	public int set(int pos, int newVal) {  // set method with position
		int len = length();
	    if(pos==0 || pos>len) return -1;
		else if(pos == 1) {
			int oldVal = head.data;
			head.data = newVal;
			return oldVal;
		}
		
		Node temp = head;
		for(int i=1; i<pos; i++)
			temp = temp.next;
		int oldVal = temp.data;
		temp.data = newVal;
		return oldVal;
	}
	
	public void reverse() {   // reverse method
	    if(head==null) return;
		
		Node prev = null;
		Node current = head;
		Node next = head;
		
		while(current!=null) {
			next = current.next;
			current.next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
		
	public void displayNodes() {  // display method
		if(head==null) {
			System.out.println("Empty!");
			return;
		}
		
		Node temp = head;
		while(temp!=null) {
			System.out.print(temp.data+ " ");
			temp = temp.next;
		}
		System.out.println();
	}
		
	public int length() {   // length method
		if(head==null) return -1;
		
		int count = 0;
		Node temp = head;
		while(temp!=null) {
			temp = temp.next;
			count++;
		}
		return count;
	}
}

class Node {
	int data;
	Node next;
	public Node(int _data) {
		this.data = _data;
		this.next = null;
	}
}
