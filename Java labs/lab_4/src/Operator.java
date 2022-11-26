public class Operator
{
    private String firstName;
    private String lastName;
    // Оператор управляет конкретным роботом
    private Robot robot;

    public Operator(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    // У оператора можно спросить каким роботом он управляет
    public Robot getRobot() {
        return robot;
    }

    // Оператору можно поручить управлять роботом
    public void setRobot(Robot robot) {
        this.robot = robot;
    }
    static public void main(String[]args){
        Robot rb = new Robot(2.6,7.9);
        rb.getCourse();
        rb.printCoordinates();
    }
}