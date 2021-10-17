import java.util.Scanner;

public class GlobalAlignment {
    //code for global alginment matrix, and alignment
    public static int max(int a,int b,int c){
        return Math.max(a,Math.max(b,c));
    }
    public static String rev(String s){
        String temp = "";
        for(int i=s.length()-1;i>=0;--i){
            temp+=s.charAt(i);
        }
        return temp;
    }
    public static void printmatrix(int[][] dp){
        for (int[] ints : dp) {
            for (int j = 0; j < dp[0].length; ++j) {
                System.out.print(ints[j]);
                System.out.print(" \t");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        //input are two strings for example, ATCG and ACGG
        Scanner in = new Scanner(System.in);
        String ref = in.next();
        String obs = in.next();
        int reflen = ref.length();
        int obslen = obs.length();

        int dp[][] = new int[obslen+1][reflen+1];
        int deletiongap = -2;
        int insertiongap = -2;
        int match = 1;
        int mismatch = -1;
        //i for obs , and j will be for ref

        for(int i=0;i<=reflen;++i){
            dp[0][i] = i*insertiongap;
        }
        for(int i=0;i<=obslen;++i){
            dp[i][0] = i*deletiongap;
        }

        for(int i=1;i<=obslen;++i){
            for(int j=1;j<=reflen;++j){
                int add = ref.charAt(j-1)==obs.charAt(i-1) ? match : mismatch;
                dp[i][j] = max(dp[i-1][j]+deletiongap, dp[i][j-1]+insertiongap, dp[i-1][j-1]+ add);
            }
        }
        System.out.println("GLOBAL ALIGNMENT MATRIX:");
        System.out.println();
        printmatrix(dp);
        String a1 = "";
        String a2 = "";
        int j = reflen;
        int i = obslen;

        while (i!=0 && j!=0){
            int add = ref.charAt(j-1) == obs.charAt(i-1) ? match : mismatch;
            if(dp[i][j] == dp[i-1][j-1] + add){
                a1 += ref.charAt(j-1);
                a2 += obs.charAt(i-1);
                //System.out.println("MOVE DIAGONAL");
                i--;
                j--;
            }
            else if(dp[i][j] == dp[i-1][j] + deletiongap){
                a2 += obs.charAt(i-1);
                a1 += "-";
                i--;
                //System.out.println("MOVE UP");
            }
            else if(dp[i][j] == dp[i][j-1] + insertiongap){
                a1 += ref.charAt(j-1);
                a2 += "-";
                j--;
                //System.out.println("MOVE LEFT");
            }
        }
        if(i == 0){
            while (j != 0){
                a2 += "-";
                a1 += ref.charAt(j-1);
                //System.out.println("MOVE LEFT");
                j--;
            }
        }
        if(j == 0) {
            while (i != 0) {
                a1 += "-";
                a2 += obs.charAt(i - 1);
                //System.out.println("MOVE UP");
                i--;
            }
        }
        System.out.println();
        System.out.println("ALGINMENT FINAL:");
        System.out.println();
        a1 = rev(a1);
        a2 = rev(a2);
        String str = "";
        for(int x=0;x<a1.length();++x){
            if(a1.charAt(x) == '-' || a2.charAt(x) == '-'){
                str+=" ";
            }
            else if(a1.charAt(x) == a2.charAt(x)){
                str+="|";
            }
            else{
                str+=" ";
            }
        }
        System.out.println(a1);
        System.out.println(str);
        System.out.println(a2);
    }
}
