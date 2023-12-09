import java.io.*;
import java.util.*;

public class d9p1 {
    static boolean zero(ArrayList<Long> a) {
        for (long i: a) if (i != 0) return false;
        return true;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("txt.in"));
		PrintWriter pw = new PrintWriter("txt.out");
        long ans = 0;
        long n = 200;
        for (long z = 0; z < n; z++) {
            String[] spl = br.readLine().split(" ");
            long[] stor = new long[spl.length];
            for (int i = 0; i < stor.length; i++) {
                stor[i] = Long.parseLong(spl[i]);
            }
            ArrayList<ArrayList<Long>> arr = new ArrayList<>();
            arr.add(new ArrayList<>());
            for (int i = 0; i < stor.length-1; i++) {
                arr.get(0).add(stor[i+1]-stor[i]);
            }
            while (!zero(arr.get(arr.size()-1))) {
                ArrayList<Long> tmp = new ArrayList<>(), last = arr.get(arr.size()-1);

                for (int i = 0; i < last.size()-1; i++) {
                    tmp.add(last.get(i+1)-last.get(i));
                }
                arr.add(tmp);
            }

            ArrayList<Long> cur = new ArrayList<>();
            cur.add(0L);
            for (int i = arr.size()-2; i >= 0; i--) {
                cur.add(cur.get(cur.size()-1) + arr.get(i).get(arr.get(i).size()-1));
            }
            long x = cur.get(cur.size()-1) + stor[stor.length-1];
            pw.println(x);
            pw.println(cur);
            ans += x;
        }
        System.out.println(ans);
        pw.close();
        br.close();
    }
}
