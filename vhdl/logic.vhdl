entity logic is
  port ( val_a : in  bit;
         val_b : in  bit;
         sum   : out bit;
         carry : out bit);
end entity logic;

architecture behav of logic is
begin
  
  sum   <= val_a xor val_b;
  carry <= val_a and val_b;
  
end architecture behav;