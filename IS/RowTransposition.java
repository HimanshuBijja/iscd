/*
 * Problem 4: Row Transposition Cipher
 * Matrix-based columnar transposition using a numeric permutation key (e.g. 3142).
 * Pads with 'X' to complete matrix rectangle.
 *
 * Example:
 *   Text: HELLOWORLD
 *   Key: 3142
 *   Encrypted: EWDLRXHOLLOX
 *   Decrypted: HELLOWORLDXX
 */

import java.util.Scanner;

public class RowTransposition {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text: ");
        String t = sc.nextLine().toUpperCase().replaceAll("[^A-Z]", "");
        System.out.print("Enter key (e.g. 3142): ");
        String k = sc.nextLine().trim();

        int c = k.length();
        // Pad with 'X' until length is a multiple of column count c
        StringBuilder sb = new StringBuilder(t);
        while (sb.length() % c != 0) {
            sb.append('X');
        }
        t = sb.toString();

        int r = t.length() / c;

        // Encrypt: read column-by-column in increasing numeric order of key digits (1, 2, ..., c)
        StringBuilder e = new StringBuilder();
        for (int n = 1; n <= c; n++) {
            int col = k.indexOf((char) ('0' + n));
            for (int i = 0; i < r; i++) {
                e.append(t.charAt(i * c + col));
            }
        }

        // Decrypt: rebuild matrix column-by-column in key order, read row-by-row
        char[] d = new char[t.length()];
        int idx = 0;
        for (int n = 1; n <= c; n++) {
            int col = k.indexOf((char) ('0' + n));
            for (int i = 0; i < r; i++) {
                d[i * c + col] = e.charAt(idx++);
            }
        }

        System.out.println("Encrypted: " + e);
        System.out.println("Decrypted: " + new String(d));
        sc.close();
    }
}
