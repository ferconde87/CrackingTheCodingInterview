import java.io.*;
import java.util.*;

class CheckPermutation{
    
    //Make a map with the occurrences of the characteres in the string 's'
    private static Map<Character, Integer> makeMap(String s){
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        for(Character c : s.toCharArray()){
            Integer num = map.get(c); 
            if(num != null){
                map.put(c, num+1);
            }else{
                map.put(c, 1);
            }
        }
        return map;
    }
    
    /* Given two strings, write a method to decide if one is a permutation of the other.*/
    //Time complexity: O(n), where n is the length of the string s
    //Space complexity: O(n)
    public static boolean checkPermutation(String s, String t){
        if(s.length() != t.length()) return false;
        Map<Character, Integer> occurrencesS = makeMap(s);
        Map<Character, Integer> occurrencesT = makeMap(t);
        for(Character c : s.toCharArray()){
            if(occurrencesS.get(c) != occurrencesT.get(c)){
                return false;
            }
        }
        return true;
    }
    
    //Similar to the other above but using only one map of occurrences
    public static boolean checkPermutationBis(String s, String t){
        if(s.length() != t.length()) return false;
        Map<Character, Integer> occurrences = makeMap(s);
        for(Character c : t.toCharArray()){
            Integer amount = occurrences.get(c);
            if(amount == null || amount == 0) return false;
            occurrences.put(c, amount-1);
        }
        return true;
    }
    
    
    //Another solution sorting the input string and check for occurrences
    public static boolean checkPermutation2(String s, String t){
        if(s.length() != t.length()) return false;
        return sort(s).equals(sort(t));        
    }
    
    private static String sort(String s){
        char[] content = s.toCharArray();
        Arrays.sort(content);
        return new String(content);
    }
    
    //Similar like the first one but this time using an array instead of a hashMap
    //Assuming that the strings are standard ASCII string
    public static boolean checkPermutation3(String s, String t){
        if(s.length() != t.length()) return false;
        int[] counterLetters = new int[128];
        char[] s_array = s.toCharArray();
        for(char c : s_array){
            counterLetters[c]++;
        }
        for(int i = 0; i < t.length(); i++){
            int index = (int)t.charAt(i);
            counterLetters[index]--;
            if(counterLetters[index] < 0){
                return false;
            }
        }
        return true;   
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while(scan.hasNext()){
            String s = scan.next();
            String t = scan.next();
            boolean result = checkPermutation(s, t);
            System.out.print("check:" + result +"\t | ");
            result = checkPermutationBis(s, t);
            System.out.print("checkBis:" + result +"\t | ");
            result = checkPermutation2(s, t);
            System.out.print("check2:" + result +"\t | ");
            result = checkPermutation3(s, t);
            System.out.println("check3:" + result);
        }
        scan.close();
    }
}

