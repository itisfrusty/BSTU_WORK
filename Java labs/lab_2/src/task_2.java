import java.util.*;
import java.lang.*;

public class task_2 {
    public static void main(String[] args) throws java.io.IOException
    {
        Scanner in = new Scanner(System.in);
        String s1;
        s1=in.nextLine();
        ProcessBuilder pb = new ProcessBuilder("cmd", "-c", s1);
        pb.start();
    }
}