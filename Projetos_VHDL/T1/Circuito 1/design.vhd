library IEEE;
use IEEE.std_logic_1164.all;

entity mux2_1bit is
port ( i_SEL : in std_logic; -- selector
       i_A : in std_logic; -- data input
       i_B : in std_logic; -- data input
       o_S : out std_logic); -- data output
end mux2_1bit;

architecture arch_1 of mux2_1bit is
begin
  o_S <= (i_A and not i_SEL) or (i_B and i_SEL);
end arch_1;
