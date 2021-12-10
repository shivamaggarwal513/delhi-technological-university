/* Hierarchical Inheritance */
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

/* Derived class for Books */
class Book : public Publication
{
protected:
    int pages;
public:
    Book() : Publication() { pages = 0; }

    void getdata()
    {
        cout << "Enter book details: \n"
            << "\tTitle: ";
        getline(cin, title);
        cout << "\tPrice: ";
        cin >> price;
        cout << "\tNo. of pages: ";
        cin >> pages;
    }

    void putdata()
    {
        cout << "--------------------------------------------------- \n"
            << "Book details: \n"
            << "\tTitle: " << title << '\n'
            << "\tPrice: " << price << '\n'
            << "\tNo. of pages: " << pages << '\n'
            << "--------------------------------------------------- \n";
    }
};

/* Derived class for audiocassettes */
class Tape : public Publication
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
    }

    void putdata()
    {
        cout << "--------------------------------------------------- \n"
            << "Audiocassette details: \n"
            << "\tTitle: " << title << '\n'
            << "\tPrice: " << price << '\n'
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