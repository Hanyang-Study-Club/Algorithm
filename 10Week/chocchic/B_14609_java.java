package week10;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

//구분구적법
public class B_14609_java {
	public static final double limit = 0.0001;
	public static int K, N, a, b;
	public static int[] ci;
		
	public static double search(double fx) {
		double start = 0;
		double end = (double)(b-a)/N;
		double deltaX = end;
		double mid = 0;
		double temp_fx = 0;
		
		while(start <= end) {
			mid = (end + start) / 2;
			temp_fx = 0;
			for(int i = 0; i < N; i++) {
				for(int j = 0; j <= K; j++) {
					temp_fx += ci[j]*Math.pow(a + i * deltaX + mid, K-j) * deltaX;
				}
			}
			
			if(Math.abs(fx - temp_fx) <= limit) {
				return mid;
			}
			
			if (fx > temp_fx) {
				start = mid;
			}else{
				end = mid;
			}
		}
		
		return -1;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		K = Integer.parseInt(br.readLine());
		ci = new int[K+1];
		
		String[] temp = br.readLine().split(" ");
		for(int i = 0 ; i <= K ; i++){
			ci[i] = Integer.parseInt(temp[i]);
		}
		
		temp = br.readLine().split(" ");
		a = Integer.parseInt(temp[0]);
		b = Integer.parseInt(temp[1]);
		N = Integer.parseInt(temp[2]);
		
		double fx = 0;
		
		for(int k = 0; k <= K; k++) {
			int n = K - k;
			fx +=  ci[k] * Math.pow(b, n+1)/(n+1) - ci[k] * Math.pow(a, n+1) / (n+1); 
		}
		
		bw.write(String.valueOf(search(fx)));
		
		br.close();
        bw.flush();
	    bw.close();
	}
}
