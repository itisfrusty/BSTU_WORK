import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Library {
    /*int[] UDK ;
    String[] FIOavt;
    String[] bookname;
    int[] year;
    int[] koleks;
    int[] kolstr;
    int[] toms;
    String[] FIOpolz;
    int[] dni; */

    public static void allInfo() {
        System.out.println("All information in data.txt: ");
        try (FileReader reader = new FileReader("data.txt")) {
            int c;
            while ((c = reader.read()) != -1) {

                System.out.print((char) c);
            }
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    public static void allBooks() {
        ArrayList<String> list = new ArrayList<>();
        try (Scanner scan = new Scanner(new File("data.txt"))) {
            while (scan.hasNextLine()) {
                list.add(scan.nextLine());
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        System.out.println("\nList of all books: ");
        String[] array = list.toArray(new String[0]);
        for (int i = 2; i < array.length - 1; i += 10) {
            System.out.println(array[i]);
        }
        System.out.println("\n---------------------------------------" +
                "\nList of books greater then 20 years: ");
        for (int i = 3; i < array.length - 1; i += 10) {
            int b = Integer.parseInt(array[i]);
            if (2022 - b > 20)
                System.out.println(array[i - 1]);
        }
        System.out.println("\n---------------------------------------" +
                "\nList of books taken for reading: ");
        int c=0;
        for (int i = 8; i < array.length - 1; i += 10) {
            if (!array[i].isEmpty()){
                c = Integer.parseInt(array[i]);
                System.out.println(array[i - 6] + " chitaet " + array[i - 1]);
            }
        }
        System.out.println("\n---------------------------------------" +
                "\nList of books whose deadline has been exceeded: ");
        int b=0;
        for (int i = 8; i < array.length - 1; i += 10) {
            if (!array[i].isEmpty()) {
                b = Integer.parseInt(array[i]);
                if (b > 14) {
                    System.out.println(array[i - 6]);
                }
            }
        }
    }
}

