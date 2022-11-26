import java.util.Scanner;

public class task_1 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in); // Объявляем Scanner
        System.out.println("Enter array length: ");
        int size = input.nextInt(); // Читаем с клавиатуры размер массива и записываем в size
        int array[] = new int[size]; // Создаём массив int размером в size
        int sum = 0;
        int proiz = 1;
        System.out.println("Insert array elements:");

        /*Пройдёмся по всему массиву, заполняя его*/
        for (int i = 0; i < size; i++) {
            array[i] = input.nextInt(); // Заполняем массив элементами, введёнными с клавиатуры
        }
        System.out.println ("Inserted array elements:");
        for (int i = 0; i < size; i++) {
            System.out.print (" " + array[i]); // Выводим на экран, полученный массив
        }

        int max = getMax(array);
        System.out.println("\nMaximum value is: "+max);

        // Вызов метода getMin () для получения минимального значения
        int min = getMin(array);
        System.out.println("Minimum value is: "+min);

        for (int b =0; b < size; b++ ) {
            sum = sum + array[b];
        }
        System.out.println("Sum of values is: "+sum);

        for (int i =0; i < size; i++ ) {
            proiz = proiz * array[i];
        }
        System.out.println("Multiplication of values is: "+proiz);
        System.out.println();
    }
    public static int getMax(int[] inputArray){
        int maxValue = inputArray[0];
        for(int i=1;i < inputArray.length;i++){ if(inputArray[i] > maxValue){
            maxValue = inputArray[i];
        }
        }
        return maxValue;
    }
    public static int getMin(int[] inputArray){
        int minValue = inputArray[0];
        for(int i=1;i<inputArray.length;i++){
            if(inputArray[i] < minValue){
                minValue = inputArray[i];
            }
        }
        return minValue;
    }
}
