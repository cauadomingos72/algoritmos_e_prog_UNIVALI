library IEEE;
use IEEE.std_logic_1164.all;

entity codi2_hot is
port(  i_A : in std_logic;
       i_B : in std_logic;
       o_S : out bit_vector(3 downto 0));
end codi2_4bits;

architecture arch_1 of codi2_hot is
begin
  o_S(0) <= (not i_A and not i_B);
  o_S(1) <= (not i_A and i_B);
  o_S(2) <= (i_A and not i_B);
  o_S(3) <= (i_A and i_B);
end arch_1;
