package week9;
// 프렉탈 평면

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class C_1030_java {
	public static int[] nums;
	
	public static int frac(int len, int x, int y) {
		if(len == 1) {
			return 0;
		}
		
		int border = len/nums[1];
		if (x >= border * (nums[1] - nums[2]) / 2 && x < border * (nums[1] + nums[2]) / 2  
			&& y >= border * (nums[1] - nums[2]) / 2 && y < border * (nums[1] + nums[2]) / 2) { // x와 y 좌표가 주어진 전체 배열의 k*k에 걸리는 경우만 검은색
			return 1;
		}
		
		return frac(border, x % border, y % border); // 현재 크기의 배열에서 k*k배열에 걸리지 않았으므로 재귀
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		nums = new int[7]; // s, N, K, R1, R2, C1, C2
		int i = 0;
		for(String line : br.readLine().split(" ")) {
			nums[i++] = Integer.parseInt(line);
		};
		
		int len = 1;
		for(;nums[0] >0;nums[0]--) {
			len*=nums[1];
		}
		
		StringBuilder sb = new StringBuilder();
		
		for(i=nums[3];i <= nums[4]; i++) {
			for(int j = nums[5]; j <= nums[6]; j++) {
				sb.append(frac(len, i, j));
			}
			sb.append("\n");
		}
		
		bw.write(sb.toString());
		
		br.close();
		bw.flush();
		bw.close();
	}
}
