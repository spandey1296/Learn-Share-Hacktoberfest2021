import java.util.Scanner;
public class Factorial
{
    public static void main(String args[])
    {
     Scanner sc=new Scanner(System.in);
     System.out.println("Enter a number whose factorial is to be calculated");
     int n =sc.nextInt();
     int fact=1;
     for(i=1;i<=n;i++)
     {
          fact=fact*i;
     }
     System.out.println("Factorial is"+fact);


    }
}