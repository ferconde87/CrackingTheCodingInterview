import java.io.*;
import java.util.*;

class PalindromePermutation{
    
    //using hashMap
    public static boolean isPalindromePermutation(String s){
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            Integer count = map.get(c);
            if(count == null){
                map.put(c, 1);
            }else{
                map.put(c, count+1);
            } 
        }
        boolean oneOddAccepted = ((s.length() % 2) == 1);
        for(Integer x : map.values()){
            if(x % 2 == 1){
                if(oneOddAccepted){
                    oneOddAccepted = false;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    
    //using hashSet
    public static boolean isPalindromePermutation2(String s){
        Set<Character> map = new HashSet<Character>();
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(map.contains(c)){
                map.remove(c);
            }else{
                map.add(c);
            } 
        }
        if(s.length() % 2 == 0) return map.isEmpty();
        else return (map.size() == 1);
    }
    
    //using vector of ints
    //assuming string s is a ascii string
    public static boolean isPalindromePermutation3(String s){
        int[] counter = new int[128];
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            counter[c]++;
        }
        boolean oneOddAccepted = ((s.length() % 2) == 1);
        for(int i = 0; i < 128; i++){
            if(counter[i] % 2 == 1){
                if(oneOddAccepted){
                    oneOddAccepted = false;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    
    
    //using vector of booleans
    //assuming string s is a ascii string
    public static boolean isPalindromePermutation4(String s){
        boolean[] odds = new boolean[128];
        for(int i = 0; i < s.length(); i++){
            int index = (int)s.charAt(i);
            odds[index] = !odds[index];
        }
        boolean oneOddAccepted = ((s.length() % 2) == 1);
        for(int i = 0; i < 128; i++){
            if(odds[i]){
                if(oneOddAccepted){
                    oneOddAccepted = false;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while(scan.hasNext()){
            String s = scan.next();
            boolean result = isPalindromePermutation(s);
            System.out.println(s + " is" + (result ? " " : " not ") + "a Palindrome.");
            result = isPalindromePermutation2(s);
            System.out.println(s + " is" + (result ? " " : " not ") + "a Palindrome.");
            result = isPalindromePermutation3(s);
            System.out.println(s + " is" + (result ? " " : " not ") + "a Palindrome.");
            result = isPalindromePermutation4(s);
            System.out.println(s + " is" + (result ? " " : " not ") + "a Palindrome.");
        }
    
    }
    
}