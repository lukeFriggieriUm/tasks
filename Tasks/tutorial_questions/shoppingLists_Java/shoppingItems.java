package Tasks.tutorial_questions.shoppingLists_Java;
import java.io.*;
import java.util.*;

public class shoppingItems {
    public static void main(String[] args) {
        List<Item> list = new ArrayList<>();
        try (Scanner inFile = new Scanner(new File("shopping_list.txt"))) {
            while (inFile.hasNext()) {
                String type = inFile.next();
                Item item = null;
                switch (type) {
                    case "Grocery":
                        item = new Grocery(inFile.next(), inFile.next(), inFile.nextFloat());
                        break;
                    case "Electronics":
                        item = new Electronics(inFile.next(), inFile.next(), inFile.nextFloat());
                        break;
                    // Add cases for Clothing, Book, and Toys...
                }
                if (item != null) {
                    list.add(item);
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("File not found, starting fresh.");
        }

        try (Scanner scanner = new Scanner(System.in)) {
            char choice;
            do {
                System.out.print("Add item (g = Grocery, e = Electronics, t = Toys, c = Clothing x = exit): ");
                choice = scanner.next().charAt(0);
                Item item = null;
                switch (choice) {
                    case 'g':
                        item = new Grocery();
                        item.input(scanner);
                        break;
                    case 'e':
                        item = new Electronics();
                        item.input(scanner);
                        break;
                    case 'b':
                        item = new Book();
                        item.input(scanner);
                        break;
                    case 'c':
                        item = new Clothing();
                        item.input(scanner);
                        break;
                    case 't':
                        item = new Toys();
                        item.input(scanner);
                        break;    
                    case 'x':
                        break;
                    default:
                        System.out.println("Invalid Choice");    
                }
                if (item != null) {
                    list.add(item);
                }
                System.out.print("Do you want to add more items? (y/n): ");
                choice = scanner.next().charAt(0);
            } while (choice == 'y');
        }

        System.out.println("Current Shopping List:");
        for (Item item : list) {
            item.display();
        }

        try (PrintWriter outFile = new PrintWriter(new FileWriter("shopping_list.txt"))) {
            for (Item item : list) {
                item.persist(outFile);
            }
        } catch (IOException e) {
            System.out.println("Error saving the file.");
        }
    }
}