
public class Sorting {

    public static void bubbleSort(int[] arr) {   // Bubble Sort

        for(int i=0; i<arr.length-1; i++) {

            for(int j=0; j<arr.length-i-1; j++) {

                if(arr[j]> arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    public static void selectionSort(int[] arr) { // Selection Sort

        for(int i=0; i<arr.length-1; i++) {

            int min=i;
            for(int j=i+1; j<arr.length; j++) {

                if(arr[j]<arr[min]) {
                    min= j;
                }
            }
            if(min!=i) {

                int temp= arr[i];
                arr[i]=arr[min];
                arr[min]= temp;
            }
        }
    }

    public static void insertionSort(int[] arr) {  // Insertion Sort

        for(int i=1; i<arr.length; i++) {

            int value = arr[i];
            int hole =i;

            while(hole>0 && arr[hole-1]>value) {

                arr[hole] = arr[hole-1];
                hole = hole-1;
            }
            arr[hole] = value;
        }
    }
}