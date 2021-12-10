/* Static variables */
package OOPLab.staticvar;
import java.util.Scanner;

public class Main {
    static int count = 0;

    static void fun()
    {
        count++;
        System.out.println("I've been called " + count + " times");
    }

    public static void main(String[] args) {
        int n = 1;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 0 to stop");
        while (n != 0)
        {
            fun();
            n = sc.nextInt();
        }
    }
}