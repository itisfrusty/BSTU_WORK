import java.io.*;
import java.util.Arrays;

public class task_1 {

    public static void main(String[] args) {

        try(FileReader reader = new FileReader("task1.txt"))
        {
            char[] buf = new char[256];
            int c;
            while((c = reader.read(buf))>0){

                if(c < 256){
                    buf = Arrays.copyOf(buf, c);
                }
                //String str = new String(buf);
                //String reverse = new StringBuffer(str).reverse().toString();
                //System.out.println("\nСтрока до реверса: " + str);
                //System.out.println("Строка в обратном порядке, после реверса: " + reverse);
            }
            reverse(buf);
        }
        catch(IOException ex){

            System.out.println(ex.getMessage());
        }

    }
    // обратный порядок массива
    public static void reverse(char[] buf) {

        // вывод в обратном порядке
        for (int i = 0; i < buf.length; i ++) {
            System.out.print(buf[i] + " ");
        }
        System.out.println("\n");
        // обратный порядок массива
        int temp = 0;
        for (int min = 0,max = buf.length - 1; min < max; min ++,max --) {
            temp = buf[min];
            buf[min] = buf[max];
            buf[max] = (char) temp;
        }

        // вывод в обратном порядке
        for (int i = 0; i < buf.length; i ++) {
            System.out.print(buf[i] + " ");
        }
    }
}