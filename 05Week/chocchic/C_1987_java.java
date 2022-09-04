package week5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class C_1987_java {
	static int R, C;
	static char[][] Board;
	static boolean[] visit = new boolean[26]; // 0 : A, 26 : Z, 방문한 알파벳을 오름차순으로 기록
	static int[] x = {1, -1, 0, 0}; // x축 이동용
	static int[] y = {0, 0, 1, -1}; // y축 이동용
	static int count = 0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	      
	    String[] rc = br.readLine().split(" ");
	    R = Integer.parseInt(rc[0]);
	    C = Integer.parseInt(rc[1]);
	     
	    Board = new char[R][C];
	    
	    for(int i = 0 ; i < R ; i++) {
	    	String[] temp = br.readLine().split("");
	    	for(int j = 0; j < C; j++) {
	    		Board[i][j] = temp[j].charAt(0);
	        }
	    }
	    
	    visit[Board[0][0]-'A'] = true; // 0,0 번째 말은 이미 들렸으므로 방문한 알파벳 배열에 추가	    
	    
	    DFS(0,0,1);
	      
        bw.write(String.valueOf(count));
        
        br.close();
        bw.flush();
	    bw.close();
	}
	
	public static void DFS(int index_x, int index_y, int temp_count) {
		count = count > temp_count ? count : temp_count;
		
		for (int move = 0; move < 4; move++) {
			int v_x = index_x + x[move];
			int v_y = index_y + y[move];
			
			if (0<= v_x && v_x < C && 0 <= v_y && v_y < R) {
				if (visit[Board[v_y][v_x]-'A'] == true) continue;
			
				visit[Board[v_y][v_x]-'A'] = true;
				DFS(v_x, v_y, temp_count+1);
				visit[Board[v_y][v_x]-'A'] = false;
			}
		}
	}
}
