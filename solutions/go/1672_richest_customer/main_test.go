package main

import "testing"

func Test_maximumWealth(t *testing.T) {
	tests := map[string]struct {
		want     int
		accounts [][]int
	}{
		"example 1": {
			accounts: [][]int{{1, 2, 3}, {3, 2, 1}},
			want:     6,
		},
		"example 2": {
			accounts: [][]int{{1, 5}, {7, 3}, {3, 5}},
			want:     10,
		},
		"example 3": {
			accounts: [][]int{{2, 8, 7}, {7, 1, 3}, {1, 9, 5}},
			want:     17,
		},
	}

	for name, tt := range tests {
		t.Run(name, func(t *testing.T) {
			if got := maximumWealth(tt.accounts); got != tt.want {
				t.Errorf("maximumWealth() = %v, want %v", got, tt.want)
			}
		})
	}
}
