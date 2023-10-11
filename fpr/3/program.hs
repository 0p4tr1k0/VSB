import System.Win32 (COORD(x))
len :: [a] -> Int
len [] = 0
len (_:xs) = 1 + len xs

sumIt :: [Int] -> Int
sumIt xs = sum xs 

getHead :: [a] -> a
getHead []= error ("Nelze")
getHead [x] = x
getHead [x,y] = x

isElement :: Eq a => a -> [a] -> Bool
isElement _ [] = False
isElement a (x:xs) = (a == x) || isElement a xs


getInit :: [a] -> [a]
getInit [_] = []
getInit (x:xs) = x : getInit xs

combine :: [a] -> [a] -> [a]
combine []ys = ys
combine (x:xs) ys = x : combine xs ys

max' :: [Int] -> Int
max' [x] = x
max' (x:y:zbytek) = if x < y then max' (y:zbytek) else max' (x:zbytek)

reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]

scalar :: [Int] -> [Int] -> Int
scalar [] [] = 0
scalar (x:xs) (y:ys) = x*y + scalar xs ys
