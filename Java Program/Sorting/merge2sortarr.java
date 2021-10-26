import java.util.*;

public class merge2sortarr {

    
    public static int[] mergearray(int [] arr1, int[] arr2)
    {
        int []res=new int[arr1.length+arr2.length];
        int i=0;
        int j=0;
        int k=0;
        while(i<arr1.length && j<arr2.length)
        {
            if( arr1[i]<arr2[j] )
            {
                res[k]=arr1[i];
                i++;
                k++;
            }
            else
            {
                res[k]=arr2[j];
                j++;
                k++;
            }
        }
        // if there is still elements left in either arr1 or arr2 then these 2 statements run . they will fill the rest of the spaces with elements , from the array which has maximum no of elements.
        while(i<arr1.length)
        {
            res[k]=arr1[i];
            i++;
            k++;
        }
        while(j<arr1.length)
        {
            res[k]=arr2[j];
            j++;
            k++;
        }
return res;
    }
    public static void main(String [] args)
    {
        Scanner scn =new Scanner(System.in);
        int n1=scn.nextInt();
        int n2=scn.nextInt();
        int []arr1=new int[n1];
        int []arr2=new int[n2];
        for(int i =0;i<arr1.length;i++)
        {
            arr1[i]=scn.nextInt();
        }
        System.out.println("enter next array-");
        for(int j =0;j<arr1.length;j++)
        {
            arr2[j]=scn.nextInt();
        }
        int []ans= mergearray(arr1,arr2);
        for(int k=0;k<ans.length;k++)
        {
            System.out.print(ans[k]+" ");
        } 
    }
}
