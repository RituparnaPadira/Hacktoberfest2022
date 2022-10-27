class InvaliAgeException extends Exception{
    public InvaliAgeException(String str){
           super(str);
    }
}

class Vote{
    public void validate(int age) throws InvaliAgeException{
        if(age<18){
            throw new InvaliAgeException("age is not invalid");
        }else{
            System.out.println("you can vote");
        }
    }
}


public class CustomExceptionExample {
    public static void main(String[] args) {
        Vote v = new Vote();
        try{
            v.validate(19);
        }
        catch(InvaliAgeException age){
            System.out.println("custome exception");
            age.printStackTrace();
        }
        finally{
            System.out.println("Normal flow");
        }
    }
}
