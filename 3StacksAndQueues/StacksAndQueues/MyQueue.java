import java.io.*;
import java.util.*;

public class MyQueue<T> {
    private static class QueueNode<T>{
        private T data;
        private QueueNode<T> next;
        
        public QueueNode(T data){
            this.data = data;
        }
    }
    
    private QueueNode<T> first;
    private QueueNode<T> last;
    
    public T remove(){
        if(first == null) throw new NoSuchElementException();
        T data = first.data;
        first = first.next;
        if(first == null) last = null;
        return data;
    }
    
    public void add(T item){
        QueueNode<T> node = new QueueNode<T>(item); 
        if(first == null){
            first = node;
        }else{
            last.next = node;
        }
        last = node;
    }
    
    public T peek(){
        if(first == null) throw new NoSuchElementException();
        return first.data;
    }
    
    public boolean isEmpty(){
        return first == null;
    }
    
    public static void main(String[] args){
        MyQueue<Integer> queue = new MyQueue<Integer>();
        queue.add(1);
        queue.add(2);
        queue.remove();
        queue.add(3);
        queue.add(4);
        queue.remove();
        assert queue.peek() == 3;
        queue.add(5);
        assert queue.peek() == 3;
        queue.remove();
        queue.remove();
        assert queue.peek() == 5;
        assert !queue.isEmpty();
        queue.remove();
        assert queue.isEmpty();
    }
    
}