/* Inheritance */
package OOPLab.inheritance;
import java.util.Scanner;

/* Base class Publication */
class Publication {
    protected String title;
    protected float price;

    public Publication() {
        title = "";
        price = 0;
    }

    public void getData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter publication details:");
        System.out.print("\tTitle: ");
        title = sc.nextLine();
        System.out.print("\tPrice: ");
        price = sc.nextInt(); sc.nextLine();
    }

    public void putData() {
        System.out.println("---------------------------------------------------");
        System.out.println("Publication details:");
        System.out.println("\tTitle: " + title);
        System.out.println("\tPrice: " + price);
        System.out.println("---------------------------------------------------");
    }
}

/* Derived class for Books */
class Book extends Publication {
    protected int pages;

    public Book() {
        super();
        pages = 0;
    }

    public void getData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter book details:");
        System.out.print("\tTitle: ");
        title = sc.nextLine();
        System.out.print("\tPrice: ");
        price = sc.nextInt();
        System.out.print("\tNo. of pages: ");
        pages = sc.nextInt(); sc.nextLine();
    }

    public void putData() {
        System.out.println("---------------------------------------------------");
        System.out.println("Book details:");
        System.out.println("\tTitle: " + title);
        System.out.println("\tPrice: " + price);
        System.out.println("\tNo. of pages: " + pages);
        System.out.println("---------------------------------------------------");
    }
}

/* Derived class for audio cassettes */
class Tape extends Publication {
    protected float playingTime;

    public Tape() {
        super();
        playingTime = 0;
    }

    public void getData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter audio cassette details:");
        System.out.print("\tTitle: ");
        title = sc.nextLine();
        System.out.print("\tPrice: ");
        price = sc.nextInt();
        System.out.print("\tPlaying time: ");
        playingTime = sc.nextInt(); sc.nextLine();
    }

    public void putData() {
        System.out.println("---------------------------------------------------");
        System.out.println("Audio cassette details:");
        System.out.println("\tTitle: " + title);
        System.out.println("\tPrice: " + price);
        System.out.println("\tPlaying time: " + playingTime + " minutes");
        System.out.println("---------------------------------------------------");
    }
}

public class Main {

    public static void main(String[] args) {
        Book oop = new Book();
        Tape dsa = new Tape();
        oop.getData();
        dsa.getData();
        oop.putData();
        dsa.putData();
    }
}