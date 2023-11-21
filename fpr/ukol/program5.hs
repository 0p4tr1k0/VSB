decode :: String -> [(Char, String)] -> String
decode encodedText dictionary = decodeHelper encodedText dictionary ""
  where
    decodeHelper :: String -> [(Char, String)] -> String -> String
    decodeHelper [] _ acc = acc
    decodeHelper (x:xs) dict acc =
      if lookup x dict /= Nothing
        then
          let Just originalPair = lookup x dict
          in decodeHelper xs dict (acc ++ originalPair)
        else
          decodeHelper xs dict (acc ++ [x])
