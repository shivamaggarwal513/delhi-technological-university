/* Class members */
package OOPLab.members;
import java.util.Scanner;

class employee {
    int number;
    String name;
    float basic, DA, IT, netSalary;

    public void updateDetails() {
        Scanner sc = new Scanner(System.in);
        System.out.print("\t Number: ");
        number = sc.nextInt(); sc.nextLine();
        System.out.print("\t Name: ");
        name = sc.nextLine();
        System.out.print("\t Basic: ");
        basic = sc.nextInt();
        System.out.print("\t Dearness Allowance: ");
        DA = sc.nextInt();
        System.out.print("\t Income Tax: ");
        IT = sc.nextInt();
        System.out.println("----------------------------------");
    }

    public void displayDetails() {
        System.out.println("\n Employee Details");
        System.out.println("\t Number             : " + number);
        System.out.println("\t Name               : " + name);
        System.out.println("\t Basic              : " + basic);
        System.out.println("\t Dearness Allowance : " + DA);
        System.out.println("\t Income Tax         : " + IT);
        System.out.println("\t Net Salary         : " + findNetSalary(basic, DA, IT));
    }

    public float findNetSalary(float basic, float DA, float IT) {
        netSalary = basic + DA - IT;
        return netSalary;
    }
}

public class Main {

    public static void main(String[] args) {
        employee E = new employee();
        System.out.println("Enter employee details");
        E.updateDetails();
        E.displayDetails();
    }
}