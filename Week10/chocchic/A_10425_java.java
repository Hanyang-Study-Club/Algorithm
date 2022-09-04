package week10;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

// 피보나치 인버스
public class A_10425_java {
	public static BigInteger fibo[];
	
	public static void getFibo() {
		fibo = new BigInteger[100010];
		fibo[0] = new BigInteger("0");
		fibo[1] = new BigInteger("1");
		fibo[2] = new BigInteger("1");
		
		BigInteger temp1 = fibo[1]; BigInteger temp2 = fibo[2];
		
	    for (int i=3; i<=100000; i++) {
	    	BigInteger now = temp1.add(temp2);
	    	fibo[i] = now;
	    	//System.out.println("i : "+i+", now" + now);
	    	
	    	temp1 = temp2; temp2 = now;
	    }

	    return;
	}
	
	public static int search(BigInteger F) {
		for(int i = 3; i <= 100000; i++) {
			if(fibo[i].equals(F)) {
				return i;
			}
		}
//		int first = 0, last = 100000;
//		while (first <= last) {
//	        int mid = (first+last)/2;
//	        if (fibo[mid].compareTo(F) == 0) {
//	        	return mid;
//	        }
//	        else if (fibo[mid].compareTo(F) == -1) {
//	        	last = mid-1;
//	        }
//	        else {
//	        	first = mid+1;
//	        }
//	    }
	    return -1;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		BigInteger F;
		
		getFibo();	
		
		StringBuilder sb = new StringBuilder();
		
		for(int i = 0 ; i < T ; i++){
			F = new BigInteger(br.readLine());
			if(F.equals(new BigInteger("1"))) {
				sb.append("2\n");
			}else {
				sb.append(search(F)+"\n");
			}
		}

		bw.write(sb.toString());
		br.close();
        bw.flush();
	    bw.close();
	}
}
