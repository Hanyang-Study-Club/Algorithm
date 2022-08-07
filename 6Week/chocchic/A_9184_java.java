package week6;
// 신나는 함수 실행

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class A_9184_java {
	
	static int[][][] Ws = new int[21][21][21];
	
	public static int w(int a, int b, int c) {
		if(a <= 0 || b <= 0 || c <= 0) {
			return 1;
		}
		
		if(a > 20 || b > 20 || c > 20) {
			return w(20, 20, 20);
		}
		
		if(Ws[a][b][c] != 0) {
			return Ws[a][b][c];
		}
		
		if(a < b && b < c) {
			return Ws[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
		}
				
	    return Ws[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		
		int a, b, c;
		
		while (true) {
			String[] ori = br.readLine().split(" ");
			a = Integer.parseInt(ori[0]);
			b = Integer.parseInt(ori[1]);
			c = Integer.parseInt(ori[2]);
			
			if (a== -1 && b == -1 && c==-1) {
				break;
			}
			
			sb.append("w(" + a + ", " + b + ", " + c + ") = ").append(w(a,b,c)).append('\n');
		}
		
		bw.write(sb.toString());
		br.close();
        bw.flush();
	    bw.close();
	}
	
}
