--Úloha 1
--Funkce vezme seznam dvojic (osoba, věk) a číslo (n). Funkce vrací seznam osob, jejichž věk je menší než číslo (n).
--seznamOsob = (osoba, věk)
--n = číslo, které určuje hranici věku
filter' :: [(String, Int)] -> Int -> [String]
filter' seznamOsob n = [osoba | (osoba, vek) <- seznamOsob, vek < n]


--Úloha 2
--Funkce se implementuje a vrací seznam indexu (pozic), na kterých se zadané písmeno nachází.
--text = textový řetězec + index
--index = číšlování od nuly
--char = písmeno v řetězci
positions :: String -> Char -> [Int]
positions text c = [index | (char, index) <- zip text [0..], char == c]

--Úloha 3
--Funkce vybírá ze seznamu prvky, které jsou vypsané jen jednou
--unique::Eq a=>[a] -> [a] -> [a] -> [a]
--unique seznam = [vyslednyS | ]