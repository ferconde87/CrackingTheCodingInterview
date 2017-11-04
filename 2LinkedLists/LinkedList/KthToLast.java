import java.io.*;
import java.util.*;

class KthToLast{
    
    private static Node kthToLast(Node head, int k){
        int n = head.length();
        if(k > n) return null;
        int index = n - k - 1;
        Node node = head;
        for(int i = 0; i < index; i++){
            node = node.next;
        }
        return node;    
    }
    
    public static void main(String[] args){
        Node head = new Node(2);
        head.appendToTail(5);
        head.appendToTail(1);
        head.appendToTail(7);
        head.appendToTail(8);
        head.print();
        Node result = kthToLast(head, 2);
        System.out.println("2 to last is " + result.data);
        result = kthToLast(head, 0);
        System.out.println("0 to last is " + result.data);
        result = kthToLast(head, 1);
        System.out.println("1 to last is " + result.data);
        result = kthToLast(head, 4);
        System.out.println("4 to last is " + result.data);
    }
    
}