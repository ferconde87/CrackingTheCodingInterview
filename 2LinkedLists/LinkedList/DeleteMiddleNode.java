import java.io.*;
import java.util.*;

class DeleteMiddleNode{
    
    /* Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
       the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
       that node.
    */
    private static void deleteMiddleNode(Node nodeToDelete){
        if(nodeToDelete == null) return;
        nodeToDelete.data = nodeToDelete.next.data;
        nodeToDelete.next = nodeToDelete.next.next;
    }
    
    
    private static void deleteMiddleNodeGeneral(Node head){
        int n = head.length();
        int mid = n/2;
        Node node = head;
        int i = 0;
        while(i < mid && node.next != null){
            node = node.next;
        }
        node.next = node.next.next;
    }
    
    public static void main(String[] args){
        Node head = new Node(1);
        head.appendToTail(5);
        head.appendToTail(9);
        head.appendToTail(12);
        head.print();
        Node node9 = head.getNode(9);
        deleteMiddleNode(node9);
        head.print();
    }
    
}