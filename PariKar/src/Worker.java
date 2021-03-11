import java.io.Serializable;

public class Worker extends Person implements Serializable {
    private String project;
    private String position;
    private String creditOrDebtor;
    private boolean precedent;

    static int count;

        public Worker(String name, String lastName, String cardNumber,
                      String mobile, String telephone, String position,
                      String project, String creditOrDebtor,
                      boolean precedent) throws InvalidArgumentException {
        System.out.println("Creating a worker model.");
        setMobile(mobile);
        setName(name);
        setLastName(lastName);
        setCardNumber(cardNumber);
        setTelephone(telephone);
        setProject(project);
        setPosition(position);
        setCreditOrDebtor(creditOrDebtor);
        setPrecedent(precedent);
        count++;
    }

    public String getProject() {
        return project;
    }

    public String getPosition() {
        return position;
    }

    public String getCreditOrDebtor() {
        return creditOrDebtor;
    }

    public boolean isPrecedent() {
        return precedent;
    }
    
    public void setProject(String project) {
        this.project = project;
    }

    public void setPosition(String position) throws InvalidArgumentException {
        if (Validator.isWord(position)) {
            this.position = position;
        } else {
            throw new InvalidArgumentException("Invalid position");
        }
    }

    public void setCreditOrDebtor(String creditOrDebtor) throws InvalidArgumentException {
        if (Validator.isWord(creditOrDebtor)) {
            this.creditOrDebtor = creditOrDebtor;
        } else {
            throw new InvalidArgumentException("Invalid creditOrDebtor");
        }
    }

    public void setPrecedent(boolean precedent) {
        this.precedent = precedent;
    }

    public boolean isValid() {
        return (name.length() > 0 &&
                lastName.length() > 0 &&
                mobile.length() > 0 &&
                telephone.length() > 0 &&
                cardNumber.length() > 0 &&
                project.length() > 0 &&
                position.length() > 0 &&
                creditOrDebtor.length() > 0);
    }

    public void show() {
        System.out.println("+== Worker Information ==+");
        System.out.println("Name:" + name);
        System.out.println("Last Name:" + lastName);
        System.out.println("Mobile:" + mobile);
        System.out.println("Card Number:" + cardNumber);
        System.out.println("Project:" + project);
        System.out.println("telephone:" + telephone);
        System.out.println("position:" + position);
        System.out.println("precedent:" + precedent);
        System.out.println("creditOrDebtor:" + creditOrDebtor);
        System.out.println("+== === === ==+");
    }
}
