algo
|while length < max graph size / 2 + 1 or no more node/way added
|| all ways from start + 1
|| all ways from end + 1

add 1 to ways from x
| for each way from x
|| for each available node
|||if this node is already marked
||||if it is marked from x
|||||close this node for this way
||||else
|||||mark is from x
|||||add this way to the other way that marked the node and add it to the full ways
|||else
||||mark it and add the new node/way


