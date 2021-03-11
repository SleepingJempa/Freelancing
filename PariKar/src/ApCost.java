import java.io.Serializable;

public class ApCost implements Serializable {
    private AP_TYPE type;
    private String title;
    private int amount;
    private String date;
    private String description;

    public ApCost(String type, String title, int amount, String date, String description) throws InvalidArgumentException {
        setType(type);
        setTitle(title);
        setAmount(amount);
        setDate(date);
        setDescription(description);
    }

    public AP_TYPE getType() {
        return type;
    }

    public String getTitle() {
        return title;
    }

    public int getAmount() {
        return amount;
    }

    public String getDate() {
        return date;
    }

    public String getDescription() {
        return description;
    }

    public void setType(String type) {
        if (type == AP_TYPE.INCOME.toString()) {
            this.type = AP_TYPE.INCOME;
        } else if (type == AP_TYPE.CHARGE.toString()) {
            this.type = AP_TYPE.CHARGE;
        } else {
            System.out.println("Invalid type");
        }
    }

    public void setTitle(String title) {
        if (Validator.isWord(title)) {
            this.title = title;
        } else {
            System.out.println("Invalid title");
        }
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    public void setDate(String date) throws InvalidArgumentException {
        if (Validator.isDate(date)) {
            this.date = date;
        } else {
            throw new InvalidArgumentException("Invalid date");
        }
    }

    public void setDescription(String description) {
        if (Validator.isWord(description)) {
            this.description = description;
        } else {
            System.out.println("Invalid description");
        }
    }
}
