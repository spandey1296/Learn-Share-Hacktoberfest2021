public class AdditivePersistence {
    
    public static long solve(long val){
        if(val <= 9){
            return 0;
        }
        long sol = 0;
        while(val > 0){
            sol += val%10;
            val /= 10;
        }
        return 1 + solve(sol);
    }
    public static void main(String args[]) {
        System.out.println(solve(39));
        System.out.println(solve(99));
        System.out.println(solve(199));
        System.out.println(solve(9812));
        System.out.println(solve(2293));
    }
}

// OUTPUT OF PROGRAM IS
// 2
// 2
// 3
// 2
// 2
