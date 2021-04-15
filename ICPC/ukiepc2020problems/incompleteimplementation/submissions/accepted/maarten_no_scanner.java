import java.io.*;
import java.util.*;

public class maarten_no_scanner {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        new maarten_no_scanner().run(br);
        br.close();
    }

    public void run(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        String[] split = br.readLine().split(" ");
        for (int i = 0; i < split.length; i++) {
            arr[i] = Integer.parseInt(split[i]);
        }

        System.out.println(3);

        int[] first_run = new int[n / 2];
        for (int i = 0; i < n / 4; i++) {
            first_run[i] = i;
        }
        Pair[] toSort = new Pair[3 * n / 4];
        for (int i = n / 4; i < n; i++) {
            toSort[i - n / 4] = new Pair(i, arr[i]);
        }
        Arrays.sort(toSort);
        int k = n / 4;
        for (Pair pair : toSort) {
            first_run[k++] = pair.i;
            if (k >= n / 2)
                break;
        }
        print(first_run);
        updateArray(arr, first_run);

        int[] second_run = new int[n / 2];
        for (int i = 0; i < n / 4; i++) {
            second_run[i] = i + n / 4;
        }
        Pair[] listToSort = new Pair[n / 2];
        for (int i = n / 2; i < n; i++) {
            listToSort[i - n / 2] = new Pair(i, arr[i]);
        }
        Arrays.sort(listToSort);
        k = n / 4;
        for (Pair pair : listToSort) {
            second_run[k++] = pair.i;
            if (k >= n / 2)
                break;
        }
        print(second_run);

        int[] third_run = new int[n / 2];
        for (int i = 0; i < n / 2; i++) {
            third_run[i] = i + n / 2;
        }
        print(third_run);
    }

    private void print(int[] arr) {
        StringJoiner joiner = new StringJoiner(" ");
        for (int i : arr) {
            joiner.add(Integer.toString(i + 1));
        }
        System.out.println(joiner.toString());
    }

    private void updateArray(int[] arr, int[] run) {
        Arrays.sort(run);
        Pair[] list = new Pair[run.length];
        int k = 0;
        for (int i : run) {
            list[k++] = new Pair(i, arr[i]);
        }
        Arrays.sort(list);
        for (int i = 0; i < list.length; i++) {
            arr[run[i]] = list[i].value;
        }
    }

    private static class Pair implements Comparable<Pair> {
        int i, value;

        public Pair(int i, int value) {
            this.i = i;
            this.value = value;
        }

        @Override
        public int compareTo(Pair other) {
            return Integer.compare(value, other.value);
        }
    }
}
