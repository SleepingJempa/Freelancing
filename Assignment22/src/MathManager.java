import javafx.util.Pair;

import java.util.ArrayList;
import java.util.Collections;

public class MathManager {
    public void insertionSort(ArrayList<Pair<String, Integer>> students){
        for (int i = 0; i < students.size()-1; i++) {
            int j = i;
            while(j >= 0 && students.get(j).compareTo(students.get(j+1)) > 0) { //switch symbol for descending order
                Collections.swap(students, j, j+1);
                j--;
            }
        }
    }

    int getMean(ArrayList<Pair<String, Integer>> students) {
        float mean = 0;
        for(int i = 0; i < students.size(); i++) {
            mean += students.get(i);
        }
        return (mean / students.size();
    }

    int getMode(ArrayList<Pair<String, Integer>> students) {
        int cnt = 0;
        Pair<Integer, Integer> mode;
        for(int i = 0; i < students.size(); i++) {
            cnt++;
            if (students.get(i).getValue() != students.get(0).getValue()) {
                mode = new Pair(cnt, students[0].getValue());
                break;
            }
        }

        for(int i = 1; i < students.size(); i++) {
            int j = i+1;
            while(j < students.size() && students.get(i).getValue() == students.get(j).getValue()) j++;

            int cnt2 = j - i;

            if (cnt2 > mode.getKey()) mode = new Pair(cnt2, students[i].getValue());

            i = j;
        }

        return mode.getValue();
    }

    float getMedian(ArrayList<Pair<String, Integer>> students) {
        if (students.size() % 2 == 0) {
            return (students.get(students.size() / 2) + students.get(students.size() / 2 - 1)) / 2;
        } else {
            return students.get(students.size() / 2);
        }
    }
}
