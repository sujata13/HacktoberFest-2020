package hacktober;

public class Knapsack01 {


		public static void main(String[] args) {
			// TODO Auto-generated method stub
			int[] w = { 1, 3, 4, 5 };
			int[] p = { 1, 4, 5, 7 };
			int tw=7;
			System.out.println(bu(w, p, 7));
		}

		public static int rec(int[] weight, int[] price, int ci, int cw, int tw) {
			if(ci==price.length || cw==tw)
				return 0;
			int a1=0;
			// use item
			if(weight[ci]+cw<=tw)
			a1 = price[ci] + rec(weight, price, ci+1, cw + weight[ci], tw);
			// dont use item
			int a2 = rec(weight, price, ci + 1, cw, tw);
			return Math.max(a1, a2);
		}
		public static int td(int[] weight, int[] price, int ci, int cw, int tw,int [][] strg) {
			if(ci==price.length)
				return 0;
			if(strg[ci][cw]!=0)
				return strg[ci][cw];
			int a1=0;
			// use item
			if(weight[ci]+cw<=tw)
			a1 = price[ci] + td(weight, price, ci+1, cw + weight[ci], tw,strg);
			// dont use item
			int a2 = td(weight, price, ci + 1, cw, tw,strg);
			int ans=Math.max(a1, a2);
			strg[ci][cw]=ans;
			return ans;
		}
		public static int bu(int [] weight,int [] price,int tw) {
			int n=price.length;
			int [][] arr=new int[n+1][tw+1];
			for(int row=arr.length-2;row>=0;row--) {
				for(int col=0;col<arr[0].length-1;col++) {
					//not use
					int a1=arr[row+1][col];
					//use
					int a2=0;
					if(col+weight[row]<=7)
					a2=arr[row+1][col+weight[row]]+price[row];
					arr[row][col]=Math.max(a1, a2);
				}
			}
			return arr[0][0];
		}
	}

