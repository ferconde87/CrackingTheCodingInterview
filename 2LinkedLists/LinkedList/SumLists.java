import java.io.*;
import java.util.*;

class SumLists{
    
    //1's digit is the head of the node
    private static Node sumLists(Node n1, Node n2){
        if(n1 == null) return n2;
        if(n2 == null) return n1;
        int carry = 0;
        Node result = null;
        Node cur = null;
        while(n1 != null && n2 != null){
            int sum = n1.data + n2.data + carry;
            carry = 0;
            if(sum >= 10){
                carry = 1;
                sum -= 10;
            }
            if(result == null){
                result = new Node(sum);
                cur = result;
            }else{
                cur.next = new Node(sum);
                cur = cur.next;
            }
            n1 = n1.next;
            n2 = n2.next;
        }
        return result;
    }
    
    private static Node parcialClone(Node node, Node cur, int n){
        if(node == null) return null;
        Node result = new Node(node.data);
        while(n > 0 && node.next != null){
            node = node.next;
            cur.next = new Node(node.data);
            cur = cur.next;
            n--;
        }
        return result;
    }
    
    //suppose the digits are sorted in foward order
    private static Node sumLists2(Node n1, Node n2){
        int n = n1.length();
        int m = n2.length();
        Node cur = null;
        Node result = null;
        while(n > m){
            int sum = n1.data;
            if(result == null){
                result = new Node(sum);
                cur = result;
            }else{
                cur.next = new Node(sum);
                cur = cur.next;
            }
            n1 = n1.next;
            n--;
        }
        while(m > n){
            int sum = n2.data;
            if(result == null){
                result = new Node(sum);
                cur = result;
            }else{
                cur.next = new Node(sum);
                cur = cur.next;
            }
            n2 = n2.next;
            m--;
        }
        while(n1 != null){
            int sum = n1.data + n2.data;
            System.out.println("sum = " + sum);
            if(result == null){
                if(sum >= 10){
                    result = new Node(1);
                    sum-= 10;
                    cur = result;
                    cur.next = new Node(sum);
                }else{
                    result = new Node(sum);
                    cur = result;
                }
            }else{
                if(sum >= 10){
                    //System.out.println("prev = " + prev.data);
                    cur.data += 1;
                    sum -= 10;
                }
                cur.next = new Node(sum);
                //prev = cur;
                cur = cur.next;
            }
            n1 = n1.next;
            n2 = n2.next;
        }
        return result;
    }
    
    //        6 ->     1      -> 7
    //                              2 ->     9       -> 5
    //result  8 ->
    //              cur
    //prev    8 ->
    public static void main(String[] args){
        Node n1 = new Node(7);
        n1.appendToTail(1);
        n1.appendToTail(6);
        Node n2 = new Node(5);
        n2.appendToTail(9);
        n2.appendToTail(2);
        Node result = sumLists(n1,n2);
        n1.print();
        System.out.println("+");
        n2.print();
        System.out.println("______");
        result.print();
        
        //////
        Node n3 = new Node(6);
        n3.appendToTail(6);
        n3.appendToTail(1);
        n3.appendToTail(7);
        Node n4 = new Node(2);
        n4.appendToTail(9);
        n4.appendToTail(5);
        Node result2 = sumLists2(n3,n4);
        n3.print();
        System.out.println("+");
        n4.print();
        System.out.println("______");
        result2.print();
    }
    
}