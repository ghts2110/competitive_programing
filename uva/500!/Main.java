import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num;
        while (sc.hasNext()) {
            num = sc.nextInt();
            System.out.println(num + "!");
            BigInteger cont = BigInteger.ONE;
        
            for (int c = num; c != 0; c--){
                cont = cont.multiply(BigInteger.valueOf(c));
            }

            System.out.println(cont);
        }
    }
}