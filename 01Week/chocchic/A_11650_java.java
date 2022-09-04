import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
   public static void main(String[] args) throws NumberFormatException, IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      
      int n = Integer.parseInt(br.readLine());
      int[][] arr = new int[n][2];
      
      for(int i = 0 ; i < n ; i++) {
         String[] ori = br.readLine().split(" ");
         
         arr[i][0] = Integer.parseInt(ori[0]);
         arr[i][1] = Integer.parseInt(ori[1]);
      }
      
      quickSort(arr, 0, n - 1);

      for(int i = 0 ; i < n ; i++) {
         bw.write(String.valueOf(arr[i][0]) + " " + String.valueOf(arr[i][1]) + "\n");
      }
   
      br.close();
      bw.flush();
      bw.close();
   }
   
   static void swap(int[][] a, int l, int r) {
      int temp = a[l][0];
      a[l][0] = a[r][0];
      a[r][0] = temp;
      
      temp = a[l][1];
      a[l][1] = a[r][1];
      a[r][1] = temp;
   }


   static void quickSort(int[][] arr, int left, int right) {
      int idx_l = left;
      int idx_r = right;
      int pivot = (int)((left + right)/2);
      int pivot_x = arr[pivot][0];
      int pivot_y = arr[pivot][1];
      
      do{
         while (arr[idx_l][0] < pivot_x || (arr[idx_l][0] == pivot_x && arr[idx_l][1] < pivot_y)) {
            idx_l++;
         }
         while (arr[idx_r][0] > pivot_x || (arr[idx_r][0] == pivot_x && arr[idx_r][1] > pivot_y)) {
            idx_r--;
         }
         if (idx_l <= idx_r) {
            swap(arr, idx_l, idx_r);
            idx_l++;
            idx_r--;
         }
      }while(idx_l <= idx_r);

      if (left < idx_r) quickSort(arr, left, idx_r); 
      if (idx_l < right) quickSort(arr, idx_l, right);
   }
   
}
