import java.util.Scanner;

public class Masmali {
    public static int ans(String s, int n, int k) {
        if (s.length() == 2 * n) return 1;

        if (k < 0) return -1;

        int theI = k < 2 * n - s.length() ? ans(s + "I", n, k + 1) : 0;
        int theO = k > 0 ? ans(s + 'O', n, k - 1) : 0;

        return theI + theO;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();

        int k = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            k += c == 'I' ? +1 : -1;
        }
        System.out.println(ans(s, n, k));
    }
}
