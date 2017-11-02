import java.util.*;
import java.io.*;

public class StringCompression{
    private static String stringCompression(String s){
        if(s.length() == 0){
            return s;
        }
        StringBuilder sb = new StringBuilder();
        int i;
        int count = 0;
        char c = s.charAt(0);
        char next = s.charAt(0);
        for(i = 0; i < s.length()-1; i++){
            count++;
            c = s.charAt(i);
            next = s.charAt(i+1);
            if(c != next){
                sb.append(c);
                sb.append(count);
                count = 0;
            }
        } 
        sb.append(next);
        sb.append(count+1);
        if(sb.length() < s.length()){
            return sb.toString();
        }else{
            return s;
        }
    }
     
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while(scan.hasNext()){
            String s = scan.next();
            String result = stringCompression(s);
            System.out.println("input: " + s + " | result = " + result);
        }
        scan.close();
    }    
}
