/* Member functions */
package OOPLab.functions;
import java.util.Scanner;

class employee {
    int number;
    String name;
    float basic, DA, IT, grossSalary, netSalary;

    public void updateDetails() {
        Scanner sc = new Scanner(System.in);
        System.out.print("\t Number: ");
        number = sc.nextInt(); sc.nextLine();
        System.out.print("\t Name: ");
        name = sc.nextLine();
        System.out.print("\t Basic: ");
        basic = sc.nextInt();
        System.out.println("---------------------");
    }

    public void displayDetails() {
        System.out.println(number + "\t\t"
                + name + " \t"
                + basic + "\t"
                + DA + " \t"
                + IT + " \t"
                + grossSalary + "\t"
                + netSalary);
    }

    public void findNetSalary() {
        DA = (float) (0.52 * basic);
        grossSalary = basic + DA;
        IT = (float) (0.3 * grossSalary);
        netSalary = basic + DA - IT;
    }
}

public class Main {

    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter no. of employees: ");
        n = sc.nextInt();
        employee[] E = new employee[n];
        System.out.println("Enter employee details");

        for (int i = 0; i < n; i++)
        {
            E[i] = new employee();
            E[i].updateDetails();
            E[i].findNetSalary();
        }
        System.out.println("Number \tName  \tBasic \tDA  \tIT \t\tGross \tNet Salary");
        System.out.println("----------------------------------------------------------");
        for (int i = 0; i < n; i++)
            E[i].displayDetails();
    }
}