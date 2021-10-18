import java.util.Scanner;

// When a number (3 digit or more) is multiplied by 2 and 3 and when both these products are concatenenated with the original number then
// it result in all digit from 1 to 9 
public class Fascinating_number {
    public static void main(String[] args) {
        System.out.println("Enter a number");
        Scanner scn = new Scanner(System.in);
        int num = scn.nextInt();
        int n2, n3;
        n2 = num * 2;
        n3 = num * 3;
        String str = num + "" + n2 + n3;
        boolean flag = true;
        // System.out.println(str);
        for (char c = '1'; c <= '9'; c++) {
            int count = 0;
            for (int i = 0; i < str.length(); i++) {
                char ch = str.charAt(i);
                if (ch == c) {
                    count++;
                }
            }
            if (count > 1 || count == 0) {
                flag = false;
                break;
            }

        }
        if (flag) {
            System.out.println(str + " is a Fascinating number");
        } else {
            System.out.println(str + " is not a Fascinating number");
        }

    }
}
