library IEEE;
use IEEE.std_logic_1164.all;

entity fullsomador is
port (	i_A : in std_logic_vector (7 downto 0);
      	i_B : in std_logic_vector (7 downto 0);
			i_CIN : in std_logic;
			o_COUT : out std_logic;
			o_S : out std_logic_vector (7 downto 0));
end fullsomador;
	
architecture design of fullsomador is
component somador
port (  i_A : in std_logic;
	i_B : in std_logic;
	i_CIN : in std_logic;
	o_COUT : out std_logic;
	o_S : out std_logic);
end component;
	
signal w_co0, w_co1, w_co2, W_co3, W_co4, W_co5, W_co6, W_co7 : std_logic;
begin
FS0 : somador port map(i_A (0), i_B (0), i_CIN, w_co0, o_S(0));
	
FS1 : somador port map(i_A (1), i_B (1), w_co0, w_co1, o_S(1));
	
FS2 : somador port map(i_A (2), i_B (2), w_co1, w_co2, o_S(2));
	
FS3 : somador port map(i_A (3), i_B (3), w_co2, w_co3, o_S(3));

FS4 : somador port map(i_A (4), i_B (4), w_co3, w_co4, o_S(4));
	
FS5 : somador port map(i_A (5), i_B (5), w_co5, w_co6, o_S(5));
	
FS6 : somador port map(i_A (6), i_B (6), w_co6, w_co7, o_S(6));
	
FS7 : somador port map(i_A (7), i_B (7), w_co7, o_COUT, o_S(7));

	
end design;
