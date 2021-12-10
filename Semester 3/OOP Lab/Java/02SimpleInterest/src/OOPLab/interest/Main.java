/* Java program to calculate simple interest */
package OOPLab.interest;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        float p, r, t, si;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter principal: ");
        p = sc.nextFloat();
        System.out.println("Enter rate: ");
        r = sc.nextFloat();
        System.out.println("Enter time: ");
        t = sc.nextFloat();

        si = (p * r * t) / 100;
        System.out.println("Simple interest: " + si);
    }
}