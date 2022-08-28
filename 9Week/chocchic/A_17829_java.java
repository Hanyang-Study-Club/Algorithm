package week9;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

// 풀링
public class A_17829_java {
	public static int[] arr;
	
	public static void pooling(int n) {
		if(n!=1) {
			int next= n/2, k = 0;
			int temp[] = new int[next*next];
			for(int i=0; i < n; i+=2) {
				for(int j=0; j < n; j+=2) {	
					int[] ttemp = {arr[i*n + j], arr[i*n + j + 1], arr[(i+1)*n+j], arr[(i+1)*n+j+1]};
					Arrays.sort(ttemp);
					temp[k++] = ttemp[2];
				}
			}
			arr = temp;
			pooling(next);
		}
		
		return; 
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int n = Integer.parseInt(br.readLine());
		arr = new int[n*n];
		
		for(int i = 0 ; i < n ; i++){
			String temp[] = br.readLine().split(" ");
			for(int j = 0; j < n; j++) {
				arr[i*n + j] = Integer.parseInt(temp[j]);
			}	
		}
		
		pooling(n);
		
		bw.write(String.valueOf(arr[0]));
		br.close();
        bw.flush();
	    bw.close();
	}
}
