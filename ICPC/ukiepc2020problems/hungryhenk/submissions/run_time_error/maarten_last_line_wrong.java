import java.util.*;

public class maarten_last_line_wrong {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; i++) {
            sc.nextLine();
        }
        // Throws a NoSuchElementException because we're out of input
        System.out.println(String.join("\n", sc.nextLine().trim().split(" ")));
    }
}
