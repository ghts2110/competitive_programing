import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger num;
        String s;

        while(true){
            s = sc.next();
            num = new BigInteger(s);
            if(num.equals(BigInteger.valueOf(0))){
                break;
            }

            if(num.mod(BigInteger.valueOf(11)).equals(BigInteger.valueOf(0))){
                System.out.println(s + " is a multiple of 11.");
            }else{
                System.out.println(s + " is not a multiple of 11.");
            }
        }
    }
}