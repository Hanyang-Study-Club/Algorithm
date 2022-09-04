package week5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

public class B_15686_java {
	static int N, M;
	static List<int[]> house, chicken;
	static boolean[] visit;
	static int distance = 10000;
	static int temp_dist = 0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	      
	    String[] mn = br.readLine().split(" ");
	    N = Integer.parseInt(mn[0]);
	    M = Integer.parseInt(mn[1]);
	     
	    house = new ArrayList<int[]>();
	    chicken = new ArrayList<int[]>();
	    
	    
	    for(int i = 0 ; i < N ; i++) {
	       String[] ori = br.readLine().split(" ");
	       for(int j = 0; j < N; j++) {
	      	 int t = Integer.parseInt(ori[j]);
	       	 int[] in = {i,j};
	       	 if (t == 2) {
	       		 chicken.add(in);
	       	 } else if(t == 1) {
	       		 house.add(in);
	       	 }	 
	        }
	    }
	    visit = new boolean[chicken.size()];  
	    
	    DFS(0,0);
	      
        bw.write(String.valueOf(distance));
        
        br.close();
        bw.flush();
	    bw.close();
	}
	
	public static void DFS(int index, int team_num) {
		temp_dist = 0;
		if(team_num == M) {	// 치킨집 M개만큼 선별
			for(int i = 0; i < house.size(); i++) {	// 가정집 개수만큼 돌기 -> 치킨집과의 거리 전부다 비교하여 최소값을 temp_disttoC에 기록
				//System.out.println("======= i를 "+i+"으로 변경");
				int temp_disttoC = 100;
				for (int j = 0; j < chicken.size(); j++) { // 치킨집 개수만큼 돌기 -> 현재 선택된 치킨집인지 조건문으로 확인, 아니면 그냥 그 for문 넘기
					if (visit[j] != true) continue;		
					
					// 현재 가정집부터 현재 치킨집까지 거리
					int temp = Math.abs(chicken.get(j)[0]-house.get(i)[0]) + Math.abs(chicken.get(j)[1]-house.get(i)[1]);
					// 같은 가정집에 대해 가장 가까운 치킨집 알아내기
					temp_disttoC = temp_disttoC > temp ? temp : temp_disttoC; 
					//System.out.println("현재 : " + i + " ," +j + " :: "+ temp_disttoC);
				}
				// 한 가정집으로부터 모든 치킨집 사이 거리 비교 후 최소 값을 distance에 저장
				temp_dist += temp_disttoC;
				//System.out.println("집부터 치킨집까지 현재 적용된 거리 : "+ temp_dist);
			}
			distance = temp_dist < distance ? temp_dist : distance;		
			return;
		}
		
		for (int i = index; i < chicken.size(); i++) {
			visit[i] = true;
			DFS(i+1, team_num+1);
			visit[i] = false;
		}
		
	}
}
