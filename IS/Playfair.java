/*
 * Problem 2: Playfair Cipher
 * Encrypts and decrypts digraphs using a 5x5 key matrix.
 * Note: 'J' is treated as 'I'.
 *
 * Example:
 *   Key: MONARCHY
 *   Text: hello
 *   Encrypted: CFSUPM
 *   Decrypted: HELXLO
 */

import java.util.*;

public class Playfair {
    static char[][] m = new char[5][5];

    // Find row and column coordinates of a character in matrix
    static int[] pos(char c) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (m[i][j] == c) return new int[]{i, j};
            }
        }
        return null;
    }

    // Process digraphs: d = +1 for Encryption, d = -1 for Decryption
    static String run(String t, int d) {
        StringBuilder r = new StringBuilder();
        for (int k = 0; k < t.length(); k += 2) {
            int[] a = pos(t.charAt(k));
            int[] b = pos(t.charAt(k + 1));

            // Same row -> shift columns
            if (a[0] == b[0]) {
                r.append(m[a[0]][(a[1] + d + 5) % 5]).append(m[b[0]][(b[1] + d + 5) % 5]);
            }
            // Same column -> shift rows
            else if (a[1] == b[1]) {
                r.append(m[(a[0] + d + 5) % 5][a[1]]).append(m[(b[0] + d + 5) % 5][b[1]]);
            }
            // Rectangle -> swap columns
            else {
                r.append(m[a[0]][b[1]]).append(m[b[0]][a[1]]);
            }
        }
        return r.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter key: ");
        String key = sc.nextLine().toUpperCase().replaceAll("[^A-Z]", "").replace('J', 'I');
        System.out.print("Enter text: ");
        String t = sc.nextLine().toUpperCase().replaceAll("[^A-Z]", "").replace('J', 'I');

        // Populate 5x5 key matrix without duplicate characters
        Set<Character> s = new LinkedHashSet<>();
        for (char c : (key + "ABCDEFGHIKLMNOPQRSTUVWXYZ").toCharArray()) {
            s.add(c);
        }

        int n = 0;
        for (char c : s) {
            m[n / 5][n % 5] = c;
            n++;
        }

        // Format plaintext into digraphs: split identical letters in a pair with 'X'
        StringBuilder p = new StringBuilder();
        for (char c : t.toCharArray()) {
            if (p.length() % 2 == 1 && p.charAt(p.length() - 1) == c) {
                p.append('X');
            }
            p.append(c);
        }
        if (p.length() % 2 == 1) {
            p.append('X');
        }

        String encrypted = run(p.toString(), 1);
        System.out.println("Encrypted: " + encrypted);
        System.out.println("Decrypted: " + run(encrypted, -1));
        sc.close();
    }
}
