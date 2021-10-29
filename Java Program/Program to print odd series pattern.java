// importing the libraries
import java.util.Scanner;
// initializing the main class
public class Main{
    // initializing the main method
    public static void main(String[] args){
        // creating a new Scanner object
        Scanner scanner = new Scanner(System.in);
        
        // use ifyou want to get the number of rows from the user
        // System.out.println("Enter the number of rows to print the pattern ");
        // int rows = scanner.nextInt();
        
        int rows = 9;
        // iterating over the rows
        for (int i = 1; i <= rows; i++){
            if(i%2==0)
                    // if the value is even, continue
                    continue;
            for (int j = rows; j > i; j--){
                System.out.print(" ");
            }
            // displaying the result
            for (int k = 1; k <= i; k++){
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}