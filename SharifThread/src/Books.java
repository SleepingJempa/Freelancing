import java.util.Scanner;

public class Books {
    private Node head;

    Books() {
        head = null;
    }

    static class Node {
        String name;
        Node next;

        public Node(String name) {
            this.name = name;
            this.next = null;
        }
    }

    public void insert(String name) {
        Node node = new Node(name);

        Node trav = head;
        Node prev = null;

        while(trav != null && name.compareTo(trav.name) > 0) {
            prev = trav;
            trav = trav.next;
        }

        if (prev == null) {
            head = node;
        } else {
            prev.next = node;
        }

        node.next = trav;

        System.out.println("Book Inserted: " + name);
    }

    public void show() {
        Node trav = head;

        System.out.print("List of Books: ");

        while(trav != null) {
            System.out.print(trav.name + " ");
            trav = trav.next;
        }

        System.out.println();
    }

    public void delete(String name) {
        Node trav = head;
        Node prev = null;

        while(trav != null && name.compareTo(trav.name) > 0) {
            prev = trav;
            trav = trav.next;
        }

        if (trav.name.equals(name)) {
            if (prev != null) {
                prev.next = trav.next;
            } else {
                head = trav.next;
            }
            System.out.println("Book Deleted: " + name);
        } else {
            System.out.println("Book Not Founded: " + name);
        }

    }

    public static void main(String[] args) {
        Books b = new Books();
        Scanner scanner = new Scanner(System.in);

        String cmd = "";
        while (true) {
            cmd = scanner.next();

            if (cmd.equals("insert")) {
                String name = scanner.next();
                b.insert(name);
            }

            if (cmd.equals("delete")) {
                String name = scanner.next();
                b.delete(name);
            }

            if (cmd.equals("show")) {
                b.show();
            }

            if (cmd.equals("exit")) {
                break;
            }
        }
    }
}
