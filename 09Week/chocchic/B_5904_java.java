package week9;
// Moo 게임

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class B_5904_java {
	public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	public static int n;
	public static final String s0 = "moo";
	
	public static void Moo(int k, int kthlen) throws IOException {
		if(n < 4) {
			bw.write(String.valueOf(s0.charAt(n-1)));
			return;
		}
		int k1thlen = kthlen * 2 + k + 3;
		if(k1thlen < n) { // 다음 수열로 넘어가야 함.
			Moo(k+1, k1thlen);
		}else {
			if(kthlen < n && n <= kthlen+k+3) { // 이번 함수에서 탐색 한 곳(이전 수열 이후 mo....o 부분)에 k 가 존재
				if(n - kthlen == 1) { // 이번 함수에서 탐색 한 곳의 mo...o에서 m의 위치를 구하고자 함.
					bw.write("m");
					return;
				}else {
					bw.write("o");
					return;
				}
			}else { // mo...o부분 말고 뒤에 있을 때, 찾고자 하는 index에서 mo...oo까지 제외한 값을 넣어서 재귀.
				n-=kthlen+k+3;
				Moo(1, 3);
			}
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		
		n = Integer.parseInt(br.readLine());
		
		Moo(1,3);
		
		br.close();
        bw.flush();
	    bw.close();
	}
}
