import java.io.*;
import java.util.*;

public class MyStack<T> {
    private static class StackNode<T>{
        private T data;
        private StackNode<T> next;
        
        public StackNode(T data){
            this.data = data;
        }
    }
    
    private StackNode<T> top;
    
    public T pop(){
        if(top == null) throw new EmptyStackException();
        T item = top.data;
        top = top.next;
        return item;
    }
    
    public void push(T item){
        StackNode<T> t = new StackNode<T>(item);
        t.next = top;
        top = t;
    }
    
    public T peek(){
        if(top == null) throw new EmptyStackException();
        return top.data;
    }
    
    public boolean isEmpty(){
        return top == null;
    }
    
    public static void main(String[] args){
        MyStack<Integer> stack = new MyStack<Integer>();
        stack.push(1);
        stack.push(2);
        stack.pop();
        stack.push(3);
        stack.push(4);
        stack.pop();
        assert stack.peek() == 3;
        stack.push(5);
        assert stack.peek() == 5;
        stack.pop();
        stack.pop();
        assert stack.peek() == 1;
        assert !stack.isEmpty();
        stack.pop();
        assert stack.isEmpty();
    }
    
}