import java.util.Scanner;
import java.math.BigInteger;

public class Jus_the_Facts {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int num;
        while (sc.hasNext()) {
            num = sc.nextInt();
            BigInteger cont = BigInteger.ONE;
            for (int c = 2; c <= num; c++) {
                cont = cont.multiply(BigInteger.valueOf(c));
                while (cont.mod(BigInteger.TEN).equals(BigInteger.ZERO)) {
                    cont = cont.divide(BigInteger.TEN);
                }
            }

            String contStr = cont.toString();
            char asw = contStr.charAt(contStr.length() - 1);

            System.out.printf("%5d -> %c%n", num, asw);
        }
    }
}

