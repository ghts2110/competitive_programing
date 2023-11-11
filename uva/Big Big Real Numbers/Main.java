import java.math.BigDecimal;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigDecimal bg1 = BigDecimal.ZERO, bg2 = BigDecimal.ZERO;

        int t;
        t = sc.nextInt();
        while(t!=0){
            t--;
            bg1 = sc.nextBigDecimal();        
            bg2 = sc.nextBigDecimal();

            BigDecimal asw = bg1.add(bg2);  

            String s = asw.toString();
            int index = 0;

            for(int i = s.length()-1; i != -1; i--){
                if(s.charAt(i) != '0' || s.charAt(i-1) == '.'){
                    index = i;
                    break;
                }
            }

            String save = "";
            for(int i = 0; i <= index; i++){
                save += s.charAt(i);
            }

            System.out.println(save);
        }
       
    }
}