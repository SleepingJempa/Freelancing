import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static ArrayList<Employer> employers;
    static ArrayList<Worker> workers;
    static ArrayList<Product> products;
    static Scanner input;

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        employers = new ArrayList<>();
        workers = new ArrayList<>();
        products = new ArrayList<>();
        input = new Scanner(System.in);

        int operation;
        boolean flag = true;

        try {
            loadApp();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        
        while(flag) {
            System.out.println("What do you want to do:");
            System.out.println("1: Register a new employer");
            System.out.println("2: Register a new worker");
            System.out.println("3: view employers list");
            System.out.println("4: view workers list");
            System.out.println("5: List of products");
            System.out.println("6: Add a new product to the list");
            System.out.println("7: AP costs");
            System.out.println("8: Add Ap Cost");
            System.out.println("0: Exit");
            operation = input.nextInt();

            switch (operation) {
                case 1:
                    addEmployer();
                    break;
                case 2:
                    addWorker();
                    break;
                case 3:
                    showEmployers();
                    break;
                case 4:
                    showWorkers();
                    break;
                case 5:
                    showProducts();
                    break;
                case 6:
                    addProduct();
                    break;
                case 7:
                    apCosts();
                    break;
                case 8:
                    flag = false;
            }
        }

        try {
            saveAndExit();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private static void loadApp() throws IOException, ClassNotFoundException {
        loadEmployers();
        loadWorkers();
        loadProducts();
    }

    private static void loadProducts() throws IOException, ClassNotFoundException {
        File test = new File("./src/products");
        if (test.length() == 0) return;

        FileInputStream file = new FileInputStream("./src/products");
        ObjectInputStream in = new ObjectInputStream(file);

        if (file.available() != 0) products = (ArrayList<Product>) in.readObject();

        in.close();
        file.close();
    }

    private static void loadEmployers() throws IOException, ClassNotFoundException {
        File test = new File("./src/employers");
        if (test.length() == 0) return;

        FileInputStream file = new FileInputStream("./src/employers");
        ObjectInputStream in = new ObjectInputStream(file);

        if (file.available() != 0) employers = (ArrayList<Employer>) in.readObject();

        in.close();
        file.close();
    }

    private static void loadWorkers() throws IOException, ClassNotFoundException {
        File test = new File("./src/workers");
        if (test.length() == 0) return;

        FileInputStream file = new FileInputStream("./src/workers");
        ObjectInputStream in = new ObjectInputStream(file);

        if (file.available() != 0) workers = (ArrayList<Worker>) in.readObject();

        in.close();
        file.close();
    }

    private static void saveAndExit() throws IOException {
        saveEmployers();
        saveWorkers();
        saveProducts();
    }

    private static void saveProducts() throws IOException {
        FileOutputStream file = new FileOutputStream("./src/products");
        ObjectOutputStream out = new ObjectOutputStream(file);

        out.writeObject(products);

        out.close();
        file.close();
    }

    private static void saveWorkers() throws IOException {
        FileOutputStream file = new FileOutputStream("./src/workers");
        ObjectOutputStream out = new ObjectOutputStream(file);

        out.writeObject(workers);

        out.close();
        file.close();
    }

    private static void saveEmployers() throws IOException {
        FileOutputStream file = new FileOutputStream("./src/employers");
        ObjectOutputStream out = new ObjectOutputStream(file);

        out.writeObject(employers);

        out.close();
        file.close();
    }

    private static void apCosts() {

    }

    private static void addProduct() {
        String name;
        String code;
        int buyPrice;
        int sellPrice;

        System.out.println("Enter name");
        name = input.next();

        System.out.println("Enter code");
        code = input.next();

        System.out.println("Enter buyPrice");
        buyPrice = input.nextInt();

        System.out.println("Enter sellPrice");
        sellPrice = input.nextInt();

        Product product = new Product(name, code, buyPrice, sellPrice);
        products.add(product);
    }

    private static void showProducts() {
        for(Product product : products) {
            product.show();
        }
    }

    private static void showWorkers() {
        for(Worker worker : workers) {
            worker.show();
        }
    }

    private static void showEmployers() {
        for(Employer employer : employers) {
            employer.show();
        }
    }

    private static void addWorker() {
        String name;
        String lastName;
        String cardNumber;
        String mobile;
        String telephone;
        String project;
        String position;
        String creditOrDebtor;
        boolean precedent;

        System.out.println("Enter name");
        name = input.next();

        System.out.println("Enter mobile");
        mobile = input.next();

        System.out.println("Enter lastName");
        lastName = input.next();

        System.out.println("Enter cardNumber");
        cardNumber = input.next();

        System.out.println("Enter telephone");
        telephone = input.next();

        System.out.println("Enter position");
        position = input.next();

        System.out.println("Enter project");
        project = input.next();

        System.out.println("Enter creditOrDebtor");
        creditOrDebtor = input.next();

        System.out.println("Enter precedent (0 false & 1 true)");
        int thePrecedent = input.nextInt();
        precedent = (thePrecedent == 0 ? false : true);

        try {
            Worker worker = new Worker(name, lastName, cardNumber, mobile, telephone,
                    position, project, creditOrDebtor, precedent);
            workers.add(worker);
        } catch (InvalidArgumentException e) {
            e.printStackTrace();
        }
    }

    public static void addEmployer() {
        String name;
        String lastName;
        String cardNumber;
        String mobile;
        String telephone;
        String account;

        System.out.println("Enter name");
        name = input.next();

        System.out.println("Enter lastName");
        lastName = input.next();

        System.out.println("Enter cardNumber");
        cardNumber = input.next();

        System.out.println("Enter mobile");
        mobile = input.next();

        System.out.println("Enter telephone");
        telephone = input.next();

        System.out.println("Enter account");
        account = input.next();

        try {
            Employer employer = new Employer(name, mobile, cardNumber, lastName,
                    telephone, account);
            employers.add(employer);
        } catch (InvalidArgumentException e) {
            e.printStackTrace();
        }
    }
}
