import java.io.*;
import java.util.*;

class IsUnique{
    public static boolean isUnique(String s){
        Set<Character> set = new HashSet<Character>();
        for(Character c : s.toCharArray()){
            if(set.contains(c)) return false;
            set.add(c);
        }
        return true;
    }
    
    //assuming the string is an ASCII string
    public static boolean isUnique2(String s){
        if(s.length() > 128) return false;
        
        boolean[] char_set = new boolean[128];
        for(int i = 0; i < s.length(); i++){
            int val = s.charAt(i);
            if(char_set[val]){
                return false;
            }
            char_set[val] = true;
        }
        return true;
    }
    
    //assuming the string uses only lowercase letters
    //we can use only a int variable of memory through bit manipulation
    public static boolean isUnique3(String s){
        int checker = 0;
        for(int i = 0; i < s.length(); i++){
            int val = s.charAt(i) - 'a';
            if((checker & (1 << val)) > 0){
                return false;
            }
            checker |= (1 << val);
        }
        return true;
    }
    
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while(scan.hasNext()){
            String s = scan.next();
            boolean result = isUnique(s);
            boolean result2 = isUnique2(s);
            boolean result3 = isUnique3(s);
            System.out.print("isUnique: " + result + "\t | ");
            System.out.print("isUnique2: " + result2 + "\t | ");
            System.out.print("isUnique3: " + result3 + "\n");
            
        }
        scan.close();
    }
}

