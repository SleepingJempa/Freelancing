public class Validator {
    public static boolean isDigit(char c) {
        return (c >= '0' && c <= '9');
    }

    public static boolean isNumber(String str) {
        if (str.length() == 0) return false;
        for(int i = 0; i < str.length(); i++) {
            if (! isDigit(str.charAt(i))) return false;
        }
        return true;
    }

    public static boolean isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    public static boolean isWord(String str) {
        if (str.length() == 0) return false;
        for(int i = 0; i < str.length(); i++) {
            if (! isAlpha(str.charAt(i))) return false;
        }
        return true;
    }

    public static boolean isWordWithNumber(String str) {
        if (str.length() == 0) return false;
        for(int i = 0; i < str.length(); i++) {
            if (! isAlpha(str.charAt(i)) && ! isDigit(str.charAt(i))) return false;
        }
        return true;
    }

    public static boolean isDate(String str) {
        return (str.length() == 10 &&
                str.charAt(4) == str.charAt(7) &&
                str.charAt(4) == '/');
    }
}
