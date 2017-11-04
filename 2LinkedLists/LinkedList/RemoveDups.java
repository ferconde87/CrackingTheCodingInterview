import java.io.*;
import java.util.*;

class RemoveDups{
    
    private static void removeDups(Node head){
        if(head == null) return;
        Node node = head;
        Set<Integer> set = new HashSet<Integer>();
        while(node.next != null){
            if(set.contains(node.next.data)){
                node.next = node.next.next;
            }else{
                set.add(node.data);
            }
            node = node.next;
        }
    }
    
    private static void removeDups2(Node head){
        if(head == null) return;
        Node node_i = head;
        Node node_j;
        Node prev = head;
        while(node_i != null){
            node_j = node_i.next;
            while(node_j != null){
                if(node_i.data == node_j.data){
                    prev.next = node_j.next;
                }else{
                    prev = node_j;
                }
                node_j = node_j.next;
            }
            node_i = node_i.next;
        }
    }
    
    public static void main(String[] args){
        Node head = new Node(2);
        head.appendToTail(3);
        head.appendToTail(1);
        head.appendToTail(3);
        head.appendToTail(5);
        head.appendToTail(2);
        head.appendToTail(7);
        head.print();
        removeDups2(head);
        head.print();
    }
    
}