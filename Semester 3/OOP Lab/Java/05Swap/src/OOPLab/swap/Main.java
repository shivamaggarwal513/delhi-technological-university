/* Java Program to Swap Two Numbers (without temporary variables) */
package OOPLab.swap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int a, b;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers: ");
        a = sc.nextInt();
        b = sc.nextInt();

        a = a + b;
        b = a - b;
        a = a - b;
        System.out.println("Numbers after swap: \n" + a + " " + b);
    }
}