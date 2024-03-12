package main

func removeDuplicates(nums []int) int {
	if len(nums) == 1 {
		return 1
	}

	i := 0

	for j := 1; j < len(nums); j++ {
		if nums[j] == nums[i] {
			continue
		}

		i++
		nums[i] = nums[j]
	}

	return i + 1
}
