package week6;
// 행렬 곱셈 순서

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class B_11049_java {
	static int N;
	static int[] arr;
	static int[][] dp; //i번째와 j번째에서 필요한 곱셈 연산 수 최솟값 저장
	static final int MAX = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  
		N = Integer.parseInt(br.readLine());
		arr = new int[N+1];
		dp = new int[N][N];
		
		
		for(int i = 0; i < N; i++) {
			String[] ori = br.readLine().split(" ");
			arr[i]= Integer.parseInt(ori[0]);
			arr[i+1]= Integer.parseInt(ori[1]);
		}
		
		br.close();
		
		for(int i = 2; i < N + 1; i++) { // 구간 간격  2~ N
			for(int j = 0; j < N + 1 -i ; j++) { // 구간 시작점 j (0 ~ N-i))
				dp[j][j+i-1] = MAX; // 최대값으로 설정하여 min을 해도 값이 걸리도록 해줌 
				for(int k = j; k < j+i-1; k++) { // 중간 지점 k (j ~ j +i -1))
					//int temp = );
					dp[j][j+i-1] = Math.min(dp[j][j+i-1], dp[j][k] + dp[k+1][j+i-1] + (arr[j]*arr[k+1]*arr[j+i]));
				}
			}
		}
		
		bw.write(String.valueOf(dp[0][N-1]));
		
		bw.flush();
		bw.close();
	}
	
}
