public class Array_elements_copy {
    public static void main(String[] args) {
        int[] arr1 = new int[] { 11, 22, 33, 44, 99 };
        int arr2[] = new int[arr1.length];

        // to copy
        for (int i = 0; i < arr1.length; i++) {
            arr2[i] = arr1[i];
        }
        // to display elements
        System.out.println("Original array elements");
        for (int i = 0; i < arr1.length; i++) {
            System.out.print(arr1[i] + " ");
        }
        System.out.println();
        System.out.println("New  array elements");
        for (int i = 0; i < arr1.length; i++) {
            System.out.print(arr2[i] + " ");
        }

    }
}