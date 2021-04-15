import java.util.*;

public class maarten_last_line {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
        }
        System.out.println(String.join("\n", sc.nextLine().trim().split(" ")));
    }
}
