library IEEE;
use IEEE.std_logic_1164.all;

entity incrementador is
port ( i_A : in std_logic;
	   i_B : in std_logic;
       o_COUT : out std_logic;
       o_S : out std_logic);
end incrementador;

architecture comp of incrementador is
begin
	process(i_A, i_B)
    begin
    o_S <= (i_A and i_B) or (not i_A and not i_B) or (not i_A and i_B) or (i_A and not i_B);
    o_COUT <= (i_A and i_B);
    end process;
end comp;
