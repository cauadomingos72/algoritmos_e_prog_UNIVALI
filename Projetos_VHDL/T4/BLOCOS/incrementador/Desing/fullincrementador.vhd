library IEEE;
use IEEE.std_logic_1164.all;
use work.all;

entity fullincrementador is
port (i_A : in std_logic_vector (3 downto 0);
		i_B : in std_logic;
      o_COUT : out std_logic;
      o_S : out std_logic_vector (3 downto 0));
end fullincrementador;

architecture design of fullincrementador is
component incrementador
port ( i_A : in std_logic;
	    i_B : in std_logic;
       o_COUT : out std_logic;
       o_S : out std_logic);
end component;

signal w_B0, w_B1, w_B2 : std_logic;

begin
FS0 : incrementador port map(i_A (0), i_B, w_B0, o_S (0));
FS1 : incrementador port map(i_A (1), w_B0, w_B1, o_S (1));
FS2 : incrementador port map(i_A (2), w_B1, w_B2, o_S (2));
FS3 : incrementador port map(i_A (3), w_B2, o_COUT, o_S (3));
end design;
