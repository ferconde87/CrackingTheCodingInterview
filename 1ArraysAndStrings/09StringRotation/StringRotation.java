import java.io.*;
import java.util.*;

class StringRotation{
    
    private static boolean isStringRotation(String s, String t){
        if(s.length() != t.length()) { return false; }
        int i = 0;
        int j;
        int splitIndex = 0;
        for(j = 0; j < t.length(); j++){
            if(s.charAt(i) == t.charAt(j)){
                i++;
            }else{
                i = 0;
                splitIndex = j;
            }
        }
        //when we reach to the end we know that in order to be a rotation the remaining part of s have to be on the first part of t
        for(int k = 0;  k <= splitIndex; k++){
            if(s.charAt(i+k)!=t.charAt(k)){
                return false;
            } 
        }
        return true;
    }
    
    private static boolean isStringRotation2(String s, String t){
        if(s.length() != t.length()) return false;
        return isSubstring(s + s, t);
    }
    
    //is t substring of s?
    private static boolean isSubstring(String s, String t){
        int i = 0;
        int j = 0;
        while(i < s.length() && j < t.length()){
            if(s.charAt(i) == t.charAt(j)){
                j++;
            }else{
                j = 0;
            }
            i++;
        }
        return j == t.length();
    }
    
    
    
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        while(scan.hasNext()){
            String s = scan.next();
            String t = scan.next();
            boolean result = isStringRotation(s, t);
            System.out.print(result + " | ");
            result = isStringRotation2(s, t);
            System.out.println(result);
        }
        scan.close();
    }

}