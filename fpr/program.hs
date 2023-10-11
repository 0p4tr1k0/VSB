import System.Win32 (COORD(x))
take' :: Int -> [a] -> [a]
take' 0 xs = []
take' _ [] = []
take' n (x:xs)= x : take' (n - 1) xs

drop' :: Int -> [a] -> [a]
drop' 0 xs = xs
drop' n (x:xs) = drop' (n-1) xs

divisors :: Int -> [Int]
divisors n = tmp n where
  tmp 0 = []
  tmp x | n `mod` x == 0 = x: tmp (x-1)
        | otherwise = tmp (x-1)

zipThem:: [a] -> [b] -> [(a,b)]
zipThem (x:xs) (y:ys) = (x,y) : zipThem xs ys
zipThem _ _ = []