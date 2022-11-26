public class Rectangle
{
    private int height;
    private int width;

    public boolean equals(Rectangle rectangle) {
        if (this.height==rectangle.height && this.width==rectangle.width)
            return true;
        return false;
    }
    public Rectangle(int height, int width) {
        this.height = height;
        this.width = width;
    }

    public int perimeter() {
        return height*2 + width*2;
    }

    public boolean square(){
        if (height == width)
            return true;
        return false;
    }

    public int area() {
        return height*width;
    }

}
