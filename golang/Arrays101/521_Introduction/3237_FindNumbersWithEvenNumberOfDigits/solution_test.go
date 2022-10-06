package solution

import (
	"testing"
)

func TestFindNumbers1(t *testing.T) {
	nums := []int{12, 345, 2, 6, 7896}
	want := 2

	res := findNumbers(nums)
	if res != want {
		t.Fatalf("findNumbers(%v) = %v, want match for %v", nums, res, want)
	}
}
