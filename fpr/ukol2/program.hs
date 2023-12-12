type Maze = [String]
type Result = (Int, Int)

solveMaze :: Maze -> Int
solveMaze maze = bfs [(start, 0)]
  where
    numRows = length maze
    numCols = length (head maze)
    start = head [(r, c) | r <- [0..numRows-1], c <- [0..numCols-1], maze !! r !! c == 's']

    bfs :: [(Result, Int)] -> Int
    bfs [] = -1
    bfs ((current, steps):queue)
      | maze !! fst current !! snd current == 'e' = steps
      | otherwise =
        bfs (queue ++ nextPositions current (steps + 1))

    nextPositions :: Result -> Int -> [(Result, Int)]
    nextPositions (r, c) s =
      filter (\pos -> isValid pos && maze !! fst pos !! snd pos /= '*')
             [(r-1, c), (r+1, c), (r, c-1), (r, c+1)]
             >>= (\pos -> [(pos, s)])

    isValid :: Result -> Bool
    isValid (r, c) = r >= 0 && r < numRows && c >= 0 && c < numCols

-- Test cases
sampleInput1 :: Maze
sampleInput1 =
  ["*********",
   "*s*   *e*",
   "* *   * *",
   "* *   * *",
   "*       *",
   "******* *",
   "        *",
   "*********"]

sampleInput2 :: Maze
sampleInput2 =
  ["*********",
   "*s*   * *",
   "* *   * *",
   "* *   * *",
   "*       *",
   "******* *",
   "e       *",
   "*********"]