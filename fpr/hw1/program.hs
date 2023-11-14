decode :: String -> [(Char, String)] -> String
decode [] _ = []  -- Konečný případ: prázdný vstupní řetězec
decode (x:xs) dictionary = case lookup x dictionary of Just originalPair -> originalPair ++ decode xs dictionary
    Nothing -> x : decode xs dictionary
