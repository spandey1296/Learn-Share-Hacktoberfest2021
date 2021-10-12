public class SumOfSquares
{
 public static void main(final String[] args)
 {
  double sum = 0;
  int[] nums = {1,2,3,4,5,6,7,8,9};
  for (int i : nums){
   sum += i * i;
  }
  System.out.println("The sum of the squares is: " + sum);
 }
}
