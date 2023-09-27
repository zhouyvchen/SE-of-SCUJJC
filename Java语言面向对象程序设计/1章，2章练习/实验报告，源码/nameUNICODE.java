package src.HomeWork;

public class nameUNICODE {
    public static void main(String[] args) {
        String name = "名字";

        System.out.println("名字 Unicode 表中的位置：");
        for (char c : name.toCharArray()) {
            System.out.println(c + ": " + (int) c);
        }
    }
}
