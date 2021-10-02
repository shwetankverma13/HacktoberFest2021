package BinarySearchCode;

public class BinarySearchJavaCode {
    public static void main(String[] args) {
        int[] arr = {12,18,22,29,36,39,42,67,99};
        int target = 39;
        int ans = binarySearchCode(arr,target);
        System.out.println(ans);
    }
    static int binarySearchCode(int[] arr, int target){
        int start = 0;
        int end = arr.length - 1;
        while(start <= end){
            // here we will not do int mid = (start + end) / 2;
            // might be possible that (start + end) exceeds the range of int in java
            // so better way is as below to find middle element
            int mid = start + (end-start) / 2;
            if(target < arr[mid]){
                end = mid - 1;
            } else if(target > arr[mid]){
                start = mid + 1;
            } else {
                // element found hence return index of that element
                return mid;
            }
        }
        // if element not found then return -1
        return -1;
    }
}

/*
Time Complexity 
Best Case :- O(1)
Worst Case :- O(log n)
*/
