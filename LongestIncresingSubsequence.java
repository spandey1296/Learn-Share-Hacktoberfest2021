
import java.util.Arrays;


public class longest_Inc_Seq {
    public static void main(String[] args) {
        int arr[]={1,2,1,2,3,7,6,7,8,9};
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
//        System.out.println(Arrays.toString(A));
//        System.out.println(Arrays.toString(T));
   // find maxIndex where ans is locate
       int maxIndex=0;
       for(int i=0;i<T.length;i++)
       {
           if(T[i]>T[maxIndex])
               maxIndex=i;
       }
       
      // print the elements
//       int y=-1;
//       for(int i=0;i<T.length;i++)
//       {
//           if(T[i]>y)
//           {
//               System.out.print(arr[i]+" ");
//               y=T[i];
//           }
//       }
//        System.out.println();
//       
       
       
       
        return T[maxIndex];
    }
}
