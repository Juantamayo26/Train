import java.io.*;
import java.util.*;
import java.math.*;

public class freek {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<Integer> p = new ArrayList<>();
        List<Integer> d = new ArrayList<>();
        List<Integer> ss = new ArrayList<>();
        ss.add(0);
        for (int i = 0; i < k; i++)
            p.add(sc.nextInt());
        for (int i = 0; i < k; i++)
            d.add(sc.nextInt());
        int mini = 0, total = 0;
        for (int i = 1; i <= k; i++) {
            int s = ss.get(i - 1) + d.get(i - 1) - p.get(i - 1);
            mini = Math.min(mini, s);
            total += s;
            ss.add(s);
        }
        for (int i = 0; i <= k; i++)
            ss.set(i, ss.get(i) - mini);
        total -= mini * (k + 1);
        int t = 0, i = 0;
        while (t < total) {
            if (i == 0) {
                if (ss.get(i) == 0 || p.get(i) < 3) {
                    i++;
                }
                else {
                    int s = Math.min(ss.get(i), p.get(i) - 2);
                    p.set(i, p.get(i) - s);
                    ss.set(i, ss.get(i) - s);
                    t += s;
                    i++;
                }
            }
            else if (i < k) {
                if (ss.get(i) == 0 || p.get(i) - p.get(i - 1) < 4) {
                    i++;
                }
                else {
                    int s = Math.min(ss.get(i), (p.get(i) - p.get(i - 1) - 2) / 2);
                    p.set(i - 1, p.get(i - 1) + s);
                    p.set(i, p.get(i) - s);
                    ss.set(i, ss.get(i) - s);
                    t += s;
                    i--;
                }
            }
            else { // i == k
                if (ss.get(i) == 0 || n - p.get(i - 1) < 2) {
                    System.out.println("impossible");
                    sc.close();
                    return;
                }
                else {
                    int s = Math.min(ss.get(i), n - p.get(i - 1) - 1);
                    p.set(i - 1, p.get(i - 1) + s);
                    ss.set(i, ss.get(i) - s);
                    t += s;
                    i--;
                }
            }
        }
        System.out.println(Integer.toString(total));
        sc.close();
    }
}
