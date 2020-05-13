public class Rotate {
  public static void main(String[] args) {
    int nums[] = {1,2,3,4,5,6};
    rotate(nums, 4);
    for (int  i : nums) {
      System.out.println(i);
    }
  }
  public static void rotate(int[] nums, int k) {
    k = k % nums.length;
    int count = 0;
    for (int start = 0; count < nums.length; start++) {
      int current = start;
      int prev = nums[start];
      do {
        int next = (current + k) % nums.length;
        int temp = nums[next];
        nums[next] = prev;
        prev = temp;
        current = next;
        count++;
      } while (start != current);
    }
  }
}
