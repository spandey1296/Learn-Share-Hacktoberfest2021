
import java.util.*;


public class longest_Inc_Seq {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        //Enter the number of elements
        int n = sc.nextInt();
        int arr[]=new int[n];
        //Enter the elements
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Maximum Length is ");
        System.out.println(find(arr));
    }
    static int find(int[] arr)
    {  int T[]=new int[arr.length];
       int A[]=new int[arr.length];
       for(int i=0;i<arr.length;i++)
       {
           T[i]=1;
           A[i]=i;
       }
       
       for(int i=1;i<arr.length;i++)
       {
           for(int j=0;j<i;j++)
           {
               if(arr[i]>arr[j])
               {
                   if(T[j]+1>T[i])
                   {
                       T[i]=T[j]+1;
                   }
               }
           }
       }
       int maxIndex=0;
       for(int i=0;i<T.length;i++)
       {
           if(T[i]>T[maxIndex])
               maxIndex=i;
       }
  
        return T[maxIndex];
    }
}
