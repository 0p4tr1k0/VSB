{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Redundant bracket" #-}
import Graphics.Win32 (vK_DIVIDE, vK_ACCEPT)
data Tree a = Leaf a | Internal a (Tree a) (Tree a) deriving (Show)

tree1 :: Tree Int
tree1 = Internal 10 (Internal 5 (Leaf 8) (Leaf 9)) (Leaf 6)

treeSum :: Tree Int -> Int
treeSum (Leaf v) = v
treeSum (Internal v lt rt) = v + treeSum lt + treeSum rt

toList :: Tree a -> [a]
toList (Leaf v) = [v]
toList (Internal v lt rt) = toList lt ++ [v] ++ toList rt

maxTree :: Ord a => Tree a -> a
maxTree (Leaf v) = v
maxTree (Internal v lt rt) = maximum [v, maxTree lt, maxTree rt]
--maxTree (Internal v (Leaf v1) (Leaf v2)) = maximum [v, v1, v2]

depthTree :: Tree a -> Int
depthTree (Leaf _) = 0
depthTree (Internal _ lt rt) = 1 + max (depthTree lt) (depthTree rt)

getGreaterElements :: Ord a => Tree a -> a -> [a]
getGreaterElements t lin = filter (> lin) (toList t)

toString :: Show a => Tree a -> String
toString (Leaf v) = show v
toString (Internal v lt rt) = show v ++"(" ++ (toString lt) ++ "," ++ (toString rt) ++ ")"