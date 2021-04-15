import java.io.*;
import java.util.*;

public class maarten {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        new maarten().run(sc);
        sc.close();
    }

    public void run(Scanner sc) {
        int h = sc.nextInt();
        int w = sc.nextInt();
        sc.nextLine();

        int[][] heights = new int[h][w];
        for (int y = 0; y < h; y++) {
            String[] line = sc.nextLine().split(" ");
            for (int x = 0; x < w; x++) {
                heights[y][x] = Integer.parseInt(line[x]);
            }
        }

        PriorityQueue<Position> pq = new PriorityQueue<>(Comparator.comparingInt(a -> -a.z));
        boolean[][] done = new boolean[h][w];
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (heights[y][x] > 1) {
                    pq.add(new Position(x, y, heights));
                } else { // No elevators needed for ground floor (z=1) or outside (z=0)
                    done[y][x] = true;
                }
            }
        }

        int ans = 0;
        while (!pq.isEmpty()) {
            Position p = pq.poll();
            if (done[p.y][p.x])
                continue;
            floodFill(h, w, p, heights, done);
            ans++;
        }

        System.out.println(ans);
    }

    private void floodFill(int h, int w, Position p, int[][] heights, boolean[][] done) {
        Stack<Position> floodStack = new Stack<>();
        floodStack.add(p);
        while (!floodStack.isEmpty()) {
            Position current = floodStack.pop();
            int x = current.x;
            int y = current.y;
            int z = current.z;
            done[y][x] = true;

            if (x > 0 && !done[y][x - 1])
                if (z >= heights[y][x - 1])
                    floodStack.add(new Position(x - 1, y, heights));

            if (x < w - 1 && !done[y][x + 1])
                if (z >= heights[y][x + 1])
                    floodStack.add(new Position(x + 1, y, heights));

            if (y > 0 && !done[y - 1][x])
                if (z >= heights[y - 1][x])
                    floodStack.add(new Position(x, y - 1, heights));

            if (y < h - 1 && !done[y + 1][x])
                if (z >= heights[y + 1][x])
                    floodStack.add(new Position(x, y + 1, heights));
        }
    }

    static class Position {
        final int x;
        final int y;
        final int z;

        public Position(int x, int y, int[][] heights) {
            this.x = x;
            this.y = y;
            this.z = heights[y][x];
        }
    }
}
