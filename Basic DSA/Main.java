
public class Main {

    public static void main(String[] args) {
        
        /* 
		   Searching + Sorting Algo Testing
		
		int arr[]={5, 7, 3, 1, 8, 2, 6, 9, 4};
		
		int index0 = Searching.linearSearch(arr, 4);
        System.out.println("Linear search: "+index0);

        MergeSort._sort(arr);
		QuickSort._sort(arr);
		Sorting.bubbleSort(arr);
		Sorting.selectionSort(arr);
		Sorting.insertionSort(arr);

        int index1 = Searching.binarySearch(arr, 7);
        System.out.println("Binary search: "+index1);

        for(int x: arr)
        System.out.print(x+" ");
	
	    */
		
		/* 
		  Stack Operations

        StackArray st = new StackArray(3);
		
		System.out.println(st.peek());
		System.out.println(st.pop());
		System.out.println(st.isEmpty());
		System.out.println(st.push(5));
		System.out.println(st.push(8));
		System.out.println(st.push(6));
		System.out.println(st.push(4));

        System.out.println(st.search(8));
        System.out.println(st.pop());
		System.out.println(st.push(9));
        System.out.println(st.peek());
        System.out.println(st.isEmpty());
		
		*/
		
		
		// QueueArray qa = new QueueArray(3);
		// System.out.println(qa.isEmpty());
		// System.out.println(qa.deQueue());
		// System.out.println(qa.front());
		// System.out.println(qa.enQueue(1));
		// System.out.println(qa.enQueue(2));
		// System.out.println(qa.enQueue(3));
		// System.out.println(qa.enQueue(4));
		// System.out.println(qa.front());
		// System.out.println(qa.deQueue());
		// System.out.println(qa.isEmpty());
		// System.out.println(qa.enQueue(4));
		// System.out.println(qa.deQueue());
		// System.out.println(qa.enQueue(4));
		// System.out.println(qa.deQueue());
		// System.out.println(qa.isEmpty());
		// System.out.println(qa.enQueue(5));
		// System.out.println(qa.enQueue(6));
		// System.out.println(qa.front());
		// System.out.println(qa.deQueue());
		// System.out.println(qa.deQueue());
		// System.out.println(qa.isEmpty());
		// System.out.println(qa.deQueue());
		// System.out.println(qa.isEmpty());
		
		DynamicArray dr = new DynamicArray();
		dr.add(1);
		dr.add(1);
		dr.add(1);
		dr.add(1);
		dr.show();
		dr.add(1);
		dr.add(1);
		dr.add(1);
		dr.add(1);
		dr.add(1);
		dr.show();
		dr.remove();
		dr.remove();
		dr.show();
    }
}