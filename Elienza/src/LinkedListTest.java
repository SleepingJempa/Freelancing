public class LinkedListTest {

    public static void main(String[] args) {

        Node a = new Node(1);
        a.next = new Node(2);

        Node b = new Node(3);
        b.next = new Node(4);
        Node t = b;
        b = a;


        System.out.println(a.equals(b));
//        Node head = new Node(1);
//
//        head.next = new Node(-2);
//
//        head.next.next = new Node(3);
//
//        Node trav = head;
//
//        while(trav != null) {
//            System.out.println(trav.value);
//
////            trav.next.next
//            trav = trav.next;
////            trav.next
//        }
    }

}
