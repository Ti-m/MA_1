----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/08/2015 12:36:04 PM
-- Design Name: 
-- Module Name: toggle - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity toggle is
    Port (  TXEN1_HK : in STD_LOGIC ;
            TX1_HK : in STD_LOGIC ;
            RX1_HK : out STD_LOGIC := '0'; 
            TXEN2_HK : in STD_LOGIC ;
            TX2_HK : in STD_LOGIC ;
            RX2_HK : out STD_LOGIC := '0';                    
            TXEN1_EX : out STD_LOGIC := '0';
            TX1_EX : out STD_LOGIC := '0';
            RX1_EX : in STD_LOGIC ;
            TXEN2_EX :  out STD_LOGIC := '0';
            TX2_EX :  out STD_LOGIC := '0';
            RX2_EX : in STD_LOGIC;
            R_MIX_7N : out STD_LOGIC := '0';
            R_MIX_7P : out STD_LOGIC := '0';
            R_MIX_5N : out STD_LOGIC := '0';
            R_MIX2_10P : in STD_LOGIC;
            R_MIX2_10N : in STD_LOGIC;
             IMMER_LOW : out STD_LOGIC := '0');
end toggle;

architecture Behavioral of toggle is
    

begin

--TOGGLE_OUT <= '1';
TXEN1_EX <= TXEN1_HK;
TX1_EX <= TX1_HK;
RX1_HK <= RX1_EX;

TXEN2_EX <= TXEN2_HK; --X5
TX2_EX <= TX2_HK;
RX2_HK <= RX2_EX;

R_MIX_5N <= '1';
IMMER_LOW <= '0';
R_MIX_7N <= R_MIX2_10P;
R_MIX_7P <= R_MIX2_10N;

end Behavioral;
