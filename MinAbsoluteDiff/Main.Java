/*
Given a sorted array of length N and a given key K. We need to find the element in an array which has absolute minimum difference with the given key K.
Ex:  int arr[] = {1, 3, 8, 10, 15}, N = 5, K=10
       O/P = 10
       int arr[] = {1, 3, 8, 11, 15}, N = 5, K=9
       O/P = 8
*/
public class Main {
    public static void main(String[] args) {
        Main m = new Main();
        int[] arr = {-2,-1, 3, 8, 11, 15};
        int k = -2;
        System.out.println(m.minAbsoluteDiff(arr, k));
    }
    
    int minAbsoluteDiff(int arr[], int k){
        int start = 0;
        int end = arr.length - 1;
        int minVal = Integer.MAX_VALUE;
        int idx = -1;
        while(start <= end){
            int mid = (start + (end - start)/2);
            int diff = Math.abs(arr[mid] - k);
            if(diff < minVal){
                idx = mid;
                minVal = diff;
            }
            
            if(arr[mid] < k){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return arr[idx];
    }
}
