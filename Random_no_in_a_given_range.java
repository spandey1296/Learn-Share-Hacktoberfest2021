import java.lang.Math;
import java.util.Scanner;

public class Random_no_in_a_given_range {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Enter a range in which you want random number");
        int min = scn.nextInt();
        int max = scn.nextInt();
        int a = (int) (Math.random() * (max - min + 1) + min);
        System.out.println("Random value between " + min + " and " + max + " is : " + a);
        scn.close();
    }
}
