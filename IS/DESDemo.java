/*
 * Problem 5: DES (Data Encryption Standard)
 * Symmetric encryption demonstration using standard Java Cryptography Architecture.
 *
 * Example:
 *   Text: Hello World
 *   Key: 12345678 (Must be 8 characters = 64-bit key)
 *   Encrypted: <Base64 encoded ciphertext>
 *   Decrypted: Hello World
 */

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.util.Base64;
import java.util.Scanner;

public class DESDemo {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter text: ");
        String t = sc.nextLine();
        System.out.print("Enter 8-character key: ");
        String k = sc.nextLine();

        if (k.length() != 8) {
            System.out.println("Key must be 8 characters");
            sc.close();
            return;
        }

        SecretKeySpec key = new SecretKeySpec(k.getBytes(), "DES");
        Cipher cipher = Cipher.getInstance("DES");

        // Encrypt: Text -> DES Cipher -> Base64 String
        cipher.init(Cipher.ENCRYPT_MODE, key);
        String encrypted = Base64.getEncoder().encodeToString(cipher.doFinal(t.getBytes()));
        System.out.println("Encrypted: " + encrypted);

        // Decrypt: Base64 String -> DES Decipher -> Original Text
        cipher.init(Cipher.DECRYPT_MODE, key);
        String decrypted = new String(cipher.doFinal(Base64.getDecoder().decode(encrypted)));
        System.out.println("Decrypted: " + decrypted);
        sc.close();
    }
}
