/* String manipulations */
package OOPLab.strings;

public class Main {

    public static void main(String[] args) {
        /* External variable accessibility */
        System.out.println("\nExternal variables: \"" + myStrings.a + "\" \"" + myStrings.b + "\"");
        System.out.println("----------------------------------------------");

        /* String Length */
        System.out.println("After strLen:");
        System.out.println("Length of \"" + myStrings.a + "\": " + myStrings.a.strLen());
        System.out.println("Length of \"" + myStrings.b + "\": " + myStrings.b.strLen());
        System.out.println("----------------------------------------------");

        /* String Concatenation */
        myStrings.a = myStrings.a.strCat(myStrings.b);
        System.out.println("After strCat:");
        System.out.println("Concatenation source: \"" + myStrings.b + "\"");
        System.out.println("Concatenation destination: \"" + myStrings.a + "\"");
        System.out.println("----------------------------------------------");

        /* String Comparison */
        int res = myStrings.a.strCmp(myStrings.b);
        System.out.println("After strCmp:");
        if (res == 0)
            System.out.println("Equal strings");
        else if (res > 0)
            System.out.println("Unequal strings: \"" + myStrings.a + "\" > \"" + myStrings.b + "\"");
        else
            System.out.println("Unequal strings: \"" + myStrings.a + "\" < \"" + myStrings.b + "\"");
        System.out.println("----------------------------------------------");

        /* String Upper */
        myStrings.a = myStrings.a.strUpr();
        myStrings.b = myStrings.b.strUpr();
        System.out.println("After strUpr:");
        System.out.println("a = \"" + myStrings.a + "\"");
        System.out.println("b = \"" + myStrings.b + "\"");
        System.out.println("----------------------------------------------");

        /* String Lower */
        myStrings.a = myStrings.a.strLwr();
        myStrings.b = myStrings.b.strLwr();
        System.out.println("After strLwr:");
        System.out.println("a = \"" + myStrings.a + "\"");
        System.out.println("b = \"" + myStrings.b + "\"");
        System.out.println("----------------------------------------------");

        /* String Reverse */
        myStrings.a = myStrings.a.strRev();
        myStrings.b = myStrings.b.strRev();
        System.out.println("After strRev:");
        System.out.println("a = \"" + myStrings.a + "\"");
        System.out.println("b = \"" + myStrings.b + "\"");
        System.out.println("----------------------------------------------");
    }
}