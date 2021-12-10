/* Hybrid Inheritance */
#include <iostream>
#include <string>
using namespace std;

enum diskType { CD, DVD };

/* Base class Publication */
class Publication
{
protected:
    string title;
    float price;
public:
    Publication() { title = ""; price = 0; }

    void getdata()
    {
        cout << "Enter publication details: \n"
            << "\tTitle: ";
        getline(cin, title);
        cout << "\tPrice: ";
        cin >> price;
    }

    void putdata()
    {
        cout << "--------------------------------------------------- \n"
            << "Publication details: \n"
            << "\tTitle: " << title << '\n'
            << "\tPrice: " << price << '\n'
            << "--------------------------------------------------- \n";
    }
};

/* Base class Sales */
class Sales
{
protected:
    float sales[3];
public:
    Sales() { sales[0] = sales[1] = sales[2] = 0; }

    void getdata()
    {
        cout << "Enter dollar sales: \n"
            << "\tfor last month: ";
        cin >> sales[0];
        cout << "\tfor second last month: ";
        cin >> sales[1];
        cout << "\tfor third last month: ";
        cin >> sales[2];
    }

    void putdata()
    {
        cout << "--------------------------------------------------- \n"
            << "Dollar sales: \n"
            << "\tfor last month: " << sales[0] << '\n'
            << "\tfor second last month: " << sales[1] << '\n'
            << "\tfor third last month: " << sales[2] << '\n'
            << "--------------------------------------------------- \n";
    }
};

/* Derived class for Books */
class Book : public Publication, public Sales
{
protected:
    int pages;
public:
    Book() : Publication(), Sales() { pages = 0; }

    void getdata()
    {
        cout << "Enter book details: \n"
            << "\tTitle: ";
        getline(cin, title);
        cout << "\tPrice: ";
        cin >> price;
        cout << "\tNo. of pages: ";
        cin >> pages;
        cout << "\tEnter dollar sales: \n"
            << "\t\tfor last month: ";
        cin >> sales[0];
        cout << "\t\tfor second last month: ";
        cin >> sales[1];
        cout << "\t\tfor third last month: ";
        cin >> sales[2];
    }

    void putdata()
    {
        cout << "--------------------------------------------------- \n"
            << "Book details: \n"
            << "\tTitle: " << title << '\n'
            << "\tPrice: " << price << '\n'
            << "\tNo. of pages: " << pages << '\n'
            << "\tDollar sales: \n"
            << "\t\tfor last month: " << sales[0] << '\n'
            << "\t\tfor second last month: " << sales[1] << '\n'
            << "\t\tfor third last month: " << sales[2] << '\n'
            << "--------------------------------------------------- \n";
    }
};

/* Derived class for audiocassettes */
class Tape : public Publication, public Sales
{
protected:
    float playingTime;
public:
    Tape() : Publication() { playingTime = 0; }

    void getdata()
    {
        cout << "Enter audiocassette details: \n"
            << "\tTitle: ";
        cin.ignore();
        getline(cin, title);
        cout << "\tPrice: ";
        cin >> price;
        cout << "\tPlaying time: ";
        cin >> playingTime;
        cout << "\tEnter dollar sales: \n"
            << "\t\tfor last month: ";
        cin >> sales[0];
        cout << "\t\tfor second last month: ";
        cin >> sales[1];
        cout << "\t\tfor third last month: ";
        cin >> sales[2];
    }

    void putdata()
    {
        cout << "--------------------------------------------------- \n"
            << "Audiocassette details: \n"
            << "\tTitle: " << title << '\n'
            << "\tPrice: " << price << '\n'
            << "\tPlaying time: " << playingTime << " minutes \n"
            << "\tDollar sales: \n"
            << "\t\tfor last month: " << sales[0] << '\n'
            << "\t\tfor second last month: " << sales[1] << '\n'
            << "\t\tfor third last month: " << sales[2] << '\n'
            << "--------------------------------------------------- \n";
    }
};

/* Derived class for eBooks */
class Disk : public Publication, public Sales
{
protected:
    diskType type;
public:
    Disk() : Publication(), Sales() { type = DVD; }

    void getdata()
    {
        char a;
        cout << "Enter eBook details: \n"
            << "\tTitle: ";
        cin.ignore();
        getline(cin, title);
        cout << "\tPrice: ";
        cin >> price;
        cout << "\tDisk type: ";
        cin >> a;
        type = (a == 'c') ? CD : DVD;
        cout << "\tEnter dollar sales: \n"
            << "\t\tfor last month: ";
        cin >> sales[0];
        cout << "\t\tfor second last month: ";
        cin >> sales[1];
        cout << "\t\tfor third last month: ";
        cin >> sales[2];
    }

    void putdata()
    {
        cout << "--------------------------------------------------- \n"
            << "eBook details: \n"
            << "\tTitle: " << title << '\n'
            << "\tPrice: " << price << '\n'
            << "\tDisk type: " << ((type == CD) ? "CD" : "DVD") << '\n'
            << "\tDollar sales: \n"
            << "\t\tfor last month: " << sales[0] << '\n'
            << "\t\tfor second last month: " << sales[1] << '\n'
            << "\t\tfor third last month: " << sales[2] << '\n'
            << "--------------------------------------------------- \n";
    }
};

int main()
{
    Book oop;
    Tape dsa;
    Disk ana;
    oop.getdata();
    dsa.getdata();
    ana.getdata();
    oop.putdata();
    dsa.putdata();
    ana.putdata();
    return 0;
}