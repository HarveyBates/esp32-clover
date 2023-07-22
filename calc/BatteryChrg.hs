import Text.Printf

chrgCurrent :: Float -> Float
chrgCurrent resistance = 1104 * resistance ** (-0.93)

main :: IO ()
main = do
  printf "%.2f\n" $ chrgCurrent 2.3
