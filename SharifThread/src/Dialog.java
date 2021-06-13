import java.util.ArrayList;
import java.util.Scanner;

public class Dialog {
    public static void Dialog(int i, ArrayList<String> actors) {
        System.out.println(
                actors.get(i) + " to " + actors.get(i+1) + ": ke ba in dar agar dar bande dar manand, dar manand."
        );

        for(int j = i+1; j > 0; j--) {
            System.out.println(
                    actors.get(j) + " to " + actors.get(j-1) + ": dar manand?"
            );
        }

        for(int j = 1; j <= i+1; j++) {
            System.out.println(
                    actors.get(j-1) + " to " + actors.get(j) + ": dar manand."
            );
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        ArrayList<String> actors = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            String name = scanner.next();
            actors.add(name);
        }

        for(int i = 0; i < n-1; i++) {
            Dialog(i, actors);
        }
    }
}
