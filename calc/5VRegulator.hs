-- 5V Step up-converter TPS6123x
module TPS6123 where

import Text.Printf

v_ref :: Float
v_ref = 1.0

v_in :: Float
v_in = 3.3

v_out :: Float
v_out = 5.0

nanoToAmps :: Float -> Float
nanoToAmps value = value * 1e-9

-- Startup
-- SS pin enables output voltage to follow the SS pin's 
-- voltage slope
softStartTime :: Float -> Float
softStartTime c_ss = (c_ss / (nanoToAmps 5)) * (1 - (v_in / v_out) * v_ref)

-- Output voltage feedback
-- R2 should be < 100 K
-- Keeping R2 close to 100K allows for low quiescent current
voltageOut :: Integer -> Integer -> Float
voltageOut r1 r2 = v_ref * (1 + (fromIntegral r1 / fromIntegral r2))

main :: IO ()
main = do
  printf "Soft-start time = %.2f sec\n" $ softStartTime $ nanoToAmps 10
  printf "Volage out = %.2f V\n" $ voltageOut 402_000 100_000


