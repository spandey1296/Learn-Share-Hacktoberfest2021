public class Add_two_matrix {

    public static void main(String[] args) {
        int a[][] = { { 4, 3, 6 }, { 2, 3, 0 }, { 3, 4, 5 } };
        int b[][] = { { 5, 6, 3 }, { 2, 1, 4 }, { 6, 5, 4 } };

        // create new matrix to store sum of two matrices
        int c[][] = new int[3][3];

        // addding
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                c[i][j] = a[i][j] + b[i][j];
                System.out.print(c[i][j] + " ");
            }
            System.out.println();
        }
    }
}
