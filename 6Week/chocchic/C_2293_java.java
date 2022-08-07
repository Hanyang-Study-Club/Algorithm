package week6;
// 동전 1

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class C_2293_java {
	static int n, k;
	static int[] coin;
	static int[] answer;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
	      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	      
	      String[] input = br.readLine().split(" ");
	      n = Integer.parseInt(input[0]);
	      k = Integer.parseInt(input[1]);
	      
	      coin = new int[n];
	      answer = new int[k+1];
	      answer[0] = 1;
	      
	      for(int i = 0 ; i < n; i++) {
	    	  coin[i] = Integer.parseInt(br.readLine());
	      }
	      br.close();
	      
	      for(int i = 0; i < n; i++) {
	    	  for(int j = coin[i]; j < k+1; j++){
	    		  answer[j] = answer[j] + answer[j-coin[i]]; 
	    	  }
	      }
	      
	      bw.write(String.valueOf(answer[k]));
	      
	      bw.flush();
	      bw.close();
	      
	}
}
