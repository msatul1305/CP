import java.io.*;
import java.util.*;

public class timeloop {
	public static void main(String[] args) throws IOException {
		int n = readI();
		String s = "Abracadabra";
		for(int i = 1; i <= n; i++) {
			System.out.println(i + " " + s);
		}
	}
	
	public static int readI() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String I = br.readLine();
		int r = Integer.parseInt(I);
		return r;
	}
	
	public static double readD() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String I = br.readLine();
		double r = Double.parseDouble(I);
		return r;
	}
	
	public static String readS() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String I = br.readLine();
		return I;
	}
	
	public static long readL() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String I = br.readLine();
		long r = Long.parseLong(I);
		return r;
	}

}
