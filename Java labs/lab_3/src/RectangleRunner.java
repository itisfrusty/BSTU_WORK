public class RectangleRunner {
        public static void main(String[] args) {
            Rectangle rect1 = new Rectangle(4,8);
            Rectangle rect2 = new Rectangle(5,9);

            System.out.println("Rectangle ONE perimeter: " + rect1.perimeter());
            System.out.println("Rectangle TWO perimeter: " + rect2.perimeter());

            System.out.println("\nRectangle ONE area: " + rect1.area());
            System.out.println("Rectangle TWO area: " + rect2.area());

            System.out.println("\nRectangle ONE is square: " + rect1.square());
            System.out.println("Rectangle TWO is square: " + rect2.square());

            System.out.println("\nRectangle ONE equals to Rectangle TWO: " + rect1.equals(rect2));
        }
}
