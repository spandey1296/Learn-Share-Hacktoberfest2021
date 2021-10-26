// find max and min value in array:

class FindMaxMinIntoArray {
	
	public static void main(String[] args) {
		int arr[] = {3,1,5,6,2,7,4,8};
		
		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		
		for(int val : arr) {
			max = Math.max(val, max);
			min = Math.min(val, min);
		}
			
		System.out.println("MAX VALUE: "+max);
		System.out.println("MIN VALUE: "+min);
	}
	
}