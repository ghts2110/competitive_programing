import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    static BigInteger[] dp = new BigInteger[5002];

    public static void main(String[] args) {
        for(int i = 0; i != 5002; i++){
            dp[i] = BigInteger.ZERO;
        }
        dp[1] = BigInteger.ONE;
        dp[2] = BigInteger.ONE;

        Scanner sc = new Scanner(System.in);
        int b;

        while(sc.hasNext()){
            b = sc.nextInt();
            System.out.println(fi(b));
        }

    }

    public static BigInteger fi(int b){
        if(!dp[b].equals(BigInteger.ZERO)){
            return dp[b];
        }
        return dp[b] = (fi(b-1).add(fi(b-2)));
    }
}
