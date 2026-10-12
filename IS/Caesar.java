/*
 * Problem 1: Caesar Cipher (Shift Cipher)
 * Supports both uppercase and lowercase characters, preserves non-alphabets,
 * and correctly handles negative keys using Math.floorMod.
 *
 * Example:
 *   Text: Hello World
 *   Key: 3
 *   Encrypted: Khoor Zruog
 *   Decrypted: Hello World
 */

import java.util.Scanner;

public class Caesar {
    static String shift(String s, int k) {
        StringBuilder r = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) {
                char base = Character.isUpperCase(c) ? 'A' : 'a';
                r.append((char) (Math.floorMod(c - base + k, 26) + base));
            } else {
                r.append(c);
            }
        }
        return r.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text: ");
        String text = sc.nextLine();
        System.out.print("Enter key: ");
        int key = sc.nextInt();

        String encrypted = shift(text, key);
        System.out.println("Encrypted: " + encrypted);
        System.out.println("Decrypted: " + shift(encrypted, -key));
        sc.close();
    }
}
