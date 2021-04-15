import java.io.*;
import java.util.*;
import java.util.stream.*;

public class rgl {
  private static int clamp(int x,int a,int b){
    return Math.max(a,Math.min(x,b));
  }

  public static void main(String[] args) throws IOException {
     final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int[] wn = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    int w = wn[0];
    int n = wn[1];
    int[] x0 = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    int[] x1 = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

    int[] p = new int[n+1];
    p[0]=-(x1[0]-x0[0]);
    for (int i=0; i<n; i++) p[i+1]=p[i]+(x1[i]-x0[i]);
    int least=p[0];
    for (int i=0; i<=n; i++) least=Math.min(least,p[i]);
    for (int i=0; i<=n; i++) p[i]-=least;
    int cost=0;
    for (int i=0; i<=n; i++) cost+=p[i];

    for (int i=0; i<=n; i=Math.max(0,i)){
      int can=clamp(
        i==0? x0[i]-1-1 :
        i==n? w-x0[i-1]-1 :
              (x0[i]-x0[i-1]-2)/2, 0, p[i]);

      if (can>0){
        if (i>0) x0[i-1]+=can;
        if (i<n) x0[i]-=can;
        p[i]-=can;
        --i;
      }else{
        ++i;
      }
    }

    int remain=0;
    for (int i: p) remain+=i;
    if (remain==0){
      System.out.println(cost);
    }else{
      System.out.println("impossible");
    }
  }
}
