#include <iostream>
#include "Functions.h"
using namespace std;

int main()
{
    /* Extern variable accessibility */
    a[0] = 'D';

    /* String Length */
    cout << "After strLen: \n"
        << "Length of \"" << a << "\": " << strLen(a) << "\n"
        << "Length of \"" << b << "\": " << strLen(b) << "\n"
        << "---------------------------------------------- \n";

    /* String Concatenation */
    strCat(a, b);
    cout << "After strCat: \n"
        << "Concatenation source : \"" << b << "\" \n"
        << "Concatenation destination: \"" << a << "\" \n"
        << "---------------------------------------------- \n";

    /* String Comparison */
    int res = strCmp(a, b);
    cout << "After strCmp: \n";
    if (res == 0)
        cout << "Equal strings \n";
    else if (res > 0)
        cout << "Unequal strings: \"" << a << "\" > \"" << b << "\" \n";
    else
        cout << "Unequal strings: \"" << a << "\" < \"" << b << "\" \n";
    cout << "---------------------------------------------- \n";

    /* String Upper */
    strUpr(a);
    strUpr(b);
    cout << "After strUpr: \n"
        << "a = \"" << a << "\" \n"
        << "b = \"" << b << "\" \n"
        << "---------------------------------------------- \n";

    /* String Lower */
    strLwr(a);
    strLwr(b);
    cout << "After strLwr: \n"
        << "a = \"" << a << "\" \n"
        << "b = \"" << b << "\" \n"
        << "---------------------------------------------- \n";

    /* String Reverse */
    strRev(a);
    strRev(b);
    cout << "After strRev: \n"
        << "a = \"" << a << "\" \n"
        << "b = \"" << b << "\" \n"
        << "---------------------------------------------- \n";

    return 0;
}