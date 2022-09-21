public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var numsToSearch = new Dictionary<int, List<int>>();

        for (int index = 0; index < nums.Length; ++index) {
            int complement = target - nums[index];

            if (numsToSearch.ContainsKey(complement)) {
                foreach (int secondIndex in numsToSearch[complement]) {
                    if (secondIndex != index) {
                        return new int[] { secondIndex, index };
                    }
                }
            }

            if (!numsToSearch.ContainsKey(nums[index])) {
                numsToSearch.Add(nums[index], new List<int> { index });
            } else {
                numsToSearch[nums[index]].Add(index);
            }
        }

        throw new ArgumentException("There is no solution for TwoSun.");
    }
}