package Algos.Graphs;
import java.util.*;

public class TopoSort {
    static ArrayList<Integer>[] adj;
    static boolean[] visited;
    static Stack<Integer> st = new Stack<>();

    static void dfs(int node) {
    visited[node] = true;
    for (int x : adj[node]) {
      if (!visited[x]) {
        dfs(x);
      }
    }
    st.push(node);
  }
    
    /**
     * @param args
     */
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter the number of nodes: ");
    int n = sc.nextInt();

    System.out.print("Enter the number of edges: ");
    int m = sc.nextInt();

    adj = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      adj[i] = new ArrayList<>();
    }

    for (int i = 0; i < m; i++) {
      int u = sc.nextInt();
      int v = sc.nextInt();
      adj[u].add(v);
    }

    visited = new boolean[n];
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }

    while (!st.empty()) {
      System.out.print(st.pop() + " ");
    }
  }
    
}
