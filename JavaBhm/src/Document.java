import java.util.Date;

public class Document {
    private String[] authors;
    private Date date;

    public String[] getAuthors() {
        return authors;
    }

    public Date getDate() {
        return date;
    }

    public void addAuthor(String name) {
        String tempAuthors[] = new String[authors.length + 1];

        for(int i = 0; i < authors.length; i++) {
            tempAuthors[i] = authors[i];
        }

        tempAuthors[authors.length] = name;

        authors = tempAuthors;
    }

    public String toString() {
        String result = "Authors: ";

        for(int i = 0; i < authors.length; i++) {
            result += authors[i] + " ";
        }

        return result;
    }
}
