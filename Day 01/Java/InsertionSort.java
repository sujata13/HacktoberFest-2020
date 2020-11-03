
public class insertionsortexample{
    public static void insertionsort(int arr[]) {
      int n= arr.length;
      for(int j=1;j<n;j++){
        int key = arr[j];
        int i=j-1;
        while((i>-1) && (arr[i]>key)) {
          arr[i+1] = arr[i];
          i--;
        }
        arr[i+1]=key;
    }
}
public static void main(String a[]){
  int[] arr1 = {9,14,2,3,5,23,53};
  System.out.println("Before Insertion Sort");
  for(int i:arr1){
    System.out.println(i+" ");
  }
  System.out.println();
  insertionsort(arr1);
  System.out.println("After insertion Sort");
  for(int i:arr1){
    System.out.println(i+" ");
  }
}
}
