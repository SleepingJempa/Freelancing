import java.io.Serializable;

public class Person implements Serializable {
    protected String name;
    protected String lastName;
    protected String mobile;
    protected String telephone;
    protected String cardNumber;

    public void setName(String name) throws InvalidArgumentException {
        if(Validator.isWord(name)) {
            this.name = name;
        } else {
            throw new InvalidArgumentException("Invalid name");
        }
    }

    public void setLastName(String lastName) throws InvalidArgumentException {
        if(Validator.isWord(lastName)) {
            this.lastName = lastName;
        } else {
            throw new InvalidArgumentException("Invalid lastName");
        }
    }

    public void setTelephone(String telephone) throws InvalidArgumentException {
        if (Validator.isNumber(telephone)) {
            this.telephone = telephone;
        } else {
            throw new InvalidArgumentException("Invalid telephone");
        }
    }

    public void setMobile(String mobile) throws InvalidArgumentException {
        if (Validator.isNumber(mobile)) {
            if (mobile.startsWith("09")) {
                this.mobile = mobile;
            } else {
                throw new InvalidArgumentException("Invalid mobile");
            }
        } else {
            throw new InvalidArgumentException("Invalid mobile");
        }
    }

    public void setCardNumber(String cardNumber) throws InvalidArgumentException {
        if (Validator.isNumber(cardNumber)) {
            this.cardNumber = cardNumber;
        } else {
            throw new InvalidArgumentException("Invalid cardNumber");
        }
    }
}
