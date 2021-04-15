import java.math.BigInteger;
import java.util.Scanner;

public class boas_quadratic_eq_bigint {

    public static BigInteger sqrt(BigInteger val) {
        if(val.equals(BigInteger.ZERO)) {
            return BigInteger.ZERO;
        }
        BigInteger half = BigInteger.ZERO.setBit(val.bitLength() / 2);
        BigInteger cur = half;

        while (true) {
            BigInteger tmp = half.add(val.divide(half)).shiftRight(1);

            if (tmp.equals(half) || tmp.equals(cur))
                return tmp;

            cur = half;
            half = tmp;
        }
    }

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

        BigInteger d = BigInteger.valueOf(sumwh).multiply(BigInteger.valueOf(sumwh)).subtract(BigInteger.valueOf(prodwh).multiply(BigInteger.valueOf(4)));

        if(d.compareTo(BigInteger.ZERO) < 0) {
            System.out.println("impossible");
            sc.close();
            return;
        }

        BigInteger sqrt_d_bi = sqrt(d);

        //double sqrt_d = Math.sqrt(Math.pow(sumwh, 2) - 4*prodwh);
        double sqrt_d = sqrt_d_bi.doubleValue();

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
