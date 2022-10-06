package solution

import (
	"testing"
)

func TestFindMaxConsecutiveOnes1(t *testing.T) {
	nums := []int{1, 1, 0, 1, 1, 1}
	want := 3

	res := findMaxConsecutiveOnes(nums)
	if res != want {
		t.Fatalf("findMaxConsecutiveOnes(%v) = %v, want match for %v", nums, res, want)
	}
}

func TestFindMaxConsecutiveOnes2(t *testing.T) {
	nums := []int{1, 0, 1, 1, 0, 1}
	want := 2

	res := findMaxConsecutiveOnes(nums)
	if res != want {
		t.Fatalf("findMaxConsecutiveOnes(%v) = %v, want match for %v", nums, res, want)
	}
}
