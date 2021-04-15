import java.io.*;
import java.util.*;

/**
 * Similarly to ludo-k5.cpp, the first two palindromes are calculated greedily and the last three with brute force.
 */
public class maarten_greedy_2_bruteforce_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        new maarten_greedy_2_bruteforce_3().run(sc);
        sc.close();
    }

    public void run(Scanner sc) {
        long n = sc.nextLong();
        System.err.println(n);
        List<Long> res = new ArrayList<>();
        while (n > 0) {
            if (n == reverse(n)) {
                res.add(n);
                break;
            }
            String str = Long.toString(n);
            if (exp10(str.length() - 1) == n) { // If n is a power of 10
                res.add(n - 1);
                res.add(1L);
                break;
            }
            if (n < 200_000) {
                res.addAll(bruteForce(n));
                break;
            }
            long palindrome = getPalindrome(n);
            while (palindrome > n) {
                palindrome = getPalindrome(n - exp10(str.length() / 2));
            }
            n -= palindrome;
            res.add(palindrome);
        }
        System.out.println(res.size());
        res.forEach(System.out::println);
    }

    private long exp10(int i) {
        if (i == 0) return 1;
        if (i == 1) return 10;
        return exp10(i / 2) * exp10(i - i / 2);
    }

    private long getPalindrome(long n) {
        String str = Long.toString(n);
        char[] c1 = str.toCharArray();
        int length = c1.length;
        char[] c2 = new char[length];
        for (int i = 0; i < length; i++) {
            c2[i] = c1[Integer.min(length - i - 1, i)];
        }
        String str2 = new String(c2);
        return Long.parseLong(str2);
    }

    private long reverse(long n) {
        String str = Long.toString(n);
        char[] c1 = str.toCharArray();
        int length = c1.length;
        char[] c2 = new char[length];
        for (int i = 0; i < length; i++) {
            c2[i] = c1[length - i - 1];
        }
        String str2 = new String(c2);
        return Long.parseLong(str2);
    }

    private List<Long> bruteForce(long n) {
        List<Long> palindromes = new ArrayList<>();
        for (long i = n; i >= 0; i--) {
            if (i == reverse(i))
                palindromes.add(i);
        }
        for (long p : palindromes) {
            for (long q : palindromes) {
                long r = n - p - q;
                if (r >= 0 && r == reverse(r)) {
                    List<Long> res = new ArrayList<>();
                    res.add(p);
                    res.add(q);
                    if (r > 0)
                        res.add(r);
                    return res;
                }
            }
        }
        return null;
    }
}
