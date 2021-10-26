
public class StackArray {                  // class declaration

    private int capacity;
    private int stack[];
    private int TOP;

    public StackArray(int capacity) {      // constructor

        this.capacity = capacity;
        this.stack = new int[capacity];
        this.TOP = -1;
    }

    public final int push(int item) {      // push method

        if(isFull()) return -1;

        stack[++TOP] = item;
        return item;
    }

    public final int pop() {                // pop method

        if(isEmpty()) return -1;

        int item = stack[TOP];
        TOP--;
        return item;
    }

    public final int peek() {                // peek method

        if(isEmpty()) return -1;

        return stack[TOP];
    }

    public final int search(int item) {      // search method

        if(isEmpty()) return -1;
		
		for(int i=0; i<capacity; i++) {	
			if(stack[i]==item) return 1;	
		}
        	
		return 0;
    }

    public final boolean isEmpty() {         // empty method

        return TOP==-1;
    }

    private final boolean isFull() {

        return TOP==capacity-1;
    }

}