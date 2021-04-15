import java.io.*;
import java.util.*;

public class maarten_only_when_ends_with_0 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        new maarten_only_when_ends_with_0().run(sc);
        sc.close();
    }

    public void run(Scanner sc) {
        int n = sc.nextInt(), p = sc.nextInt();
        int[] minutes = new int[n];
        for (int i = 0; i < n; i++) {
            minutes[i] = sc.nextInt();
        }
        int[] solves = new int[n];
        int prev = minutes[0];
        if (prev == 0) {
            for (int i = 0; i < n; i++) {
                System.out.println(0);
            }
            return;
        }
        solves[0] = p;
        for (int i = 1; i < n; i++) {
            if (minutes[i] < prev) {
                p--;
            }
            solves[i] = p;
            prev = minutes[i];
        }
        if (p == 0) {
            for (int solve : solves) {
                System.out.println(solve);
            }
        } else {
            System.out.println("ambiguous");
        }
    }
}
