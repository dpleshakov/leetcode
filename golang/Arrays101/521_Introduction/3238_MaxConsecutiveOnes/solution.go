package solution

func max(left, right int) int {
	if left < right {
		return right
	}
	return left
}

func findMaxConsecutiveOnes(nums []int) int {
	result := 0
	current := 0

	for _, num := range nums {
		if num == 1 {
			current++
		} else {
			result = max(result, current)
			current = 0
		}
	}

	result = max(result, current)

	return result
}
