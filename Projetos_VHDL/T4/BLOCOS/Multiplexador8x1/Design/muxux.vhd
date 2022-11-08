library ieee;
use ieee.std_logic_1164.all;

entity muxux is
port ( i_R7  : in std_logic_vector(3 downto 0);
		 i_R6  : in std_logic_vector(3 downto 0);
		 i_R5  : in std_logic_vector(3 downto 0);
		 i_R4  : in std_logic_vector(3 downto 0);
		 i_R3  : in std_logic_vector(3 downto 0);
		 i_R2  : in std_logic_vector(3 downto 0);
		 i_R1  : in std_logic_vector(3 downto 0);
		 i_R0  : in std_logic_vector(3 downto 0);
       i_XYZ  : in std_logic_vector(2 downto 0);
       o_Q   : out std_logic_vector(3 downto 0)); 
end muxux;

architecture arch_1 of muxux is 
begin 
				with i_XYZ select 
						o_Q <= i_R0 when "000",
								 i_R1 when "001", 
								 i_R2 when "010",
								 i_R3 when "011",
								 i_R4 when "100",
								 i_R5 when "101",
								 i_R6 when "110",
								 i_R7 when "111";
end arch_1;
