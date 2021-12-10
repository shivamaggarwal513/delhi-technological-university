/* Java Program to Check Whether Number is Even or Odd */
package OOPLab.evenodd;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        n = sc.nextInt();
        String result = (n % 2 == 0) ? "Even" : "Odd";
        System.out.println(result);
    }
}