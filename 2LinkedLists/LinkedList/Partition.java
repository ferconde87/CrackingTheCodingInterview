import java.io.*;
import java.util.*;

class Partition{
    
    /* Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
       the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
       that node.
    */
    private static Node partition(Node head, int d){
        if(head == null) return null;
        Node first = null;
        Node smaller = null;
        Node firstGreaterOrEq = null;
        Node greaterOrEq =  null;
        Node node = head;
        
        while(node != null){
            if(node.data < d){
                if(first == null){
                    first = node;
                    smaller = first;
                }else{
                    smaller.next = node;
                    smaller = smaller.next;
                }
            }else{
                if(firstGreaterOrEq == null){
                    firstGreaterOrEq  = node;
                    greaterOrEq = firstGreaterOrEq;
                }else{
                    greaterOrEq.next = node;
                    greaterOrEq = greaterOrEq.next;
                }
            }
            node = node.next;
        }
        greaterOrEq.next = null;
        smaller.next = firstGreaterOrEq;
        return first;
    }
    ////      3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1      (5)
    //                           node
    //      fst
    //      sm
    //          fsGoE
    //                          goe
    //
    
    public static void main(String[] args){
        Node head = new Node(3);
        head.appendToTail(5);
        head.appendToTail(8);
        head.appendToTail(5);
        head.appendToTail(10);
        head.appendToTail(2);
        head.appendToTail(1);
        head.print();
        Node newOrder = partition(head, 5);
        newOrder.print();
    }
    
}