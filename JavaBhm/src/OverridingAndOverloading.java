public class OverridingAndOverloading extends Parent {
    @Override
    public void sayHello(String name) {
        System.out.println("Hi " + name);
    }

    // Overloading
    public void sayHello(String name, String nickname) {
        System.out.println("Hey " + name + " (" + nickname + ")");
    }
}
