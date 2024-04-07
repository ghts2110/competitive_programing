import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    
    static BigInteger[] memo = new BigInteger[5001];

    public static BigInteger dp(int f){
        if(!memo[f].equals(BigInteger.valueOf(-1))){
            return memo[f];
        }

        return memo[f] = dp(f-1).add(dp(f-2));
    }
    public static void main(String[] args) {

        for(int i = 0; i != 5001; i++){
            memo[i] = BigInteger.valueOf(-1);
        }

        memo[0] = BigInteger.ZERO;
        memo[1] = BigInteger.ONE;

        Scanner s = new Scanner(System.in);   
        while(s.hasNextInt()){
            int f = s.nextInt();
            System.out.println("The Fibonacci number for "+f+" is " + dp(f));
        }
    }
}