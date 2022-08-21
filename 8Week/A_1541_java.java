import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String string = br.readLine();
		int len = string.length();
		int answer = 0, start_i=0;
		boolean isMinus = false;

		for(int j = 0; j < len ; j++) {
			char cur = string.charAt(j);		
			if(cur == '-' || cur == '+' ) {
				if(isMinus) {
					answer -= Integer.parseInt(string.substring(start_i,j));
					start_i = j+1;
				}else {
					answer += Integer.parseInt(string.substring(start_i,j));
					start_i = j+1;
				}
			}
			if(cur == '-') {
				isMinus = true;
			}
			if(j == len-1) {
				if(isMinus) {
					answer -= Integer.parseInt(string.substring(start_i,len));
				}else {
					answer += Integer.parseInt(string.substring(start_i,len));
				}
			}
		}
		
		bw.write(String.valueOf(answer));
		br.close();
    bw.flush();
	  bw.close();
	}
}
