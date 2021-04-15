// Slower than boas_scanner in two ways:
// - No precomputation is done for the calculation of minCost
// - A DFS is called for every starting station instead of just once

import java.util.*;


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

public class boas_slower_scanner {

    

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
                    ldagAdjList.get(neighbour.first).add(new Pair<>(node, neighbour.second));
                }
            }
        }

        return ldagAdjList;
    }

    static HashMap<Integer, BitSet> peopleAlongRoute = new HashMap<>();

    static void dfs(int node, int person) {
        
        peopleAlongRoute.get(node).set(person, true);

        for(Pair<Integer, Integer> neighbour : dagAdjList.get(node)) {
            dfs(neighbour.first, person);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        p = sc.nextInt();
        g = sc.nextInt();

        for(int i=0; i<n; i++) {
            people.put(i, new BitSet(100));
        }

        for(int i=0; i<n; i++) {
            peopleAlongRoute.put(i, new BitSet(100));
        }

        HashMap<Integer, Integer> stationsForPeople = new HashMap<>();

        for(int i=0; i<p; i++) {
            int station = sc.nextInt() - 1;
            int person = i;
            BitSet stationBitSet = people.get(station);
            stationBitSet.set(person, true);
            stationsForPeople.put(i, station);
        }

        

        for(int i=0; i<n; i++) {
            adjList.put(i, new ArrayList<>());
        }

        for(int i=0; i<m; i++) {
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            int c = sc.nextInt();
            adjList.get(a).add(new Pair<>(b, c));
            adjList.get(b).add(new Pair<>(a, c));
        }

        HashMap<Integer, Long> dist = dijkstra(0);


        dagAdjList = shortestPathDAG(dist);

        for(int i=0; i<p; i++) {
            dfs(stationsForPeople.get(i), i);
        }

        long separateCost = 0;
        for(int i=0; i<n; i++) {
            separateCost += dist.get(i) * people.get(i).cardinality();
        }

        long minCost = separateCost;
        for(int i=0; i<n; i++) {
            BitSet alongRoute = peopleAlongRoute.get(i);
            long groupCost = 0;
            for(int j=0; j<p; j++) {
                int startingStation = stationsForPeople.get(j);
                if(alongRoute.get(j)) {
                    groupCost += dist.get(startingStation) - dist.get(i) + g;
                } else {
                    groupCost += dist.get(startingStation);
                }
            }

            minCost = Math.min(minCost, groupCost);
        }
        System.out.println(minCost);

        sc.close();
    }
}
