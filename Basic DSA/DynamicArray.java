public class DynamicArray {
	
	private int capacity;
	private int[] arr;
	private int size;
	
	public DynamicArray() {
		this.capacity = 5;
		this.arr = new int[capacity];
		this.size = 0;
	}
	
	public boolean add(int data) {
		if(fillFactor()) expand();
		
		arr[size] = data;
		size++;
		return true;
	}
	
	public boolean remove() {
		if(unfillFactor()) shrink();
		
		size = size - 1;
		arr[size] = 0;
		return true;
	}
	
	public void show() {
		for(int x : arr )
			System.out.print(x+ " ");
		System.out.println();
	}
	
	private void expand() {
		int length = size;
		capacity = capacity*2;
		int[] newArray = new int [capacity];
		System.arraycopy(arr, 0, newArray, 0, length);
		arr = newArray;	
	}
	
	private void shrink() {
		int length = size;
		capacity = capacity/2;
		int[] newArray = new int [capacity];
		System.arraycopy(arr, 0, newArray, 0, length);
		arr = newArray;
	}
		
	private boolean fillFactor() {
		int factor_value = (capacity*80)/100;
		return factor_value == size;
	}
	
	private boolean unfillFactor() {
		int factor_value = (capacity*40)/100;
		return factor_value == size;
	}
	
}