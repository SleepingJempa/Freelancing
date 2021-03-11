import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();

        int best = 0;
        int temp = 0;
        int cnt = 0;

        for(int i=0; i < str.length(); i++) {
            temp += (str.charAt(i) == '(' ? 1 : -1);
            if (temp >= 0) {
                if (str.charAt(i) == ')') cnt++;
            } else {
                temp = 0;
                cnt = 0;
            }
            best = Math.max(best, cnt);
        }

        System.out.println(best);
    }

}
