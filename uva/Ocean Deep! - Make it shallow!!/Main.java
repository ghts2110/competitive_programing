import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String s;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            s = sc.nextLine();
            while(true){
                String save;
                if(s.charAt(s.length()-1) == '#'){
                    break;
                }
                save = sc.nextLine();
                s += save;
            }

            BigInteger sum = BigInteger.ZERO;
            int index = 0;
            for(int i = s.length()-2; i >= 0; i--){
                BigInteger num = BigInteger.valueOf(s.charAt(i) - '0');
                BigInteger two = BigInteger.valueOf(2);
                BigInteger pot = two.pow(index);
                BigInteger mult = pot.multiply(num);
                sum = sum.add(mult);
                index++;
            }   

            BigInteger finalnum = BigInteger.valueOf(131071);
            if(sum.mod(finalnum).equals(BigInteger.ZERO)){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
        }

    }
}
