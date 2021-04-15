import java.util.Scanner;

public class boas_quadratic_eq_no_bigint {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long c = sc.nextLong();
        long e = sc.nextLong();
        long m = sc.nextLong();

        if(c != 4) {
            System.out.println("impossible");
            sc.close();
            return;
        }

        if(e % 2 != 0) {
            System.out.println("impossible");
            sc.close();
            return;
        }

        long sumwh = e/2 + 4;
        long prodwh = m + 2*sumwh - 4;

        double d = Math.pow(sumwh, 2) - 4*prodwh; 

        if(d < 0) {
            System.out.println("impossible");
            sc.close();
            return;
        }

        double sqrt_d = Math.sqrt(d);

        double w_1_d = (sumwh + sqrt_d) / 2;
        double w_2_d = (sumwh - sqrt_d) / 2;

        long w_1 = Math.round(w_1_d);
        long h_1 = sumwh - w_1;
        
        long w_2 = Math.round(w_2_d);
        long h_2 = sumwh - w_2;
        
        if(w_1 >= 2 && h_1 >= 2 && w_1 + h_1 == sumwh && prodwh % w_1 == 0 && prodwh / w_1 == h_1) {
            System.out.format("%d %d\n",w_1, h_1);
        } else if(w_2 >= 2 && h_2 >= 2 && w_2 + h_2 == sumwh && prodwh % w_2 == 0 && prodwh / w_2 == h_2) {
            System.out.format("%d %d\n",w_2, h_2);
        } else {
            System.out.println("impossible");
        }
        

        sc.close();
    }
}
