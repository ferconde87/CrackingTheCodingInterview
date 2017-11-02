import java.util.*;
import java.io.*;

public class RotateMatrix{
    //assumption a is an nxn matrix
    private static void rotateMatrix(int[][] a){
        int n = a.length;
        for(int layer = 0; layer < n/2; layer++){
            int first = layer;
            int last = n - 1 - layer;
            for(int i = first; i < last; i++){
                int offset = i - first;
                int top = a[first][i];
                //left -> top
                a[first][i] = a[last-offset][first];
                //bottom -> left
                a[last-offset][first] = a[last][last - offset];
                //right -> bottom
                a[last][last - offset] = a[i][last];
                //top -> right
                a[i][last] = top; // right <- saved top
            }
        }
    }
    
    //m is a squared matrix
    private static void print(int[][] m){
        int n = m.length;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.print(m[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[][] matrix = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = scan.nextInt();
            }
        }
        scan.close();
        print(matrix);
        System.out.println();
        rotateMatrix(matrix);
        print(matrix);
    }

}
