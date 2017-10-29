import java.io.*;
import java.util.*;

class SortedMatrixSearch{
    public static boolean binarySearchInMatrix(int[][] matrix, int target){
        int n = matrix.length;
        if (n==0) return false;
        int m = matrix[0].length;
        return binarySearchInMatrix(matrix, 0, n-1, 0, m-1, target);
    }
    
    private static boolean binarySearchInMatrix(int[][] matrix, int startRow, int endRow, int startCol, int endCol, int target){
        if(startRow > endRow || startCol > endCol) return false;
        int midRow = (endRow + startRow) / 2;
        int midCol = (endCol + startCol) / 2;
        int curValue = matrix[midRow][midCol];
        if(target == curValue) return true;
        if(target < curValue){
            if(binarySearchInMatrix(matrix, startRow, midRow-1, startCol, endCol, target)) return true;
            return binarySearchInMatrix(matrix, startRow, endRow, startCol, midCol-1, target);
        }else{
            if(binarySearchInMatrix(matrix, midRow+1, endRow, startCol, endCol, target)) return true;
            return binarySearchInMatrix(matrix, startRow, endRow, midCol+1, endCol, target);
        }
    }
    
    //other solution
    boolean findElement(int[][] matrix, int elem){
        int row = 0;
        int col = matrix[0].length - 1;
        while(row < matrix.length && col >= 0){
            if(matrix[row][col] == elem){
                return true;
            }else if(elem < matrix[row][col]){
                col--;
            }else{
                row++;
            }
        }
        return false;
    }
    
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int target = scan.nextInt();
        int n = scan.nextInt();
        int m = scan.nextInt();
        int[][] matrix = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                matrix[i][j] = scan.nextInt();
            }
        }
        scan.close();
        boolean result = binarySearchInMatrix(matrix, target);
        System.out.println(result);
    }
}

