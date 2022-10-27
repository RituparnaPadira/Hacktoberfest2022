import java.util.Scanner;

public class UseOfTryCatch{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1= sc.nextInt();
        int n2= sc.nextInt();
        int add =  n1+n2;
        System.out.println("Add ="+add);
        try{
        int div = n1/n2;
        System.out.println("div="+div);
        }catch(Exception e){
            e.printStackTrace();
        }
        finally{
            System.out.println("normal ");
        }
        int mul = n1*n2;
        System.out.println("Mul =" + mul);
    }
}
