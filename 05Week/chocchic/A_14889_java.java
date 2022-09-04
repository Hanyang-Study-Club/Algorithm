package week5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class A_14889_java {
	static int N;
	static int[][] arr;
	static boolean[] visit;
	static int dif = 100;
		
	public static void main(String[] args) throws NumberFormatException, IOException {
	      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	      BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	      
	      N = Integer.parseInt(br.readLine());
	      arr = new int[N][N];
	      visit = new boolean[N];
	      
	      for(int i = 0 ; i < N ; i++) {
	         String[] ori = br.readLine().split(" ");
	         for(int j = 0; j < N; j++) {
	        	 arr[i][j] = Integer.parseInt(ori[j]);
	         }
	      }
	      
	      DFS(0,0);
	      
          bw.write(String.valueOf(dif));
          
          br.close();
	      bw.flush();
	      bw.close();
	}
	
	public static void DFS(int index, int team_num) {
		if(team_num == N/2) {
			int start = 0, link = 0;
			
			for (int i = 0; i < N-1; i++) {
				for (int j = i+1; j < N; j++ ) {
					if (visit[i] == true && visit[j] == true) {
						start += arr[i][j];
						start += arr[j][i];
					}
					if(visit[i] == false && visit[j] == false) {
						link += arr[i][j];
						link += arr[j][i];
					}
				}
			}
			
			int temp_dif = Math.abs(start-link);
			
			if (temp_dif == 0) {
				dif = temp_dif;
				return;
			}
			
			dif = dif > temp_dif ? temp_dif : dif;

			return;
		}
		
		for (int i = index; i < N; i++) {
			visit[i] = true;
			DFS(i+1, team_num+1);
			visit[i] = false;
		}
	}
}
