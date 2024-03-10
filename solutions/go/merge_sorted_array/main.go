package main

func merge(nums1 []int, m int, nums2 []int, n int) {
	if m == 0 {
		copy(nums1, nums2)
		return
	}
	if n == 0 {
		return
	}

	nums1copy := make([]int, m)
	copy(nums1copy, nums1[:m])

	p1 := 0
	p2 := 0
	wp := 0

	for p1 < m && p2 < n {
		if nums1copy[p1] < nums2[p2] {
			nums1[wp] = nums1copy[p1]
			p1++
		} else {
			nums1[wp] = nums2[p2]
			p2++
		}
		wp++
	}

	if p1 < m {
		copy(nums1[wp:], nums1copy[p1:])
	}
	if p2 < n {
		copy(nums1[wp:], nums2[p2:])
	}
}
