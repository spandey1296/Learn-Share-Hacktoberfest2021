import java.util.Scanner;

class QuickSortRandom
{
	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter size:");
		int Size=sc.nextInt();
		int[] input=new int[Size];
		System.out.println("Enter values:");
		for(int i=0;i<Size;i++) input[i]=sc.nextInt();
		quickSort(input, 0, Size-1);
		printMethod(input);
	}

	private static void quickSort(int[] arr, int beg, int end)
	{
		if(beg<end)
		{
			int index=randomIndex(arr, beg, end);
			quickSort(arr, beg, index-1);
			quickSort(arr, index+1, end);
		}
	}

	private static int randomIndex(int[] arr, int beg, int end)
	{
		int length=end-beg+1;
		int pivotIndex=beg+(int)Math.floor(Math.random()*length);

		int temp=arr[end];
		arr[end]=arr[pivotIndex];
		arr[pivotIndex]=temp;

		return partitionMethod(arr, beg, end);
	}
		

	private static int partitionMethod(int[] arr, int beg, int end)
	{
		int pivot=arr[end];
		int index=beg;

		for(int i=beg;i<end;i++)
		{
			if(arr[i]<=pivot)
			{
				int temp=arr[index];
				arr[index]=arr[i];
				arr[i]=temp;
				index++;
			}
		}
		int temp=arr[index];
		arr[index]=arr[end];
		arr[end]=temp;

		return index;
	}

	private static void printMethod(int[] arr)
	{
		System.out.println("Sorting values:");
		for(int x: arr) System.out.println(x);
	}
}
