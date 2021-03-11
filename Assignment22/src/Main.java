import javafx.util.Pair;
import java.util.*;


public class Main {
    public static void main(String[] args) {
        String name;
        int mark;

        Scanner scanner = new Scanner(System.in);

        ArrayList<Pair<String, Integer>> students = null;

        while(true) {
            name = scanner.next();

            if (name == "-1") break;

            mark = scanner.nextInt();

            if (mark < 0 && mark > 100) {
                System.out.println("Invalid mark, please try again.");
            }

            students.add(new Pair(name, mark));
        }

        MathManager mathManager = new MathManager();

        mathManager.insertionSort(students);
        
        int mean = mathManager.getMean(students);

        int mode = mathManager.getMode(students);

        float median = mathManager.getMedian(students);

        System.out.println("Mean: " + mean);

        System.out.println("Mode: " + mode);

        System.out.println("Median: " + median);
    }
}
