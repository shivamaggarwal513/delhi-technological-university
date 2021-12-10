/* Class */
package OOPLab.classes;
import java.util.Scanner;

class student {
    int roll;
    String name;
    String grade;

    public void update() {
        Scanner sc = new Scanner(System.in);
        System.out.print("\t Roll No.: ");
        roll = sc.nextInt(); sc.nextLine();
        System.out.print("\t Name: ");
        name = sc.nextLine();
        System.out.print("\t Grade: ");
        grade = sc.nextLine();
        System.out.println("-----------------------");
    }

    public void display() {
        System.out.println(roll + "\t\t" + name + "\t" + grade);
    }
}

public class Main {

    public static void main(String[] args) {
        student[] arr = new student[3];
        System.out.println("Enter student details");
        for (int i = 0; i < 3; i++) {
            arr[i] = new student();
            arr[i].update();
        }

        System.out.println("Roll \tName \tGrade");
        for (int i = 0; i < 3; i++)
            arr[i].display();
    }
}