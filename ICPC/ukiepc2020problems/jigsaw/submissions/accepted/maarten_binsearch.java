import java.io.*;
import java.util.*;

public class maarten_binsearch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        new maarten_binsearch().run(sc);
        sc.close();
    }

    public void run(Scanner sc) {
        long c = sc.nextLong(), e = sc.nextLong(), m = sc.nextLong();

        if (c != 4 || e % 2 != 0) {
            System.out.println("impossible");
            return;
        }

        long n = c + e + m;
        // w * h == n
        // => w = n / h
        // 2w + 2h - 8 = e
        // => h = (e + 8 - 2w) / 2
        long low = 2, high = e / 4 + 2;
        while (low <= high) {
            long w = (low + high) / 2;
            long h = (e + 8 - 2 * w) / 2;
            boolean w_times_h_overflows = Long.numberOfLeadingZeros(w) + Long.numberOfLeadingZeros(h) < 66;
            if (w_times_h_overflows || w * h > n) { // w > n / h
                high = w - 1;
            } else if (w * h < n) { // w < n / h
                low = w + 1;
            } else { // w == n / h
                System.out.println(w + " " + h);
                return;
            }
        }

        System.out.println("impossible");
    }
}
