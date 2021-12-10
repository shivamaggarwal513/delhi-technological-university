/* Java Program to Add Two Numbers */
package OOPLab.add;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int a, b, sum;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter two numbers: ");
        a = sc.nextInt();
        b = sc.nextInt();
        sum = a + b;
        System.out.println(a + " + " + b + " = " + sum);
    }
}