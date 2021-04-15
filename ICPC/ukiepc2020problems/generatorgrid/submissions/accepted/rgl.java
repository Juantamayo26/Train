import java.io.*;
import java.util.*;
import java.util.stream.*;

public class rgl {
  final BufferedReader br;

  public static void main(String[] args) {
    new rgl().go();
  }

  public rgl() {
     br = new BufferedReader(new InputStreamReader(System.in));
  }

  int[] read() {
    try {
      return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    } catch (IOException e) {
      throw new AssertionError("Malformed input data");
    }
  }

  void go() {
    final int[] nm = read();
    final Graph g = new Graph(nm[0]+1);
    for (int i = 0; i < nm[1]; i++) {
      final int[] cx = read();
      g.add(nm[0], cx[0]-1, cx[1]);
    }
    int[] costs = read();
    for (int i = 0; i < nm[0]; i++) {
      g.add(i, (i+1) % (nm[0]), costs[i]);
    }
    System.out.println(g.mst());
  }

  private static class Graph {
    final int n;
    final List<Map<Integer, Long>> edge;

    public Graph(final int n) {
      this.n = n;
      this.edge = new ArrayList<>();
      for (int i = 0; i < n; i++) {
        this.edge.add(new HashMap<Integer, Long>());
      }
    }

    public void add(int a, int b, long c) {
      if (!edge.get(a).containsKey(b) || edge.get(a).get(b) > c) {
        edge.get(a).put(b, c);
        edge.get(b).put(a, c);
      }
    }

    public long mst() {
      final PriorityQueue<Map.Entry<Integer, Long>> todo =
          new PriorityQueue<>(n, Map.Entry.comparingByValue());
      todo.add(new AbstractMap.SimpleEntry<Integer, Long>(0, 0L));
      final boolean[] visited = new boolean[n];

      long cost = 0;
      while (!todo.isEmpty()) {
        final Map.Entry<Integer, Long> t = todo.poll();
        final int x = t.getKey();
        final long w = t.getValue();
        if (!visited[x]) {
          visited[x] = true;
          cost += w;
          for (Map.Entry<Integer, Long> e : edge.get(x).entrySet()) {
            if (!visited[e.getKey()]) {
              todo.add(e);
            }
          }
        }
      }
      return cost;
    }
  }
}

