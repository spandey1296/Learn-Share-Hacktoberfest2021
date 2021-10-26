/* find only element into array which
   is not repeated
*/

class FindDuplicate {
	
    public static void main(String[] args) {
        int arr[] = {5,4,1,4,3,5,1};

        /* @method 1 : XOR property
           TC---> o(n)
        */
        int res =0;
		
        for(int i=0;i<arr.length;i++)
            res= res^arr[i];
        
        System.out.println(res);

    }
}