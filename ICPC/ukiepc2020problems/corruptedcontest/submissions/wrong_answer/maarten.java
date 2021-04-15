import java.io.*;
import java.util.*;

public class maarten {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        new maarten().run(sc);
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
        if (p != 0)
            System.out.println("ambiguous");
        else {
            for (int solve : solves) {
                System.out.println(solve);
            }
        }
    }
}
