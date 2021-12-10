/* Public and Private Inheritance */
#include <iostream>
#include <fstream>
using namespace std;

class OpenFile
{
protected:
    fstream file;

public:
    /* Member function to write in file */
    void write()
    {
        file.open("alphabet.txt", ios::out);
        for (char c = 'A'; c <= 'Z'; c++)
            file << c;
        file.close();
    }

    /* Member function to read from file */
    void read()
    {
        char c;
        file.open("alphabet.txt", ios::in);
        while (!file.eof())
        {
            c = ' ';
            file >> c;
            std::cout << c;
        }
        std::cout << '\n';
        file.close();
    }
};

/* Derived class for admin */
class admin : public OpenFile { };

/* Derived class for user */
class user : private OpenFile
{
public:
    void read()
    {
        OpenFile::read();
    }
};

int main()
{
    admin a1;
    user u1;
    cout << "Writing in file with admin \n";
    a1.write();
    cout << "\nReading from file with admin \n";
    a1.read();
    cout << "\nReading from file with user \n";
    u1.read();
    return 0;
}