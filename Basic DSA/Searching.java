
public class Searching {

    public static int binarySearch(int[] arr, int element) {  // Binary Search 

        int beg=0;
        int end=arr.length-1;

        while(beg<=end) {

            int mid=(beg+end)/2;

            if(arr[mid]<element) {
                beg= mid+1;
            }else if(arr[mid]==element) {
                return mid;
            }else {
                end=mid-1;
            }
        }
        return -1;
    }

    public static int linearSearch(int[] arr, int element) {  // Linear Search

        for(int i=0; i<arr.length; i++) {

            if(arr[i]==element) return i;
        }

        return -1;
    }
}