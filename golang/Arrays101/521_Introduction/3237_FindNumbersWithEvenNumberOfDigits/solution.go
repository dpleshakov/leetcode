package solution

func hasEvenNumberOfDigits(num int) bool {
	result := true
	order := 1

	for num/order > 0 {
		result = !result
		order *= 10
	}

	return result
}

func findNumbers(nums []int) int {
	result := 0

	for _, num := range nums {
		if hasEvenNumberOfDigits(num) {
			result++
		}
	}

	return result
}
