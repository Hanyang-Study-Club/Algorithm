import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class  {
   public static void main(String[] args) throws NumberFormatException, IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      String[] input = br.readLine().split(" ");

      int n = Integer.parseInt(input[0]);
      int k = Integer.parseInt(input[1]);
      int i = 0;
      int[] arr = new int[n];
      for (String s : br.readLine().split(" ")) {
         arr[i++]=Integer.parseInt(s);
      }

      quickSort(arr, 0, n - 1);

      bw.write(String.valueOf(arr[k-1]));
   
      br.close();
      bw.flush();
      bw.close();
   }
   
   static void swap(int[] a, int l, int r) {
      int temp = a[l];
      a[l] = a[r];
      a[r] = temp;
   }


   static void quickSort(int[] arr, int left, int right) {
      int idx_l = left;
      int idx_r = right;
      int pivot = arr[(int)((left + right)/2)];
      
      do{
         while (arr[idx_l] < pivot) {
            idx_l++;
         }
         while (arr[idx_r] > pivot) {
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
