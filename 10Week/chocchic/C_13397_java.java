package week10;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

// 구간 나누기
public class C_13397_java {
	public static int[] arr;
	public static int N, M;
	
	public static boolean est(int mid) {
		int m=1, min_value = Integer.MAX_VALUE, max_value = Integer.MIN_VALUE;
		
		for(int i = 0; i < N; i++) {
			min_value = Math.min(min_value, arr[i]);
			max_value = Math.max(max_value, arr[i]);
			
			if(max_value - min_value > mid) {
				min_value = arr[i];
				max_value = arr[i];
				m++;
			}
		}
		
		return m <= M;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String[] temp = br.readLine().split(" ");
		N = Integer.parseInt(temp[0]);
		M = Integer.parseInt(temp[1]);
		
		temp = br.readLine().split(" ");
		arr = new int[N];
		
		int start = 0;
		int end = Integer.MIN_VALUE;
		for(int i = 0 ; i < N ; i++){
			arr[i] = Integer.parseInt(temp[i]);
			end = Math.max(end, arr[i]);
		}
		
		while(start < end) {
			int mid = (start + end) / 2;
			if(est(mid)) {
				end = mid;
			}else {
				start = mid + 1;
			}
		}
		
		bw.write(String.valueOf(end));
		
		br.close();
        bw.flush();
	    bw.close();
	}
}
