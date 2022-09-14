library IEEE;
use IEEE.std_logic_1164.all;

entity tb_demux2_1bit is
--empty
end tb_demux2_1bit;

architecture arch_1 of tb_demux2_1bit is

--DUT component
component demux2_1bit is
port( i_SEL : in std_logic;
      i_A : in std_logic;
      o_R : out std_logic;
      o_S : out std_logic);
end component;

signal w_SEL, w_A, w_R, w_S : std_logic;

begin
  --Connect DUT
  u_DUT: demux2_1bit port map(i_SEL => w_SEL,
                              i_A => w_A,
                              o_R => w_R,
                              o_S => w_S);
  process
  begin
    --Select output channel R
    w_SEL  <='0';
    w_A    <='0';
    wait for 1 ns;
    assert(w_R='0' and w_S='0') report "Fail @ 00" severity error;
    
    w_SEL  <='0';
    w_A    <='1';
    wait for 1 ns;
    assert(w_R='1' and w_S='0') report "Fail @ 01" severity error;
    
    -- Select output channel S
    w_SEL  <='1';
    w_A    <='0';
    wait for 1 ns;
    assert(w_R='0' and w_S='0') report "Fail @ 10" severity error;
    
    w_SEL  <='1';
    w_A    <='1';
    wait for 1 ns;
    assert(w_R='0' and w_S='1') report "Fail @ 11" severity error;
    
    -- Clear inputs
    w_SEL  <='0';
    w_A    <='0';
    assert false report "Test Done!" severity error;
    wait;
  end process;
end arch_1;
