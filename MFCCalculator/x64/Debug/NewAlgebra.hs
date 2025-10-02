import Control.Applicative
import Data.Ratio
import System.Environment (getArgs)
import Text.Read
import Text.Read.Lex qualified as L

data Algebra
  = -- TODO  IntL Int
    IntH Integer
  | Doub Double
  | Rati Rational
  | -- TODO | Vect [Algebra]
    Matr [[Algebra]]
  deriving (Show, Eq)

class SafeNum a where
  safeAdd :: a -> a -> Either String a
  safeSub :: a -> a -> Either String a
  safeMul :: a -> a -> Either String a
  safeDiv :: a -> a -> Either String a

-- TODO safePow :: a -> a -> Either String a
-- TODO safeRec :: a -> Either String a -- 倒数
-- TODO safeNeg :: a -> Either String a
-- TODO safeAbs :: a -> Either String a

sameDim :: [[a]] -> [[b]] -> Bool
sameDim [] [] = True
sameDim (x : xs) (y : ys) = length x == length y && sameDim xs ys
sameDim _ _ = False

-- ratToIntL :: Ratio Int -> Algebra
-- ratToIntL a
--  | denominator a == 1 = IntL (numerator a)
--  | otherwise = RatL a

ratToIntH :: Ratio Integer -> Algebra
ratToIntH a
  | denominator a == 1 = IntH (numerator a)
  | otherwise = Rati a

instance SafeNum Algebra where -- TODO Matr
  safeAdd :: Algebra -> Algebra -> Either String Algebra
  safeAdd (IntH a) (IntH b) = Right $ IntH (a + b)
  safeAdd (Rati a) (Rati b) = Right $ Rati (a + b)
  safeAdd (Doub a) (Doub b) = Right $ Doub (a + b)
  safeAdd (IntH a) (Rati b) = Right $ ratToIntH ((a % 1) + b)
  safeAdd (Rati a) (IntH b) = Right $ ratToIntH (a + (b % 1))
  safeAdd (IntH a) (Doub b) = Right $ Doub (fromInteger a + b)
  safeAdd (Doub a) (IntH b) = Right $ Doub (a + fromInteger b)
  safeAdd (Rati a) (Doub b) = Right $ Doub (fromRational a + b)
  safeAdd (Doub a) (Rati b) = Right $ Doub (a + fromRational b)
  safeAdd _ _ = Left "存在类型不匹配的加法运算"

  safeSub :: Algebra -> Algebra -> Either String Algebra
  safeSub (IntH a) (IntH b) = Right $ IntH (a - b)
  safeSub (Rati a) (Rati b) = Right $ Rati (a - b)
  safeSub (Doub a) (Doub b) = Right $ Doub (a - b)  
  safeSub (IntH a) (Rati b) = Right $ ratToIntH ((a % 1) - b)
  safeSub (Rati a) (IntH b) = Right $ ratToIntH (a - (b % 1))
  safeSub (IntH a) (Doub b) = Right $ Doub (fromInteger a - b)
  safeSub (Doub a) (IntH b) = Right $ Doub (a - fromInteger b)
  safeSub (Rati a) (Doub b) = Right $ Doub (fromRational a - b)
  safeSub (Doub a) (Rati b) = Right $ Doub (a - fromRational b)
  safeSub _ _ = Left "存在类型不匹配的减法运算"

  safeMul :: Algebra -> Algebra -> Either String Algebra
  safeMul (IntH a) (IntH b) = Right $ IntH (a * b)
  safeMul (Rati a) (Rati b) = Right $ Rati (a * b)
  safeMul (Doub a) (Doub b) = Right $ Doub (a * b)    
  safeMul (IntH a) (Rati b) = Right $ ratToIntH ((a % 1) * b)
  safeMul (Rati a) (IntH b) = Right $ ratToIntH (a * (b % 1))
  safeMul (IntH a) (Doub b) = Right $ Doub (fromInteger a * b)
  safeMul (Doub a) (IntH b) = Right $ Doub (a * fromInteger b)
  safeMul (Rati a) (Doub b) = Right $ Doub (fromRational a * b)
  safeMul (Doub a) (Rati b) = Right $ Doub (a * fromRational b)  
  safeMul _ _ = Left "存在类型不匹配的乘法运算"

  safeDiv :: Algebra -> Algebra -> Either String Algebra
  safeDiv _ (IntH 0) = Left "除数为0"
  safeDiv _ (Rati 0) = Left "除数为0"
  safeDiv _ (Doub 0.0) = Left "除数为0"
  safeDiv (IntH a) (IntH b) = Right $ ratToIntH (a % b)
  safeDiv (Rati a) (Rati b) = Right $ Rati (a / b)
  safeDiv (Doub a) (Doub b) = Right $ Doub (a / b)      
  safeDiv (IntH a) (Rati b) = Right $ ratToIntH ((a % 1) / b)
  safeDiv (Rati a) (IntH b) = Right $ ratToIntH (a / (b % 1))
  safeDiv (IntH a) (Doub b) = Right $ Doub (fromInteger a / b)
  safeDiv (Doub a) (IntH b) = Right $ Doub (a /fromInteger b)
  safeDiv (Rati a) (Doub b) = Right $ Doub (fromRational a / b)
  safeDiv (Doub a) (Rati b) = Right $ Doub (a / fromRational b)  
  safeDiv _ _ = Left "存在类型不匹配的除法运算"

instance Read Algebra where
  readPrec :: ReadPrec Algebra
  readPrec =
    choice
      [ do
          L.Punc "[" <- lexP
          rows <- parseRows
          L.Punc "]" <- lexP
          return $ Matr rows,
        reset $ do
          son <- readPrec :: ReadPrec Integer
          L.Symbol "%" <- lexP
          mot <- readPrec :: ReadPrec Integer
          if mot /= 0
            then return $ Rati (son % mot)
            else pfail,
        do
          lexeme <- lexP
          case lexeme of
            L.Number n ->
              case L.numberToInteger n of
                Just i -> return $ IntH i
                Nothing -> return $ Doub (fromRational (L.numberToRational n))
            _ -> pfail
      ]
    where
      sepBy :: ReadPrec a -> ReadPrec sep -> ReadPrec [a]
      sepBy p sep = (:) <$> p <*> many (sep >> p) <|> return []
      parseRows = sepBy parseRow (do L.Punc "," <- lexP; return ())
      parseRow = do
        L.Punc "[" <- lexP
        ele <- sepBy readPrec (do L.Punc "," <- lexP; return ())
        L.Punc "]" <- lexP
        return ele

showAlgebra :: Algebra -> String
showAlgebra (IntH a) = show a
showAlgebra (Rati a) = show a
showAlgebra (Doub a) = show a
showAlgebra (Matr a) = show a

calculate :: String -> String -> String -> String
calculate x op y = case (readMaybe x :: Maybe Algebra, readMaybe y :: Maybe Algebra) of
  (Just a, Just b) -> case op of
    "+" -> ans $ safeAdd a b
    "-" -> ans $ safeSub a b
    "*" -> ans $ safeMul a b
    "/" -> ans $ safeDiv a b
    _ -> "不存在的运算符"
  (Nothing, Just b) -> "左操作数不合法"
  (Just a, Nothing) -> "右操作数不合法"
  (Nothing, Nothing) -> "左右操作数均不合法"
  where
    ans (Right res) = showAlgebra res
    ans (Left err) = err

main :: IO ()
main = do
  args <- getArgs
  case args of
    [a, op, b] -> putStrLn $ calculate a op b
    _ -> putStrLn "内部运算格式异常"