
public class QuickSort {
	
	public static void _sort(int[] arr) {
		int beg = 0;
		int end = arr.length-1;
		quickSort(arr, beg, end);
	}
	
	private static void quickSort(int[] arr, int beg, int end) {

		if(beg<end) {

			int index = partitionIndex(arr, beg, end);
			quickSort(arr, beg, index-1);
			quickSort(arr, index+1, end);
		}
	}

	private static int partitionIndex(int[] arr, int beg, int end) {

		int pivot = arr[end];
		int index = beg;

		for(int i=beg; i<end; i++) {

			if(arr[i]<=pivot) {
				int temp = arr[index];
				arr[index] = arr[i];
				arr[i] = temp;
				index++;
			}
		}
		int temp = arr [index];
		arr[index] = arr[end];
		arr[end] = temp;

		return index;
	}
	
}