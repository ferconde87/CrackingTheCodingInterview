import java.io.*;
import java.util.*;

class OneWay{
    //assuming string is a standard ascii string
    public static boolean oneWay(String s, String t){
        int diff = Math.abs((s.length() - t.length()));
        if(diff > 1) return false;
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
    
    private static boolean oneEditAway(String first, String second){
        int diff = Math.abs(first.length() - second.length());
        if(diff > 1) return false;
        String s1, s2;
        if(first.length() < second.length()){
            s1 = first;
            s2 = second;
        }else{
            s2 = first;
            s1 = second;
        }
        int i = 0;
        int j = 0;
        boolean foundDifference = false;
        while(i < s1.length() && j < s2.length()){
            if(s1.charAt(i) != s2.charAt(j)){
                if(foundDifference) return false;
                foundDifference = true;
                if(s1.length() == s2.length()){
                    i++;
                }
            }else{
                i++;
            }
            j++;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while(scan.hasNext()){
            String s = scan.next();
            String t = scan.next();
            boolean result = oneWay(s,t);
            System.out.println(s + ", " + t + " ==> " + result);
            result = oneEditAway(s,t);
            System.out.println(s + ", " + t + " ==> " + result); 
        }
        scan.close();
    }
}