package program1;
import java.util.ArrayList;
import java.util.Scanner;

public class Reader {
    // constructor
    Reader(){setData();}

    // methods
    ArrayList<Float> getData(){return numsList;};
    void setData(){addNums();}
    boolean isNumerical(String string) {
        float floatValue;
        try {
            floatValue = Float.parseFloat(string);
            return true;
        } catch (NumberFormatException e) {
            System.out.println("Input is not valid! Enter a valid number:");
            return false;
        }
    }
    void addNums(){
        Scanner userInput = new Scanner(System.in);
        System.out.println("Enter some Numbers, when done, input a blank line:");
        String input = "test";
        while (input.isEmpty() == false){
            input = userInput.nextLine();
            if (input.isEmpty() == true){
                System.out.println("END of INPUT");
                break;
            }
            else if (isNumerical(input) == false){
            }
            else{
                Float num = Float.parseFloat(input);
                System.out.println("Adding:" + num);
                numsList.add(num);
            }
        }
        System.out.println("ArrayList:" + numsList);
    }

    // attributes
    ArrayList<Float> numsList = new ArrayList<Float>();
}
