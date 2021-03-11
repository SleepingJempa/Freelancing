public class Email extends Document {
    private String subject;
    private String[] to;

    public String getSubject() {
        return subject;
    }

    public String[] getTo() {
        return to;
    }

    public String toString() {
        return subject;
    }
}
