import java.io.*;
import java.util.*;

public class d3p1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("txt.in"));
		PrintWriter pw = new PrintWriter("txt.out");
    
        int n = 140;
        String[] stor = new String[n+3];
        String s = "...................................................................................................................................................";
        stor[0] = s;
        stor[n+1] = stor[n+2] = s;
        for (int i = 1; i <= n; i++) {
            stor[i] = "."+br.readLine()+".";
        }
        for (String ss: stor) System.out.println(ss);
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
                    boolean symb = false;
                    for (int k = l-1; k <= r+1; k++) {
                        if (!Character.isDigit(stor[i-1].charAt(k)) && stor[i-1].charAt(k) != '.') {
                            symb = true;
                        }
                        if (!Character.isDigit(stor[i+1].charAt(k)) && stor[i+1].charAt(k) != '.') {
                            symb = true;
                        }
                        if (!Character.isDigit(stor[i].charAt(k)) && stor[i].charAt(k) != '.') {
                            symb = true;
                        }
                    }
                    if (symb) {
                        ans += x;
                    }
                }
            }
        }
        pw.println(ans);
        pw.close();
        br.close();
    }
}
