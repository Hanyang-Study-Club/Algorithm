import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;

public class Main {
   public static void main(String[] args) throws NumberFormatException, IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
      
      String[] input = br.readLine().split(" ");
      int n = Integer.parseInt(input[0]);
      int m = Integer.parseInt(input[1]);
      Set<String> hear = new HashSet<>();
      ArrayList<String> hearnsee = new ArrayList<>();
      
      for(int i =0; i < n; i++) {
         hear.add(br.readLine());
      }

      for(int i =0; i < m; i++) {
            String see = br.readLine();
            if(hear.contains(see)) {
               hearnsee.add(see);//hearnsee[j++] = see;
            }
      }

      Collections.sort(hearnsee);
      bw.write(String.valueOf(hearnsee.size())+"\n");
      for(String hns : hearnsee) {
         bw.write(hns + "\n");
      }
   
      br.close();
      bw.flush();
      bw.close();
   }   
}
