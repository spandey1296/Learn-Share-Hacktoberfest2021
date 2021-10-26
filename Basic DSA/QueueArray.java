public class QueueArray {
	
	/* 
	  Simple Queue :--->
	  simply increment front and rear value
	  initialized with front =-1 rear =-1; empty condition
	  rear == capacity-1 full condition;
	  front == rear reinitialized
	*/

    private int capacity;
    private int queue[];
    private int _front;
    private int _rear;
	private int size;

    public QueueArray(int capacity) {

        this.capacity = capacity;
        this.queue = new int[capacity];
        this._front = 0;
        this._rear = 0;
		this.size = 0;
    }
	
	public boolean enQueue(int data) {
		if(isFull()) return false;
		
		queue[_rear] = data;
		_rear = (_rear+1)%capacity;
		size = size + 1;
		return true;
	}
	
	public int deQueue() {	
		if(isEmpty()) return -1;
		
		int data = queue[_front];
		_front = (_front+1)%capacity;
		size = size - 1;
		return data;
	}
	
	public int front() {
		if(isEmpty()) return -1;
		
		return queue[_front];
	}

    public boolean isEmpty() {
		return size == 0;
    }
	
	private boolean isFull() {
		return size == capacity;
	}
}