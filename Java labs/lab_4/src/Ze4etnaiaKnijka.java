import java.util.Scanner;

public class Ze4etnaiaKnijka {
    public static Scanner ob = new Scanner(System.in);
    public info info;
    public String city;

    public Ze4etnaiaKnijka() {
        System.out.print("введите Фамилию студента: ");
        setZe4etnaiaKnijka(ob.next());
        info = new info();
    }

    public String getZe4etnaiaKnijka() {
        return city;
    }

    public void setZe4etnaiaKnijka(String city) {
        this.city = city;
    }

    public class info {
        int pr, st, sq;

        public info() {
            System.out.print("сессия №: ");
            setPr(ob.nextInt());
            System.out.print("количество сданных зачётов: ");
            setSt(ob.nextInt());
            System.out.print("кол-во сданных экзаменов: ");
            setSq(ob.nextInt());
        }

        public int getPr() {
            return pr;
        }

        public void setPr(int pr) {
            this.pr = pr;
        }

        public int getSt() {
            return st;
        }

        public void setSt(int st) {
            this.st = st;
        }

        public int getSq() {
            return sq;
        }

        public void setSq(int sq) {
            this.sq = sq;
        }

        public void print() {
            System.out.print("Студент по фамилии" + " " + getZe4etnaiaKnijka() + " сдал" + " " + getPr() + " сессию" + ", в числе которой: " + getSt() + " зачетов" + " и " + getSq() + " экзаменов");
        }
    }

    static public void main(String[] args) {
        Ze4etnaiaKnijka ct = new Ze4etnaiaKnijka();
        ct.info.print();
    }
}