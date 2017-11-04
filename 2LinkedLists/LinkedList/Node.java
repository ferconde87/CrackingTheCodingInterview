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
    
    Node deleteNode(Node head, int d){
        Node node = head;
        if(node == null) return null;
        
        if(node.data == d){
            return node.next;
        }
        
        while(node.next != null){
            if(node.next.data == d){
                node.next = node.next.next;
                break;
            }
            node = node.next;
        }
        return head;
    }
    
    public int length(){
        int length = 0;
        Node node = this;
        while(node != null){
            length++;
            node = node.next;
        }
        return length;
    }
    
    public Node getNode(int d){
        Node node = this;
        while(node != null){
            if(node.data == d) return node;
            node = node.next;
        }
        return null;
    }
    
    void print(){
        Node node = this;
        while(node != null){
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }
    
    public static void main(String[] args){
        Node head = new Node(1);
        head.appendToTail(2);
        head.appendToTail(3);
        head.print();
        head = head.deleteNode(head, 2);
        head.print();
    }
}