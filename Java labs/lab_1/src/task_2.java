import java.util.Arrays;
import java.util.Scanner;

public class task_2 {
    static void reverse(int[] arr){
        int temp;
        for (int i = arr.length-1, j = 0; i >=arr.length/2 ; i--,j++) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        System.out.print("Input massive size: ");
        int sizeArr = in.nextInt();

        int[] arr = new int[sizeArr];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (int) (Math.random()*20-5);
        }

        System.out.print("Vash massiv viglyadit tak: ");
        for(int key : arr){ System.out.print(key+" "); }


        System.out.print("\nPerevernutiy massiv: ");
        reverse(arr);
        for(int key : arr){ System.out.print(key+" "); }

        System.out.print("\nProverka cherez toString: ");
        System.out.println(" "+Arrays.toString(arr));
    }
}
