import java.io.Serializable;

public class Employer extends Person implements Serializable {
    private String account;

    static int count;

    public Employer(String name, String mobile, String cardNumber,
                    String lastName, String telephone, String account) throws InvalidArgumentException {
        System.out.println("Creating a employer model.");
        setMobile(mobile);
        setName(name);
        setLastName(lastName);
        setCardNumber(cardNumber);
        setTelephone(telephone);
        setAccount(account);
        count++;
    }

    public String getName() {
        return name;
    }

    public String getLastName() {
        return lastName;
    }

    public String getTelephone() {
        return telephone;
    }

    public String getAccount() {
        return account;
    }

    public static int getCount() {
        return count;
    }

    public String getMobile() {
        return mobile;
    }

    public String getCardNumber() {
        return cardNumber;
    }

    public void setAccount(String account) throws InvalidArgumentException {
        if (Validator.isWord(account)) {
            this.account = account;
        } else {
            throw new InvalidArgumentException("Invalid account");
        }
    }

    public boolean isValid() {
        return (name.length() > 0 &&
                lastName.length() > 0 &&
                mobile.length() > 0 &&
                telephone.length() > 0 &&
                cardNumber.length() > 0 &&
                account.length() > 0);
    }

    public void show() {
        System.out.println("+== Employer Information ==+");
        System.out.println("Name:" + name);
        System.out.println("Lastname:" + lastName);
        System.out.println("mobile:" + mobile);
        System.out.println("cardNumber:" + cardNumber);
        System.out.println("account:" + account);
        System.out.println("telephone:" + telephone);
        System.out.println("+== === === ==+");
    }

}
