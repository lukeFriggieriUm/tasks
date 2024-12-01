package Tasks.tutorial_questions.shoppingLists_Java;

import java.io.*;
import java.util.*;

abstract class Item {
    public abstract void display();
    public abstract void persist(PrintWriter out);
    public abstract void input(Scanner scanner);
}

class Grocery extends Item {
    private String name, expiryDate;
    private float price;

    public Grocery() {
        this.name = "";
        this.expiryDate = "";
        this.price = 0.0f;
    }

    public Grocery(String name, String expiryDate, float price) {
        this.name = name;
        this.expiryDate = expiryDate;
        this.price = price;
    }

    public String getName() { return name; }
    public String getExpiryDate() { return expiryDate; }
    public float getPrice() { return price; }

    public void setName(String name) { this.name = name; }
    public void setExpiryDate(String expiryDate) { this.expiryDate = expiryDate; }
    public void setPrice(float price) { this.price = price; }

    @Override
    public void display() {
        System.out.println("Grocery: " + name + ", Price: " + price + ", Expiry Date: " + expiryDate);
    }

    @Override
    public void persist(PrintWriter out) {
        out.println("Grocery " + name + " " + price + " " + expiryDate);
    }

    @Override
    public void input(Scanner scanner) {
        System.out.print("Enter the name: ");
        name = scanner.next();
        System.out.print("Enter the expiry date: ");
        expiryDate = scanner.next();
        System.out.print("Enter the price: ");
        price = scanner.nextFloat();
    }
}

class Electronics extends Item {
    private String name, warranty;
    private float price;

    public Electronics() {
        this.name = "";
        this.warranty = "";
        this.price = 0.0f;
    }

    public Electronics(String name, String warranty, float price) {
        this.name = name;
        this.warranty = warranty;
        this.price = price;
    }

    @Override
    public void display() {
        System.out.println("Electronics: " + name + ", Price: " + price + ", Warranty: " + warranty);
    }

    @Override
    public void persist(PrintWriter out) {
        out.println("Electronics " + name + " " + price + " " + warranty);
    }

    @Override
    public void input(Scanner scanner) {
        System.out.print("Enter the name: ");
        name = scanner.next();
        System.out.print("Enter the warranty: ");
        warranty = scanner.next();
        System.out.print("Enter the price: ");
        price = scanner.nextFloat();
    }
}

class Clothing extends Item{
    private String type, size;
    private float price;

    public Clothing(){
        this.type = "";
        this.size = "";

        this.price = 0.0f;
    }

    public Clothing(String type, String size, float price){
        this.type = type;
        this.size = size;
        this.price = price;
    }

    @Override
    public void display() {
        System.out.println("Clothing: " + type + ", Price: " + price + ", Size: " + size);
    }

    @Override
    public void persist(PrintWriter out) {
        out.println("Clothing " + type + " " + price + " " + size);
    }

    @Override
    public void input(Scanner scanner) {
        System.out.print("Enter the type: ");
        type = scanner.next();
        System.out.print("Enter the size: ");
        size = scanner.next();
        System.out.print("Enter the price: ");
        price = scanner.nextFloat();
    }
}

class Book extends Item{
    private String name, genre;
    private float price;

    public Book() {
        this.name = "";
        this.genre = "";
        this.price = 0.0f;
    }

    public Book(String name, String genre, float price) {
        this.name = name;
        this.genre = genre;
        this.price = price;
    }

    @Override
    public void display() {
        System.out.println("Book: " + name + ", Price: " + price + ", Genre: " + genre);
    }

    @Override
    public void persist(PrintWriter out) {
        out.println("Book " + name + " " + price + " " + genre);
    }

    @Override
    public void input(Scanner scanner) {
        System.out.print("Enter the name: ");
        name = scanner.next();
        System.out.print("Enter the genre: ");
        genre = scanner.next();
        System.out.print("Enter the price: ");
        price = scanner.nextFloat();
    }
}

class Toys extends Item {
    private String type, warranty;
    private float price;

    public Toys() {
        this.type = "";
        this.warranty = "";
        this.price = 0.0f;
    }

    public Toys(String type, String warranty, float price) {
        this.type = type;
        this.warranty = warranty;
        this.price = price;
    }

    @Override
    public void display() {
        System.out.println("Toys: " + type + ", Price: " + price + ", Warranty: " + warranty);
    }

    @Override
    public void persist(PrintWriter out) {
        out.println("Toys " + type + " " + price + " " + warranty);
    }

    @Override
    public void input(Scanner scanner) {
        System.out.print("Enter the type: ");
        type = scanner.next();
        System.out.print("Enter the warranty: ");
        warranty = scanner.next();
        System.out.print("Enter the price: ");
        price = scanner.nextFloat();
    }
}




