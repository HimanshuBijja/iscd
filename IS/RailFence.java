/*
 * Problem 3: Rail Fence Cipher (Zig-Zag Cipher)
 *
 * Example:
 *   Text: HELLOWORLD
 *   Rails: 3
 *   Encrypted: HOLELWRDLO
 *   Decrypted: HELLOWORLD
 */

import java.util.Scanner;

public class RailFence {
    // Generate rail pattern indices for each character position
    static int[] pattern(int n, int d) {
        int[] r = new int[n];
        int row = 0, dir = 1;
        for (int i = 0; i < n; i++) {
            r[i] = row;
            if (d > 1) {
                if (row == 0) dir = 1;
                else if (row == d - 1) dir = -1;
                row += dir;
            }
        }
        return r;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text: ");
        String t = sc.nextLine().replace(" ", "");
        System.out.print("Enter number of rails: ");
        int d = sc.nextInt();

        int[] p = pattern(t.length(), d);

        // Encryption: collect characters row by row
        StringBuilder e = new StringBuilder();
        for (int r = 0; r < d; r++) {
            for (int i = 0; i < t.length(); i++) {
                if (p[i] == r) e.append(t.charAt(i));
            }
        }

        // Decryption: place cipher characters back into their matching rail slots
        char[] o = new char[t.length()];
        int k = 0;
        for (int r = 0; r < d; r++) {
            for (int i = 0; i < t.length(); i++) {
                if (p[i] == r) o[i] = e.charAt(k++);
            }
        }

        System.out.println("Encrypted: " + e);
        System.out.println("Decrypted: " + new String(o));
        sc.close();
    }
}
