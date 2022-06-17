package program1;
import java.util.ArrayList;
import java.util.Collections;
import java.lang.Math; // only using sqrt() function, Prof. said this is fine

public class Analyzer {
    // methods
    void setData(ArrayList<Float> input){
        data = input;
        Collections.sort(data);
        System.out.println("SortedData:" + data);
    }
    void analyze(){
        setSumFun();
        setMedianFun();
        setMeanFun();
        setMinFun();
        setMaxFun();
        setSDFun();
        printResults();
    }
    void setSumFun(){
        for (Float it : data){
            sum+=it;
        }
    }
    void setMedianFun(){
        if (data.size() % 2 == 0){
            int position = data.size()/2;
            float mid = (data.get(position) - data.get(position-1))/2;
            median = data.get(position-1) + mid;
        }
        else{
            int position = (data.size()/2);
            median = data.get(position);
        }
    }
    void setMeanFun(){mean = sum/data.size();}
    void setMinFun(){min = data.get(0);}
    void setMaxFun(){max = data.get(data.size()-1);}
    void setSDFun(){
        double variance = 0;
        for (double it : data){
            double localSum = (mean - it);
            variance+=(localSum * localSum);
        }
        variance/=data.size();
        sd = Math.sqrt(variance);
    }
    void printResults(){
        System.out.println("Min:" + min);
        System.out.println("Max" + max);
        System.out.println("Sum:" + sum);
        System.out.println("Median:" + median);
        System.out.println("Mean:" + mean);
        System.out.println("Standard Deviation:" + sd);
    }

    // attributes
    ArrayList<Float> data = new ArrayList<>();
    float sum;
    float median;
    float mean;
    double sd;
    float min;
    float max;
}
