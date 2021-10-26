import java.util.Scanner;

class QuickSortHorae
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
			int index=partitionMethod(arr, beg, end);
			quickSort(arr, beg, index);
			quickSort(arr, index+1, end);
		}
	}

	private static int partitionMethod(int[] arr, int beg, int end)
	{
		int pivot=arr[beg];
		int i=beg-1;
		int j=end+1;

		while(true)
		{
			do{
				i++;
			}while(arr[i]<pivot);

			do{
				j--;
			}while(arr[j]>pivot);

			if(i>=j) return j;

			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}

	private static void printMethod(int[] arr)
	{
		System.out.println("Sorting values:");
		for(int x: arr) System.out.println(x);
	}

}
