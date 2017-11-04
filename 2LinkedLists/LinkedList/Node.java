import java.io.*;
import java.util.*;

class Node{
    Node next = null;
    int data;
    
    public Node(int d){
        data = d;
    }
    
    void appendToTail(int d){
        Node end = new Node(d);
        Node node = this;
        while(node.next != null){
            node = node.next;
        }
        node.next = end;
    }
    
    public static void main(String[] args){
        
    }
}