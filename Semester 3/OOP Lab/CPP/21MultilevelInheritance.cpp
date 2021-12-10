/* Multilevel Inheritance */
#include <iostream>
#include <string>
using namespace std;

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

/* Intermediate Base class Publication2 */
class Publication2 : public Publication
{
protected:
    string date;
public:
    Publication2() : Publication() { date = ""; }

    void getdata()
    {
        cout << "Enter date of publication (DD/MM/YYYY): ";
        cin >> date;
    }

    void putdata()
    {
        cout << "--------------------------------------------------- \n"
            << "Date of publication: " << date << '\n'
            << "--------------------------------------------------- \n";
    }
};

/* Derived class for Books */
class Book : public Publication2
{
protected:
    int pages;
public:
    Book() : Publication2() { pages = 0; }

    void getdata()
    {
        cout << "Enter book details: \n"
            << "\tTitle: ";
        getline(cin, title);
        cout << "\tPrice: ";
        cin >> price;
        cout << "\tDate of publication (DD/MM/YYYY): ";
        cin >> date;
        cout << "\tNo. of pages: ";
        cin >> pages;
    }

    void putdata()
    {
        cout << "--------------------------------------------------- \n"
            << "Book details: \n"
            << "\tTitle: " << title << '\n'
            << "\tPrice: " << price << '\n'
            << "\tDate of publication: " << date << '\n'
            << "\tNo. of pages: " << pages << '\n'
            << "--------------------------------------------------- \n";
    }
};

/* Derived class for audiocassettes */
class Tape : public Publication2
{
protected:
    float playingTime;
public:
    Tape() : Publication2() { playingTime = 0; }

    void getdata()
    {
        cout << "Enter audiocassette details: \n"
            << "\tTitle: ";
        cin.ignore();
        getline(cin, title);
        cout << "\tPrice: ";
        cin >> price;
        cout << "\tDate of publication (DD/MM/YYYY): ";
        cin >> date;
        cout << "\tPlaying time: ";
        cin >> playingTime;
    }

    void putdata()
    {
        cout << "--------------------------------------------------- \n"
            << "Audiocassette details: \n"
            << "\tTitle: " << title << '\n'
            << "\tPrice: " << price << '\n'
            << "\tDate of publication: " << date << '\n'
            << "\tPlaying time: " << playingTime << " minutes \n"
            << "--------------------------------------------------- \n";
    }
};

int main()
{
    Book oop;
    Tape dsa;
    oop.getdata();
    dsa.getdata();
    oop.putdata();
    dsa.putdata();
    return 0;
}