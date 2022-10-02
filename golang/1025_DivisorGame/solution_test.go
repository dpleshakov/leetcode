package solution

import (
	"testing"
)

func TestDefault1(t *testing.T) {
	n := 2
	want := true

	res := divisorGame(n)
	if res != want {
		t.Fatalf(`divisorGame(%q) = %t, want match for %t`, n, res, want)
	}
}

func TestDefault2(t *testing.T) {
	n := 3
	want := false

	res := divisorGame(n)
	if res != want {
		t.Fatalf(`divisorGame(%q) = %t, want match for %t`, n, res, want)
	}
}
