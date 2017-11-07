import java.io.*;
import java.util.*;

public class Tree<T>{
    
    Node<T> root;

    public static class Node<T>{
        private T data;
        private Node<T> left;
        private Node<T> right;
        
        public Node(T d){
            data = d;
            left = null;
            right = null;
        }
        
        public void inOrder(){
            if(left != null) left.inOrder();
            System.out.print(data + " ");
            if(right != null) right.inOrder(); 
        }
        
        public void preOrder(){
            System.out.print(data + " ");
            if(left != null) left.preOrder();
            if(right != null) right.preOrder(); 
        }
        
        public void postOrder(){
            if(left != null) left.postOrder();
            if(right != null) right.postOrder(); 
            System.out.print(data + " ");
        }
        
        public static void main(String[] args){
            //                 4
            //              /     \
            //             2       6
            //            / \     / \
            //           1   3   5   7
            Node<Integer> node = new Node<Integer>(4);
            node.left = new Node<Integer>(2);
            node.left.left = new Node<Integer>(1);
            node.left.right = new Node<Integer>(3);
            node.right = new Node<Integer>(6);
            node.right.left = new Node<Integer>(5);
            node.right.right = new Node<Integer>(7);
            node.inOrder();System.out.println();
            node.preOrder();System.out.println();
            node.postOrder();System.out.println();
            
        }
    }
    
    public static void main(String[] args){
        Node.main(args);
    }
}