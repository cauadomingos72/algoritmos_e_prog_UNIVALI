library IEEE;
use IEEE.std_logic_1164.all;

entity comparador8bits is
port (  i_A : in std_logic_vector(7 downto 0);
		  i_B : in std_logic_vector(7 downto 0);
		  o_S : out std_logic);
end comparador8bits;
	
architecture comp of comparador8bits is

signal w_x0, w_x1, w_x2, w_x3, w_x4, w_x5, w_x6, w_x7 : std_logic;
begin
	
w_x0 <=(i_A(0) and i_B(0)) or (not i_A(0) and not i_B(0)) or (i_A(0) and not i_B(0)) or (not i_A(0) and i_B(0)); 
w_x1 <=(i_A(1) and i_B(1)) or (not i_A(1) and not i_B(1)) or (i_A(1) and not i_B(1)) or (not i_A(1) and i_B(1));
w_x2 <=(i_A(2) and i_B(2)) or (not i_A(2) and not i_B(2)) or (i_A(2) and not i_B(2)) or (not i_A(2) and i_B(2));
w_x3 <=(i_A(3) and i_B(3)) or (not i_A(3) and not i_B(3)) or (i_A(3) and not i_B(3)) or (not i_A(3) and i_B(3));
w_x4 <=(i_A(4) and i_B(4)) or (not i_A(4) and not i_B(4)) or (i_A(4) and not i_B(4)) or (not i_A(4) and i_B(4));
w_x5 <=(i_A(5) and i_B(5)) or (not i_A(5) and not i_B(5)) or (i_A(5) and not i_B(5)) or (not i_A(5) and i_B(5));
w_x6 <=(i_A(6) and i_B(6)) or (not i_A(6) and not i_B(6)) or (i_A(6) and not i_B(6)) or (not i_A(6) and i_B(6));
w_x7 <=(i_A(7) and i_B(7)) or (not i_A(7) and not i_B(7)) or (i_A(7) and not i_B(7)) or (not i_A(7) and i_B(7));

o_S <= w_x0 and w_x1 and w_x2 and w_x3 and w_x4 and w_x5 and w_x6 and w_x7;

end comp;
