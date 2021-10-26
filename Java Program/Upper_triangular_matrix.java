// to display upper triangular matrix
public class Upper_triangular_matrix {
    public static void main(String[] args) {
        int rows, cols;
        int a[][] = { { 1, 2, 3 }, { 8, 6, 4 }, { 1, 2, 3 } };
        rows = a.length;
        cols = a[0].length;
        if (rows != cols) {
            System.out.println("Matrix should be square matrix");
        } else {
            System.out.println("Upper triangular matrix");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (j > i)
                        System.out.print("0 ");
                    else
                        System.out.print(a[i][j] + " ");
                }
                System.out.println();
            }
        }

    }
}
