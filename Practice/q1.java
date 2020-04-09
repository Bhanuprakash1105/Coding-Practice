import java.util.*;
import java.lang.*;
import java.io.*;

class q3 {

	int mooreVoting_algo(Integer a[], int size)
	{
		int index = 0, count = 1;
		for (int i = 1; i < size; i++) {
			if(a[i] == a[index]) { count++; } else { count--; }
			if(count == 0) { index = i; count = 1; }
		}
		return a[index];
	}

	public static void main(String[] args) {

		Scanner scanVar = new Scanner(System.in);

		System.out.print("\nEnter the size of array: ");
		int size = scanVar.nextInt();

		System.out.print("\nValues into array: ");
		Integer[] a = new Integer[size];
		for (int i = 0; i < size; ++i) {
			a[i] = scanVar.nextInt();
		}
		scanVar.close();

		q3 obj = new q3();
		//Using Moore's Voting Algorithm
		int max = obj.mooreVoting_algo(a, size);
		
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i = 0; i < size; ++i) {
			if(map.get(max) == null) { map.put(max, 1); } else if(max == a[i]) {
				int temp = map.get(max);
				temp++;
				map.put(max, temp);
			}
		}

		if(map.get(max) > (int)size/3) { System.out.println("\nThe output is: "+ max +"\n"); } else {
			System.out.println("\nThe output is: "+ -1 +"\n");
		}

		return;
	}
}