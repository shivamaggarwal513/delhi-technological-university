/* String methods */
package OOPLab.strings;

class myStrings {
    public static myStrings a = new myStrings("Shivam");
    public static myStrings b = new myStrings("Aggarwal");

    private String str;

    public myStrings(String str) {
        this.str = str;
    }

    public myStrings strCat(String source) {
        str += source;
        return this;
    }

    public myStrings strCat(myStrings source) {
        return this.strCat(source.str);
    }

    public myStrings strRev() {
        int len = str.length();
        StringBuilder rev = new StringBuilder(len);
        for (int i = 0; i < len; i++) {
            rev.append(str.charAt(len - i - 1));
        }
        str = rev.toString();
        return this;
    }

    public myStrings strUpr() {
        int len = str.length();
        StringBuilder upr = new StringBuilder(len);
        for (int i = 0; i < len; i++) {
            char c = str.charAt(i);
            if (c >= 'a' && c <= 'z') {
                c = (char) (c + 'A' - 'a');
            }
            upr.append(c);
        }
        str = upr.toString();
        return this;
    }

    public myStrings strLwr() {
        int len = str.length();
        StringBuilder lwr = new StringBuilder(len);
        for (int i = 0; i < len; i++) {
            char c = str.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                c = (char) (c + 'a' - 'A');
            }
            lwr.append(c);
        }
        str = lwr.toString();
        return this;
    }

    public int strLen() {
        return str.length();
    }

    public int strCmp(myStrings comp) {
        int i = 0;
        int len = Math.max(str.length(), comp.strLen()) - 1;

        while (str.charAt(i) == comp.str.charAt(i) && (i < len))
            i++;
        return str.charAt(i) - comp.str.charAt(i);
    }

    @Override
    public String toString() {
        return str;
    }
}