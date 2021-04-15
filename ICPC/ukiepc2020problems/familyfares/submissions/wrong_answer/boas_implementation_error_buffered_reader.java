import java.util.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


class Pair<S extends Comparable<S>, T extends Comparable<T>> implements Comparable<Pair<S, T>> {
    S first;
    T second;
    
    Pair(S f, T s) {
        first = f;
        second = s;
    }

    @Override
    public int compareTo(Pair<S, T> o) {
        int t = first.compareTo(o.first);
        if (t == 0) return second.compareTo(o.second);
        return t;
    }
    
    @Override
    public int hashCode() {
        return (31 + first.hashCode()) * 31 + second.hashCode();
    }
    
    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Pair)) return false;
        if (o == this) return true;
        Pair p = (Pair) o;
        return first.equals(p.first) && second.equals(p.second);
    }
    
    @Override
    public String toString() {
        return "Pair{" + first + ", " + second + "}";
    }
}

public class boas_implementation_error_buffered_reader {

    

    static HashMap<Integer, ArrayList<Pair<Integer, Integer>>> adjList = new HashMap<>();
    static HashMap<Integer, BitSet> people = new HashMap<>();
    static int n;
    static int m;
    static int p;
    static int g;
    static HashMap<Integer, ArrayList<Pair<Integer, Integer>>> dagAdjList;
    static HashSet<Integer> visited = new HashSet<>();

    static HashMap<Integer, Long> dijkstra(int source) {
        HashMap<Integer, Long> dist = new HashMap<>();
        for(int i=0; i<n; i++) {
            dist.put(i, Long.MAX_VALUE);
        }
        dist.put(source, (long) 0);
        PriorityQueue<Pair<Long, Integer>> pq = new PriorityQueue<>();

        pq.add(new Pair<>(dist.get(source), source));

        while(!pq.isEmpty()) {
            Pair<Long, Integer> node = pq.remove();
            long cost = node.first;
            int from = node.second;

            if(cost > dist.get(from))
                continue;

            for(Pair<Integer, Integer> neighbour : adjList.get(from)) {
                int to = neighbour.first;
                long newCost = dist.get(from) + neighbour.second;

                if(newCost < dist.get(to)) {
                    dist.put(to, newCost);
                    pq.add(new Pair<>(newCost, to));
                }
            }
        }

        return dist;

    }

    static HashMap<Integer, ArrayList<Pair<Integer, Integer>>> shortestPathDAG(HashMap<Integer, Long> dist) {
        

        HashMap<Integer, ArrayList<Pair<Integer, Integer>>> ldagAdjList = new HashMap<>();

        for(int i=0; i<n; i++) {
            ldagAdjList.put(i, new ArrayList<>());
        }

        for(int node=0; node<n; node++) {
            for(Pair<Integer, Integer> neighbour : adjList.get(node)) {
                if(dist.get(node) + neighbour.second <= dist.get(neighbour.first)) {
                    ldagAdjList.get(node).add(new Pair<>(neighbour.first, neighbour.second));
                }
            }
        }

        return ldagAdjList;
    }

    static HashMap<Integer, BitSet> peopleAlongRoute = new HashMap<>();

    static void dfs(int node) {
        visited.add(node);

        BitSet alongRoute = (BitSet) people.get(node).clone();

        for(Pair<Integer, Integer> neighbour : dagAdjList.get(node)) {
            if(!visited.contains(neighbour.first)) {
                dfs(neighbour.first);
                alongRoute.or(peopleAlongRoute.get(neighbour.first));
            }
        }
        peopleAlongRoute.put(node, alongRoute);
    }

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader( 
                              new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());
        g = Integer.parseInt(st.nextToken());

        for(int i=0; i<n; i++) {
            people.put(i, new BitSet(100));
        }

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<p; i++) {
            int station = Integer.parseInt(st.nextToken()) - 1;
            int person = i;
            BitSet stationBitSet = people.get(station);
            stationBitSet.set(person, true);
        }

        

        for(int i=0; i<n; i++) {
            adjList.put(i, new ArrayList<>());
        }

        for(int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            adjList.get(a).add(new Pair<>(b, c));
            adjList.get(b).add(new Pair<>(a, c));
        }

        HashMap<Integer, Long> dist = dijkstra(0);


        dagAdjList = shortestPathDAG(dist);

        dfs(0);

        long separateCost = 0;
        for(int i=0; i<n; i++) {
            separateCost += dist.get(i) * people.get(i).cardinality();
        }

        long minCost = separateCost;
        for(int i=0; i<n; i++) {
            long groupCost = separateCost + (g - dist.get(i)) * peopleAlongRoute.get(i).cardinality();
            minCost = Math.min(minCost, groupCost);
        }
        System.out.println(minCost);

    }
}
