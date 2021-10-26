
import java.util.Scanner;

class Prime_Superior {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of inuts");
        int t= sc.nextInt();
        System.out.println("Enter the inputs");
        for(int i=0;i<t;i++){
            int n= sc.nextInt();

            int c=0;
            for(int div=2; div*div<=n;div++){
                if (n%div==0){
                    c++;
                }
            }
            if (c == 0){
                System.out.println("prime");
            }
            else{
                System.out.println("not prime");
            }
        }
        sc.close();
    }
}
