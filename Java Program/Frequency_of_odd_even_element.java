public class Frequency_of_odd_even_element {
    public static void main(String[] args) {
        int rows, cols;
        int a[][] = { { 8, 2, 3 }, { 8, 6, 4 }, { 1, 2, 3 } };
        rows = a.length;
        cols = a[0].length;
        int oddcount = 0;
        int evencount = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (a[i][j] % 2 == 0) {
                    evencount++;
                } else {
                    oddcount++;
                }
            }
        }
        System.out.println("Frequency of odd numbers : " + oddcount);
        System.out.println("Frequency of even numbers : " + evencount);

    }
}