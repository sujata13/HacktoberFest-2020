class IterativeBinarySearch {
    public int search(int arr[], int x){
        int l = 0, r = arr.length - 1;

        while(l <= r){
            int m = l + (r  - l) / 2;

            if (arr[m] == x){
                return m;
            }
            else if (arr[m] < x){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        IterativeBinarySearch bs = new IterativeBinarySearch();

        int arr[] = {1, 5, 8, 10, 36, 48};

        int result = bs.search(arr, 36);

        if (result == -1){
            System.out.println("Element not found!");
        } else {
            System.out.println("Element found at index : " + result);
        }
    }
}
