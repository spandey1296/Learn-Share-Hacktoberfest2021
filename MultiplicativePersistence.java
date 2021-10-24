public class MultiplicativePersistence {
    
    public static long findMultiplicativePersistence(long value){
        if(value <= 9){
            return 0;
        }
        long sum = 1;
        while(value > 0){
            sum *= value%10;
            value /= 10;
        }
        return 1 + findMultiplicativePersistence(sum);
    }
    public static void main(String args[]) {
        System.out.println(findMultiplicativePersistence(64));
        System.out.println(findMultiplicativePersistence(216));
        System.out.println(findMultiplicativePersistence(6457));
        System.out.println(findMultiplicativePersistence(98821));
        System.out.println(findMultiplicativePersistence(2265));
        System.out.println(findMultiplicativePersistence(7654));
    }
}
