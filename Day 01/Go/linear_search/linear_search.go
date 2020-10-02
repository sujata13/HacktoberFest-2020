package main

import "fmt"

// LinearSearch - implementation of the linear search algorithm
func LinearSearch(list []int, value int) int {
	for i := 0; i < len(list); i++ {
		if list[i] == value {
			fmt.Println(list[i])
			return i
		}
	}
	fmt.Println("Value not found in list")
	return -1
}

// Run this as go run Go/linear_search/linear_search.go
func main() {
	list := []int{10, 5, 3, 9, 2, 8, 7, 1, 4, 6}
	LinearSearch(list, 8)
}
