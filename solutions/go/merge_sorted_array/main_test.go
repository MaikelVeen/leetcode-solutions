package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_merge(t *testing.T) {
	type args struct {
		nums1    []int
		m        int
		nums2    []int
		n        int
		expected []int
	}
	tests := []struct {
		name string
		args args
	}{
		{
			name: "Example 1",
			args: args{
				nums1:    []int{1, 2, 3, 0, 0, 0},
				m:        3,
				nums2:    []int{2, 5, 6},
				n:        3,
				expected: []int{1, 2, 2, 3, 5, 6},
			},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			merge(tt.args.nums1, tt.args.m, tt.args.nums2, tt.args.n)

			// Assert that nums one is equal to the expected
			assert.Equal(t, tt.args.expected, tt.args.nums1)
		})
	}
}
