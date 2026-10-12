/*
 * Problem 6: Diffie-Hellman Key Exchange
 * Computes shared secret between Alice and Bob using modular exponentiation.
 *
 * Formulas:
 *   Alice Public Key: A = g^a mod p
 *   Bob Public Key:   B = g^b mod p
 *   Shared Secret:    K = B^a mod p = A^b mod p
 *
 * Example:
 *   p: 23, g: 5
 *   Alice Private: 6   -> Public: 8
 *   Bob Private:   15  -> Public: 19
 *   Alice Secret:  2
 *   Bob Secret:    2
 */

import java.math.BigInteger;
import java.util.Scanner;

public class DiffieHellman {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter prime p: ");
        BigInteger p = sc.nextBigInteger();
        System.out.print("Enter generator g: ");
        BigInteger g = sc.nextBigInteger();
        System.out.print("Enter Alice's private key: ");
        BigInteger a = sc.nextBigInteger();
        System.out.print("Enter Bob's private key: ");
        BigInteger b = sc.nextBigInteger();

        // Calculate public keys
        BigInteger A = g.modPow(a, p);
        BigInteger B = g.modPow(b, p);
        System.out.println("Alice public: " + A + ", Bob public: " + B);

        // Calculate shared secrets (both will match)
        BigInteger secretAlice = B.modPow(a, p);
        BigInteger secretBob = A.modPow(b, p);
        System.out.println("Alice secret: " + secretAlice);
        System.out.println("Bob secret:   " + secretBob);
        sc.close();
    }
}
