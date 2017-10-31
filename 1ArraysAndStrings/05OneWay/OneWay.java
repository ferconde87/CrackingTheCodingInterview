import java.io.*;
import java.util.*;

class OneWay{
    //assuming string is a standard ascii string
    public static boolean oneWay(String s, String t){
        int diff = Math.abs((s.length() - t.length()));
        if(diff > 1) return false;
//        if(diff == 0){
//            return oneUpdate(s, t);
//        }else{
//            return oneAddedOrRemoved(s, t);
//        }
        return oneUpdate(s, t);
    }
    
    
    private static boolean oneUpdate(String s, String t){
        int[] occurrences = new int[128];
        for(int i = 0; i < s.length(); i++){
            occurrences[(int)s.charAt(i)]++;
        }
        boolean oneUpdateRemaining = true;
        for(int i = 0; i < t.length(); i++){
            int index = (int)t.charAt(i);
            if(occurrences[index] <= 0){
                if(oneUpdateRemaining){
                    oneUpdateRemaining = false;
                }else{
                    return false;
                }
            }
            occurrences[index]--;
        }
        return true;
    }
    
    private static boolean oneAddedOrRemoved(String s, String t){
        return true;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while(scan.hasNext()){
            String s = scan.next();
            String t = scan.next();
            boolean result = oneWay(s,t);
            System.out.println(s + ", " + t + " ==> " + result); 
        }
        scan.close();
    }
}