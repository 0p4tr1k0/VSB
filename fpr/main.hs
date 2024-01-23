{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
import Data.List (isPrefixOf)


data Component = Button { name :: String, value :: String }
               | Container { name :: String, children :: [Component] }
               | TextBox { name :: String, text :: String }
               deriving Show


gui :: Component
gui =
  Container "My App" [
    Container "Menu" [
      Button "btn_new" "New",
      Button "btn_open" "Open",
      Button "btn_close" "Close"
    ],
    Container "Body" [TextBox "textbox 1" "Some text goes here"],
    Container "Footer" [Button "btn_submit" "Submit"]
  ]

-- isPrefixof vrací Bool

-- Funkce pro hledání jmen komponent, která začínají na zadaný prefix
startWithName :: Component -> String -> [String]
-- V případě Button vrátíme seznam, který obsahuje jméno pouze tehdy, když je prefix jeho prefixem
startWithName (Button n _) prefix = [n | prefix `isPrefixOf` n]
-- V případě Container použijeme concatMap na seznam dětí a rekurzivně voláme startWithName na každou z nich
startWithName (Container _ children) prefix = concatMap (\child -> startWithName child prefix) children
-- V případě TextBox vrátíme seznam, který obsahuje jméno pouze tehdy, když je prefix jeho prefixem
startWithName (TextBox n _) prefix = [n | prefix `isPrefixOf` n]
-- Výchozí vzor pro případ, kdy se nejedná o Button, Container ani TextBox. Vracíme prázdný seznam.
startWithName _ _ = []


-- Vezme komponentu a vrátí novou upravenou komponentu
noContainers :: Component -> Component
-- Vezme počáteční kontejner s nějakým názvem a dítě předá potom do "filtru" , za kterým stojí unwrapContainer funkce a spojí se s tím zbytkem z kontejneru
noContainers (Container name children) = Container name (concatMap (unwrapContainer . noContainers) children)
noContainers other = other
-- Pomocná funkce, která vezme komponentu a potom vrátí jenom jeho children (potomka, instance, které potřebujeme)
unwrapContainer :: Component -> [Component]
-- oddělí children od kontejneru a vrátí ty instance, které se spojí concatmapem
unwrapContainer (Container _ children) = children
-- pokud dostane něco jiného, tak jako list to taky vrátí
unwrapContainer other = [other]