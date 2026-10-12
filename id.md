1. Caeser Cipher

import java.util.*;
public class Caesar {
    static String shift(String s, int k) {
        StringBuilder r = new StringBuilder();
        for (char c : s.toCharArray()) {
            char b = Character.isUpperCase(c) ? 'A' : 'a';
            r.append(Character.isLetter(c) ? (char) (Math.floorMod(c - b + k, 26) + b) : c);
        }
        return r.toString();
    }
    public static void main(String[] x) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text: ");
        String t = sc.nextLine();
        System.out.print("Enter key: ");
        int k = sc.nextInt();
        String e = shift(t, k);
        System.out.println("Encrypted: " + e);
        System.out.println("Decrypted: " + shift(e, -k));
    }
}

Enter text: Hello World
Enter key: 3
Encrypted: Khoor Zruog
Decrypted: Hello World



2) Playfair Cipher

import java.util.*;
public class Playfair {
    static char[][] m = new char[5][5];
    static int[] pos(char c) {
        for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) if (m[i][j] == c) return new int[]{i, j};
        return null;
    }
    static String run(String t, int d) {
        StringBuilder r = new StringBuilder();
        for (int k = 0; k < t.length(); k += 2) {
            int[] a = pos(t.charAt(k)), b = pos(t.charAt(k + 1));
            if (a[0] == b[0]) r.append(m[a[0]][(a[1] + d + 5) % 5]).append(m[b[0]][(b[1] + d + 5) % 5]);
            else if (a[1] == b[1]) r.append(m[(a[0] + d + 5) % 5][a[1]]).append(m[(b[0] + d + 5) % 5][b[1]]);
            else r.append(m[a[0]][b[1]]).append(m[b[0]][a[1]]);
        }
        return r.toString();
    }
    public static void main(String[] x) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter key: ");
        String key = sc.nextLine().toUpperCase().replaceAll("[^A-Z]", "").replace('J', 'I');
        System.out.print("Enter text: ");
        String t = sc.nextLine().toUpperCase().replaceAll("[^A-Z]", "").replace('J', 'I');
        Set<Character> s = new LinkedHashSet<>();
        for (char c : (key + "ABCDEFGHIKLMNOPQRSTUVWXYZ").toCharArray()) s.add(c);
        int n = 0;
        for (char c : s) m[n / 5][n++ % 5] = c;
        StringBuilder p = new StringBuilder();
        for (char c : t.toCharArray()) {
            if (p.length() % 2 == 1 && p.charAt(p.length() - 1) == c) p.append('X');
            p.append(c);
        }
        if (p.length() % 2 == 1) p.append('X');
        String e = run(p.toString(), 1);
        System.out.println("Encrypted: " + e);
        System.out.println("Decrypted: " + run(e, -1));
    }
}

Enter key: MONARCHY
Enter text: hello
Encrypted: CFSUPM
Decrypted: HELXLO

















3) Rail Fence Cipher

import java.util.*;
public class RailFence {
    static int[] pattern(int n, int d) {
        int[] r = new int[n];
        int row = 0, dir = 1;
        for (int i = 0; i < n; i++) {
            r[i] = row;
            if (d > 1) { if (row == 0) dir = 1; else if (row == d - 1) dir = -1; row += dir; }
        }
        return r;
    }
    public static void main(String[] x) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text: ");
        String t = sc.nextLine().replace(" ", "");
        System.out.print("Enter number of rails: ");
        int d = sc.nextInt();
        int[] p = pattern(t.length(), d);
        StringBuilder e = new StringBuilder();
        for (int r = 0; r < d; r++)
            for (int i = 0; i < t.length(); i++) if (p[i] == r) e.append(t.charAt(i));
        char[] o = new char[t.length()];
        int k = 0;
        for (int r = 0; r < d; r++)
            for (int i = 0; i < t.length(); i++) if (p[i] == r) o[i] = e.charAt(k++);
        System.out.println("Encrypted: " + e);
        System.out.println("Decrypted: " + new String(o));
    }
}

Enter text: HELLOWORLD
Enter number of rails: 3
Encrypted: HOLELWRDLO
Decrypted: HELLOWORLD


























4) Row Transposition Cipher

import java.util.*;
public class RowTransposition {
    public static void main(String[] x) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text: ");
        String t = sc.nextLine().toUpperCase().replaceAll("[^A-Z]", "");
        System.out.print("Enter key (e.g. 3142): ");
        String k = sc.nextLine().trim();
        int c = k.length();
        while (t.length() % c != 0) t += "X";
        int r = t.length() / c;
        StringBuilder e = new StringBuilder();
        for (int n = 1; n <= c; n++) {
            int col = k.indexOf((char) ('0' + n));
            for (int i = 0; i < r; i++) e.append(t.charAt(i * c + col));
        }
        char[] d = new char[t.length()];
        int idx = 0;
        for (int n = 1; n <= c; n++) {
            int col = k.indexOf((char) ('0' + n));
            for (int i = 0; i < r; i++) d[i * c + col] = e.charAt(idx++);
        }
        System.out.println("Encrypted: " + e);
        System.out.println("Decrypted: " + new String(d));
    }
}

Enter text: HELLOWORLD
Enter key (e.g. 3142): 3142
Encrypted: EWDLRXHOLLOX
Decrypted: HELLOWORLDXX
5) DES

import javax.crypto.*;
import javax.crypto.spec.*;
import java.util.*;
public class DESDemo {
    public static void main(String[] x) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text: ");
        String t = sc.nextLine();
        System.out.print("Enter 8-character key: ");
        String k = sc.nextLine();
        if (k.length() != 8) { System.out.println("Key must be 8 characters"); return; }
        SecretKeySpec key = new SecretKeySpec(k.getBytes(), "DES");
        Cipher c = Cipher.getInstance("DES");
        c.init(Cipher.ENCRYPT_MODE, key);
        String e = Base64.getEncoder().encodeToString(c.doFinal(t.getBytes()));
        System.out.println("Encrypted: " + e);
        c.init(Cipher.DECRYPT_MODE, key);
        System.out.println("Decrypted: " + new String(c.doFinal(Base64.getDecoder().decode(e))));
    }
}

Enter text: Hello World
Enter 8-character key: 12345678
Encrypted: <Base64 string>
Decrypted: Hello World




6) Diffie-Hellman Key Exchange

import java.math.BigInteger;
import java.util.*;
public class DiffieHellman {
    public static void main(String[] x) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter prime p: ");
        BigInteger p = sc.nextBigInteger();
        System.out.print("Enter generator g: ");
        BigInteger g = sc.nextBigInteger();
        System.out.print("Enter Alice's private key: ");
        BigInteger a = sc.nextBigInteger();
        System.out.print("Enter Bob's private key: ");
        BigInteger b = sc.nextBigInteger();
        BigInteger A = g.modPow(a, p), B = g.modPow(b, p);
        System.out.println("Alice public: " + A + ", Bob public: " + B);
        System.out.println("Alice secret: " + B.modPow(a, p));
        System.out.println("Bob secret:   " + A.modPow(b, p));
    }
}

Enter prime p: 23
Enter generator g: 5
Enter Alice's private key: 6
Enter Bob's private key: 15
Alice public: 8, Bob public: 19
Alice secret: 2
Bob secret:   2
