library IEEE;
use IEEE.std_logic_1164.all;

entity demux2_1bit is
port( i_SEL : in std_logic;
      i_A : in std_logic;
      o_R : out std_logic;
      o_S : out std_logic);
end demux2_1bit;

architecture arch_1 of demux2_1bit is
begin
  o_R <= (i_A and not i_SEL);
  o_S <= (i_A and i_SEL);
end arch_1;
