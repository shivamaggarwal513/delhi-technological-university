/* Java Program to Find Quotient and Remainder */
package OOPLab.division;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int D, d, q, r;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter dividend: ");
        D = sc.nextInt();
        System.out.println("Enter divisor: ");
        d = sc.nextInt();
        q = D / d;
        r = D % d;
        System.out.println(D + " = " + d + " x " + q + " + " + r);
        System.out.println("Quotient: " + q);
        System.out.println("Remainder: " + r);
    }
}