import java.io.Serializable;

public class Product implements Serializable {
    private String name;
    private String code;
    private int buyPrice;
    private int sellPrice;

    static int count;

    public Product(String name, String code, int buyPrice, int sellPrice) {
        System.out.println("Creating a product model.");
        this.name = name;
        this.code = code;
        this.buyPrice = buyPrice;
        this.sellPrice = sellPrice;
        count++;
    }

    public String getName() {
        return name;
    }

    public String getCode() {
        return code;
    }

    public int getBuyPrice() {
        return buyPrice;
    }

    public int getSellPrice() {
        return sellPrice;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public void setBuyPrice(int buyPrice) {
        this.buyPrice = buyPrice;
    }

    public void setSellPrice(int sellPrice) {
        this.sellPrice = sellPrice;
    }

    public void show() {
        System.out.println("+== Product Information ==+");
        System.out.println("Name:" + name);
        System.out.println("Code:" + code);
        System.out.println("buyPrice:" + buyPrice);
        System.out.println("sellPrice:" + sellPrice);
        System.out.println("+== === === ==+");
    }
}
