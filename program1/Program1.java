package program1;

public class Program1 {
    public static void main(String[] args){
        System.out.println("PROGRAM 1");
        Reader reader = new Reader();
        Analyzer analyzer = new Analyzer();
        analyzer.setData(reader.getData());
        analyzer.analyze();
    }
}
