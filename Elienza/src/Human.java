public class Human {

    public Human(String name) {
        this.name = name;
    }

    private String name;

    public String getName() {
//        System.out.println("LOG: Name has been asked"); // LOG
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
