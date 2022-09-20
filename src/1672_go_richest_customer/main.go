package main

func maximumWealth(accounts [][]int) int {
	var max int

	for _, cus := range accounts {
		var sum int
		for _, account := range cus {
			sum += account
		}

		if sum > max {
			max = sum
		}
	}

	return max
}
