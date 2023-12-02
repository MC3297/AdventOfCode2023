import java.io.*;
import java.util.*;
public class d2p1 {
    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new FileReader("txt.in"));
		PrintWriter pw = new PrintWriter("txt.out");
        int ans = 0;
        for (int z = 0; z < 100; z++) {
            String s = r.readLine();
            s = s.replaceAll(",", "");
            String pp = s.split(": ")[1];
            String[] spl = pp.split("; ");
            boolean bad = false;
            int fr = 0, fb = 0, fg = 0;
            for (String i: spl) {
                int rr = 0, bb = 0, gg = 0;
                String[] tmp = i.split(" ");
                for (int j = 0; j < tmp.length; j+=2) {
                    int n = Integer.parseInt(tmp[j]);
                    if (tmp[j+1].length() == 3) rr = n;
                    if (tmp[j+1].length() == 4) bb = n;
                    if (tmp[j+1].length() == 5) gg = n;
                }       
                fr = Math.max(fr, rr);
                fg = Math.max(fg, gg);
                fb = Math.max(fb, bb);
                if (rr > 12 || gg > 13 || bb > 14) bad = true;
            }
            if (!bad) {
                ans += z+1;
            }
        }
        pw.println(ans);
        pw.close();
        r.close();
    }
}