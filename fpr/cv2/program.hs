data Point = Point{x :: Int, y :: Int}
data Position = Position {topLeftCorner :: Point, width :: Int, height :: Int}

data Component = TextBox {name :: String, position :: Position, text :: String}|
                Button {name :: String, position :: Position, text :: String}|
                Container {name :: String, children :: [Component]}

gui :: Component
gui = Container "Moje GUI" [
    Container "Menu" [
        Button "Button_new" (Position (Point 10 10)10 20) "New",
        Button "Button_save" (Position (Point 10 50)10 20) "Save"
    ],
    Container "Page" [
        TextBox "tb_1" (Position (Point 10 150)100 20) "Muj text"
    ],
    Container "Footer" []
    ]

instance Show Component where
    show component = plshelp component 0 where
        plshelp (Button name position text) tabs = replicate tabs '\t' ++ text ++ "\n"
        plshelp (TextBox name postion text) tabs = replicate tabs '\t' ++ text ++ "\n"
        plshelp (Container name children) tabs = replicate tabs '\t' ++ name ++ "\n" ++ concatMap (\x -> plshelp x (tabs+1)) children

identify :: Component -> Component
identify (Container n children) = Container n [identify c| c <- children]
identify (TextBox n p t) = TextBox n p t
identify (Button n p t) = Button n p t

insertInto :: Component -> String -> Component -> Component
insertInto (Container n children) name comp = 
    let
        chs = if n == name then children ++ [comp] else children
    in Container n [insertInto c name comp | c<-chs]
insertInto (TextBox n p t) name comp = (TextBox n p t)
insertInto (Button n p t) name comp = (Button n p t)