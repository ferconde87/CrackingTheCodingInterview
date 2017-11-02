import java.io.*;
import java.util.*;

public class ZeroMatrix{

    private static void zeroMatrix(int[][] matrix){
        int n = matrix.length;
        if(n == 0) return;
        int m = matrix[0].length;
        List<Integer> rows = new ArrayList<Integer>();
        List<Integer> cols = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j]==0){
                    rows.add(i);
                    cols.add(j);
                }
            }
        }
        for(int i : rows){
            for(int j = 0; j < m; j++){
                matrix[i][j] = 0;
            }
        }
        for(int j : cols){
            for(int i = 0; i < n; i++){
                matrix[i][j] = 0;
            }
        }
    }
    
    
//using an espacial 
    private static void zeroMatrix2(int[][] matrix){
        int n = matrix.length;
        if(n == 0) return;
        int m = matrix[0].length;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n; i++){
            if(matrix[i][0]==0){
                for(int j = 1; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < m; j++){
            if(matrix[0][j]==0){
                for(int i = 1; i < n; i++){
                    matrix[i][j] = 0; 
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i = 1; i < n; i++){
                matrix[i][0] = 0;
            }
            for(int j = 1; j < m; j++){
                matrix[0][j] = 0;
            } 
        }
    }
    
    private static void print(int[][] matrix){
        int n = matrix.length;
        if(n == 0) return;
        int m = matrix[0].length;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                System.out.print(matrix[i][j]);
            }
            System.out.println();
        }        
    }
    
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
        int[][] matrix = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                matrix[i][j] = scan.nextInt();
            }
        }
        scan.close();
        print(matrix);
        System.out.println();
        zeroMatrix(matrix);
        print(matrix);
    }
    
}