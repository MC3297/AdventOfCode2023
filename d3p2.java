import java.io.*;
import java.util.*;

public class d3p2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("txt.in"));
		PrintWriter pw = new PrintWriter("txt.out");
    
        int n = 140;
        String[] stor = new String[n+2];
        ArrayList<Integer>[][] pos = new ArrayList[143][143];
        for (int i = 0; i < 143; i++) {
            for (int j = 0; j < 143; j++) {
                pos[i][j] = new ArrayList<>();
            }
        }
        String s = "...................................................................................................................................................";
        stor[0] = s;
        stor[n+1] = s;
        for (int i = 1; i <= n; i++) {
            stor[i] = "."+br.readLine()+".";
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int l = 0, r = 0;
            for (int j = 0; j < stor[i].length()-1; j++) {
                if (!Character.isDigit(stor[i].charAt(j)) && Character.isDigit(stor[i].charAt(j+1))) {
                    l = j+1;
                }
                if (Character.isDigit(stor[i].charAt(j)) && !Character.isDigit(stor[i].charAt(j+1))) {
                    r = j;
                    int x = Integer.parseInt(stor[i].substring(l,r+1));
                    for (int k = l-1; k <= r+1; k++) {
                        if (stor[i-1].charAt(k) == '*') {
                            pos[i-1][k].add(x);
                        }
                        if (stor[i+1].charAt(k) == '*') {
                            pos[i+1][k].add(x);
                        }
                        if (stor[i].charAt(k) == '*') {
                            pos[i][k].add(x);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 143; i++) {
            for (int j = 0; j < 143; j++) {
                if (pos[i][j].size() == 2) {
                    ans += pos[i][j].get(0) * pos[i][j].get(1);
                }
            }
        }
        pw.println(ans);
        pw.close();
        br.close();
    }
}
