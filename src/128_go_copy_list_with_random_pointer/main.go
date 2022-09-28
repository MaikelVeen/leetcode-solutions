package main

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	clones := map[*Node]*Node{}

	cursor := head
	for {
		clones[cursor] = &Node{
			Val: cursor.Val,
		}

		if cursor.Next == nil {
			break
		}

		cursor = cursor.Next
	}

	cursor = head
	for {
		clones[cursor].Next = clones[cursor.Next]
		clones[cursor].Random = clones[cursor.Random]

		if cursor.Next == nil {
			break
		}

		cursor = cursor.Next
	}

	return clones[head]
}
