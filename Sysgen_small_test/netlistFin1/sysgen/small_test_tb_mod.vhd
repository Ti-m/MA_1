---------------------------------------------------------------------
--
--  Package       : conv_pkg
--
--  Filename      : conv_pkg.vhd
--
--  Date          : 8/16/99
--
--  Description   : Package that defines constant values that is used in the
--                  XBS and functions that convert one type to another.
--
--  Note          : This package uses a VHDL 93 constructs therefore when
--                  compiling with ModelTech use:  vcom -93
--
---------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

package conv_pkg is
    ---------------------------------------------------------------------------
    -- Constant that tells whether we're simulating
    ---------------------------------------------------------------------------
    constant simulating : boolean := false
      -- synthesis translate_off
        or true
      -- synthesis translate_on
    ;

    ---------------------------------------------------------------------------
    -- Constants for XBS
    ---------------------------------------------------------------------------
    -- Arithmetic types
    constant xlUnsigned : integer := 1;
    constant xlSigned : integer := 2;
    constant xlFloat : integer := 3;

    -- Constants for Quantization and Overflow
    constant xlWrap : integer := 1;
    constant xlSaturate : integer := 2;
    constant xlTruncate : integer := 1;
    constant xlRound : integer := 2;
    constant xlRoundBanker : integer := 3;

    -- Constants for xladdsub s-function
    constant xlAddMode : integer := 1;
    constant xlSubMode : integer := 2;

    ---------------------------------------------------------------------------
    -- Black Box Attributes
    ---------------------------------------------------------------------------
    attribute black_box : boolean;      -- for Synplicity (obsolete)
    attribute syn_black_box : boolean;  -- for Synplicity Version 6.0
    attribute fpga_dont_touch: string;  -- for FPGA Express
    attribute box_type :  string;       -- for XST

    ---------------------------------------------------------------------------
    -- Attributes to keep clock enable signals
    ---------------------------------------------------------------------------
    attribute keep : string;
    attribute syn_keep : boolean;

    ---------------------------------------------------------------------------
    -- Arithmetic conversion functions
    ---------------------------------------------------------------------------
    -- convert a std_logic_vector to a unsigned type and vice versa
    function std_logic_vector_to_unsigned(inp : std_logic_vector) return unsigned;
    function unsigned_to_std_logic_vector(inp : unsigned) return std_logic_vector;

    -- convert a std_logic_vector to a signed type and vice versa
    function std_logic_vector_to_signed(inp : std_logic_vector) return signed;
    function signed_to_std_logic_vector(inp : signed) return std_logic_vector;
    -- convert signed to unsigned and vice versa
    function unsigned_to_signed(inp : unsigned) return signed;
    function signed_to_unsigned(inp : signed) return unsigned;
    -- Tests used in convert_type
    function pos(inp : std_logic_vector; arith : INTEGER) return boolean;
    function all_same(inp: std_logic_vector) return boolean;
    function all_zeros(inp: std_logic_vector) return boolean;
    function is_point_five(inp: std_logic_vector) return boolean;
    function all_ones(inp: std_logic_vector) return boolean;



    -- Convert a fixed point type to another fixed point type with a
    -- different bin_pt, width, and arithmetic type
    function convert_type (inp : std_logic_vector; old_width, old_bin_pt,
                           old_arith, new_width, new_bin_pt, new_arith,
                           quantization, overflow : INTEGER)
        return std_logic_vector;

    -- Cast type by zero pading or Sign extending MSB and
    -- zero pading or truncating LSB
    function cast (inp : std_logic_vector; old_bin_pt,
                   new_width, new_bin_pt, new_arith : INTEGER)
        return std_logic_vector;

    function shift_division_result(quotient, fraction: std_logic_vector;
                                   fraction_width, shift_value, shift_dir: INTEGER)
        return std_logic_vector;

    function shift_op (inp: std_logic_vector;
                       result_width, shift_value, shift_dir: INTEGER)
        return std_logic_vector;

    -- slice a vector
    function vec_slice (inp : std_logic_vector; upper, lower : INTEGER)
        return std_logic_vector;

    -- slice a signed
    function s2u_slice (inp : signed; upper, lower : INTEGER)
        return unsigned;

    -- slice a unsigned
    function u2u_slice (inp : unsigned; upper, lower : INTEGER)
        return unsigned;

    -- Cast signed to signed
    function s2s_cast (inp : signed; old_bin_pt,
                   new_width, new_bin_pt : INTEGER)
        return signed;
    -- Cast unsigned to signed
    function u2s_cast (inp : unsigned; old_bin_pt,
                   new_width, new_bin_pt : INTEGER)
        return signed;
    -- Cast signed to unsigned
    function s2u_cast (inp : signed; old_bin_pt,
                   new_width, new_bin_pt : INTEGER)
        return unsigned;
    -- Cast unsigned to unsigned
    function u2u_cast (inp : unsigned; old_bin_pt,
                   new_width, new_bin_pt : INTEGER)
        return unsigned;
    -- Cast unsigned to std_logic_vector
    function u2v_cast (inp : unsigned; old_bin_pt,
                   new_width, new_bin_pt : INTEGER)
        return std_logic_vector;
    -- Cast signed to std_logic_vector
    function s2v_cast (inp : signed; old_bin_pt,
                   new_width, new_bin_pt : INTEGER)
        return std_logic_vector;
    -- Quantization Functions
    function trunc (inp : std_logic_vector; old_width, old_bin_pt, old_arith,
                    new_width, new_bin_pt, new_arith : INTEGER)
        return std_logic_vector;
    function round_towards_inf (inp : std_logic_vector; old_width, old_bin_pt,
                                old_arith, new_width, new_bin_pt,
                                new_arith : INTEGER) return std_logic_vector;
    function round_towards_even (inp : std_logic_vector; old_width, old_bin_pt,
                                old_arith, new_width, new_bin_pt,
                                new_arith : INTEGER) return std_logic_vector;

    -- Overflow functions
    function max_signed(width : INTEGER) return std_logic_vector;
    function min_signed(width : INTEGER) return std_logic_vector;
    function saturation_arith(inp:  std_logic_vector;  old_width, old_bin_pt,
                              old_arith, new_width, new_bin_pt, new_arith
                              : INTEGER) return std_logic_vector;
    function wrap_arith(inp:  std_logic_vector;  old_width, old_bin_pt,
                        old_arith, new_width, new_bin_pt, new_arith : INTEGER)
                        return std_logic_vector;

    ---------------------------------------------------------------------------
    -- Binary point alignment functions
    ---------------------------------------------------------------------------

    -- Returns the number of fractional bits after alignment of fixed point num
    function fractional_bits(a_bin_pt, b_bin_pt: INTEGER) return INTEGER;

    -- Returns the number of integer bits after alignment of fixed point num.
    function integer_bits(a_width, a_bin_pt, b_width, b_bin_pt: INTEGER)
        return INTEGER;


    -- sign extend the MSB
    function sign_ext(inp : std_logic_vector; new_width : INTEGER)
        return std_logic_vector;

    -- zero extend the MSB
    function zero_ext(inp : std_logic_vector; new_width : INTEGER)
        return std_logic_vector;

    -- zero extend the MSB
    function zero_ext(inp : std_logic; new_width : INTEGER)
        return std_logic_vector;

    -- zero or sign extend the MSB
    function extend_MSB(inp : std_logic_vector; new_width, arith : INTEGER)
        return std_logic_vector;

    -- Align input by padding LSB with zeros and sign or zero extening
    function align_input(inp : std_logic_vector; old_width, delta, new_arith,
                          new_width: INTEGER)
        return std_logic_vector;

    -- Pad LSB with zeros
    function pad_LSB(inp : std_logic_vector; new_width: integer)
        return std_logic_vector;
    -- Pad LSB with zeros and add a zero or sign extend the MSB
    function pad_LSB(inp : std_logic_vector; new_width, arith : integer)
        return std_logic_vector;

    -- Find the max & min integer.
    function max(L, R: INTEGER) return INTEGER;
    function min(L, R: INTEGER) return INTEGER;

    -- Test is two strings are equal
    function "="(left,right: STRING) return boolean;

    -- convert a boolean into a signed
    function boolean_to_signed (inp : boolean; width: integer)
        return signed;
    -- convert a boolean into an unsigned
    function boolean_to_unsigned (inp : boolean; width: integer)
        return unsigned;
    -- convert a boolean into std_logic_vector
    function boolean_to_vector (inp : boolean)
        return std_logic_vector;
    -- convert a std_logic into std_logic_vector
    function std_logic_to_vector (inp : std_logic)
        return std_logic_vector;
    -- convert an integer into a std_logic_vector
    function integer_to_std_logic_vector (inp : integer;  width, arith : integer)
        return std_logic_vector;

    -- Convert std_logic or std_logic_vector to an integer
    function std_logic_vector_to_integer (inp : std_logic_vector;  arith : integer)
        return integer;
    function std_logic_to_integer(constant inp : std_logic := '0')
        return integer;

     -- Convert a binary string array element into a std_logic_vector
    function bin_string_element_to_std_logic_vector (inp : string;  width, index : integer)
        return std_logic_vector;
    -- convert a binary string into a std_logic_vector (e.g., 0b10.1 = 101)
    function bin_string_to_std_logic_vector (inp : string)
        return std_logic_vector;
    -- convert a hex string to a std_logic_vector
    function hex_string_to_std_logic_vector (inp : string; width : integer)
        return std_logic_vector;

    -- Make a binary string that represents zero
    function makeZeroBinStr (width : integer) return STRING;


    function and_reduce(inp: std_logic_vector) return std_logic;

    ---------------------------------------------------------------------------
    -- Debugging functions
    ---------------------------------------------------------------------------
    -- synthesis translate_off

    -- Check for all X's (i.e., 0bXX.X)
    function is_binary_string_invalid (inp : string)
        return boolean;
    -- Check for all U's (i.e., 0bUU.U)
    function is_binary_string_undefined (inp : string)
        return boolean;

    -- Check for Undefined values
    function is_XorU(inp : std_logic_vector)
        return boolean;


    -- convert a std_logic_vector to a real type and vice versa
    function to_real(inp : std_logic_vector; bin_pt : integer; arith : integer)
        return real;
    function std_logic_to_real(inp : std_logic; bin_pt : integer; arith : integer)
        return real;


    -- convert a real into a std_logic_vector
    function real_to_std_logic_vector (inp : real;  width, bin_pt, arith : integer)
        return std_logic_vector;
    -- convert a real string into a std_logic_vector
    function real_string_to_std_logic_vector (inp : string;  width, bin_pt, arith : integer)
        return std_logic_vector;

    -- display_precision is the number of digits to display in ModelTech's
    -- waveform viewer ( used in to_string(inp : real) )
    constant display_precision : integer := 20;
    -- convert a real into a string type
    function real_to_string (inp : real) return string;

    -- Check of 0b and the beginning of a string
    function valid_bin_string(inp : string) return boolean;

    -- Convert a std_logic_vector to a binary string
    function std_logic_vector_to_bin_string(inp : std_logic_vector) return string;
    -- Convert a std_logic to a binary string
    function std_logic_to_bin_string(inp : std_logic) return string;
    -- convert a std_logic_vector to a binary string and add a binary point
    function std_logic_vector_to_bin_string_w_point(inp : std_logic_vector; bin_pt : integer)
        return string;
     -- Convert a real to a binary string
    function real_to_bin_string(inp : real;  width, bin_pt, arith : integer)
        return string;

   -- convert a std_logic_vector value to a character
    type stdlogic_to_char_t is array(std_logic) of character;
    constant to_char : stdlogic_to_char_t := (
        'U' => 'U',
        'X' => 'X',
        '0' => '0',
        '1' => '1',
        'Z' => 'Z',
        'W' => 'W',
        'L' => 'L',
        'H' => 'H',
        '-' => '-');

    -- synthesis translate_on

end conv_pkg;

package body conv_pkg is

    ---------------------------------------------------------------------------
    -- Arithmetic conversion functions
    ---------------------------------------------------------------------------
    -- convert a std_logic_vector to a unsigned type
    function std_logic_vector_to_unsigned(inp : std_logic_vector)
        return unsigned
    is
    begin
        return unsigned (inp);
    end;

    -- convert an unsigend to a std_logic_vector
    function unsigned_to_std_logic_vector(inp : unsigned)
        return std_logic_vector
    is
    begin
        return std_logic_vector(inp);
    end;

    -- convert an std_logic_vector to a signed
    function std_logic_vector_to_signed(inp : std_logic_vector)
        return signed
    is
    begin
        return  signed (inp);
    end;

    -- convert an std_logic_vector to a sigend
    function signed_to_std_logic_vector(inp : signed)
        return std_logic_vector
    is
    begin
        return std_logic_vector(inp);
    end;

    -- convert unsigned to signed
    function unsigned_to_signed (inp : unsigned)
        return signed
    is
    begin  -- unsigned_to_signed
        return signed(std_logic_vector(inp));
    end;


    -- convert signed to unsigned
    function signed_to_unsigned (inp : signed)
        return unsigned
    is
    begin  -- signed_to_unsigned
        return unsigned(std_logic_vector(inp));
    end;

    -- Test if a number is positive
    function pos(inp : std_logic_vector; arith : INTEGER)
        return boolean
    is
        constant width : integer := inp'length;
        variable vec : std_logic_vector(width-1 downto 0);

    begin
        vec := inp;
        if arith = xlUnsigned then
            return true;
        else
            if vec(width-1) = '0' then
                return true;
            else
                return false;
            end if;
        end if;

        -- Error
        return true;
    end;

    function max_signed(width : INTEGER)
        return std_logic_vector
    is
        variable ones : std_logic_vector(width-2 downto 0);
        variable result : std_logic_vector(width-1 downto 0);
    begin
        ones := (others => '1');
        result(width-1) := '0';
        result(width-2 downto 0) := ones;
        return result;
    end;

    function min_signed(width : INTEGER)
        return std_logic_vector
    is
        variable zeros : std_logic_vector(width-2 downto 0);
        variable result : std_logic_vector(width-1 downto 0);
    begin
        zeros := (others => '0');
        result(width-1) := '1';
        result(width-2 downto 0) := zeros;
        return result;
    end;

    function and_reduce(inp: std_logic_vector) return std_logic
    is
        variable result: std_logic;
        constant width : integer := inp'length;
        variable vec : std_logic_vector(width-1 downto 0);
    begin
        vec := inp;
        result := vec(0);
        if width > 1 then
            for i in 1 to width-1 loop
                result := result and vec(i);
            end loop;
        end if;
        return result;
    end;


    -- Check if all the bits are the same
    function all_same(inp: std_logic_vector) return boolean
    is
        variable result: boolean;
        constant width : integer := inp'length;
        variable vec : std_logic_vector(width-1 downto 0);
    begin
        vec := inp;
        result := true;
        if width > 0 then
            for i in 1 to width-1 loop
                if vec(i) /= vec(0) then
                    result := false;
                end if;
            end loop;
        end if;
        return result;
    end;


    -- Check if a number is all zeros
    function all_zeros(inp: std_logic_vector)
        return boolean
    is
        constant width : integer := inp'length;
        variable vec : std_logic_vector(width-1 downto 0);
        variable zero : std_logic_vector(width-1 downto 0);
        variable result : boolean;
    begin
        zero := (others => '0');
        vec := inp;
        -- synthesis translate_off
        if (is_XorU(vec)) then
            return false;
        end if;
         -- synthesis translate_on

        if (std_logic_vector_to_unsigned(vec) = std_logic_vector_to_unsigned(zero)) then
            result := true;
        else
            result := false;
        end if;
        return result;
    end;

    -- Check if a number is point five
    function is_point_five(inp: std_logic_vector)
        return boolean
    is
        constant width : integer := inp'length;
        variable vec : std_logic_vector(width-1 downto 0);
        variable result : boolean;
    begin
        vec := inp;
        -- synthesis translate_off
        if (is_XorU(vec)) then
            return false;
        end if;
         -- synthesis translate_on
        if (width > 1) then
           if ((vec(width-1) = '1') and (all_zeros(vec(width-2 downto 0)) = true)) then
               result := true;
           else
               result := false;
           end if;
        else
           if (vec(width-1) = '1') then
               result := true;
           else
               result := false;
           end if;
        end if;

        return result;
    end;

    -- Check if a number is all ones
    function all_ones(inp: std_logic_vector)
        return boolean
    is
        constant width : integer := inp'length;
        variable vec : std_logic_vector(width-1 downto 0);
        variable one : std_logic_vector(width-1 downto 0);
        variable result : boolean;
    begin
        one := (others => '1');
        vec := inp;
        -- synthesis translate_off
        if (is_XorU(vec)) then
            return false;
        end if;
         -- synthesis translate_on
        if (std_logic_vector_to_unsigned(vec) = std_logic_vector_to_unsigned(one)) then
            result := true;
        else
            result := false;
        end if;
        return result;
    end;


    ---------------------------------------------------------------------------
    -- Type conersion functions
    ---------------------------------------------------------------------------


    -- Calculate the width of the temp. full precision representation
    function full_precision_num_width(quantization, overflow, old_width,
                                      old_bin_pt, old_arith,
                                      new_width, new_bin_pt, new_arith : INTEGER)
        return integer
    is
        variable result : integer;
    begin
        result := old_width + 2;
        return result;
    end;

    -- Calculate the width of the temp. quantized representation
    -- ASSUMES POSITIVE BIN_PT
    function quantized_num_width(quantization, overflow, old_width, old_bin_pt,
                                 old_arith, new_width, new_bin_pt, new_arith
                                 : INTEGER)
        return integer
    is
        variable right_of_dp, left_of_dp, result : integer;
    begin

        right_of_dp := max(new_bin_pt, old_bin_pt);
        left_of_dp := max((new_width - new_bin_pt), (old_width - old_bin_pt));

        result := (old_width + 2) + (new_bin_pt - old_bin_pt);
        return result;
    end;



    -- Convert one Fix point type to another fixed point type with a
    -- different bin_pt, width, and arithmetic type
    function convert_type (inp : std_logic_vector; old_width, old_bin_pt,
                           old_arith, new_width, new_bin_pt, new_arith,
                           quantization, overflow : INTEGER)
        return std_logic_vector
    is
        constant fp_width : integer :=
            full_precision_num_width(quantization, overflow, old_width,
                                     old_bin_pt, old_arith, new_width,
                                     new_bin_pt, new_arith);
        constant fp_bin_pt : integer := old_bin_pt;
        constant fp_arith : integer := old_arith;
        variable full_precision_result : std_logic_vector(fp_width-1 downto 0);

        constant q_width : integer :=
            quantized_num_width(quantization, overflow, old_width, old_bin_pt,
                                old_arith, new_width, new_bin_pt, new_arith);
        constant q_bin_pt : integer := new_bin_pt;
        constant q_arith : integer := old_arith;
        variable quantized_result : std_logic_vector(q_width-1 downto 0);

        variable result : std_logic_vector(new_width-1 downto 0);
    begin
        result := (others => '0');

        full_precision_result := cast(inp, old_bin_pt, fp_width, fp_bin_pt,
                                      fp_arith);

        -- Apply quantization functions.  This will remove LSB bits.
        if (quantization = xlRound) then

            quantized_result := round_towards_inf(full_precision_result,
                                                  fp_width, fp_bin_pt,
                                                  fp_arith, q_width, q_bin_pt,
                                                  q_arith);
        elsif (quantization = xlRoundBanker) then
            quantized_result := round_towards_even(full_precision_result,
                                                  fp_width, fp_bin_pt,
                                                  fp_arith, q_width, q_bin_pt,
                                                  q_arith);
        else
            quantized_result := trunc(full_precision_result, fp_width, fp_bin_pt,
                                      fp_arith, q_width, q_bin_pt, q_arith);
        end if;


        -- Apply overflow function.  This will remove MSB bits.
        if (overflow = xlSaturate) then
            result := saturation_arith(quantized_result, q_width, q_bin_pt,
                                       q_arith, new_width, new_bin_pt, new_arith);
        else
             result := wrap_arith(quantized_result, q_width, q_bin_pt, q_arith,
                                  new_width, new_bin_pt, new_arith);
        end if;


        return result;
    end;

    -- Cast type by zero pading or Sign extending MSB and
    -- zero pading or truncating LSB
    function cast (inp : std_logic_vector; old_bin_pt, new_width,
                   new_bin_pt, new_arith : INTEGER)
        return std_logic_vector
    is
        constant old_width : integer := inp'length;
        -- Number of digits to add/subract to the left of the decimal point
        constant left_of_dp : integer := (new_width - new_bin_pt)
                                         - (old_width - old_bin_pt);
        -- Number of digits to add/subract to the right of the decimal point
        constant right_of_dp : integer := (new_bin_pt - old_bin_pt);

        variable vec : std_logic_vector(old_width-1 downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
        variable j   : integer;

    begin
        vec := inp;
        for i in new_width-1 downto 0 loop
            j := i - right_of_dp;
            if ( j > old_width-1) then
                -- Bits to the left of the decimal point
                if (new_arith = xlUnsigned) then
                    -- If unsigned zero pad MSB
                    result(i) := '0';
                else
                    -- If signed, sign extend MSB
                    result(i) := vec(old_width-1);
                end if;
            elsif ( j >= 0) then 
                -- Copy bits from input
                result(i) := vec(j);
            else
                -- zero pad LSB
                result(i) := '0';
            end if;
        end loop;

        return result;
    end;

    function shift_division_result(quotient, fraction: std_logic_vector;
                                   fraction_width, shift_value, shift_dir: INTEGER)
        return std_logic_vector
    is
        constant q_width : integer := quotient'length;
        constant f_width : integer := fraction'length;
        constant vec_MSB : integer := q_width+f_width-1;
        constant result_MSB : integer := q_width+fraction_width-1;
        constant result_LSB : integer := vec_MSB-result_MSB;
        variable vec : std_logic_vector(vec_MSB downto 0);
        variable result : std_logic_vector(result_MSB downto 0);
    begin
        vec := ( quotient & fraction );
        if shift_dir = 1 then
            for i in vec_MSB downto 0 loop
                if (i < shift_value) then
                     vec(i) := '0';
                else
                    vec(i) := vec(i-shift_value);
                end if;
            end loop;
            --vec := vec sll shift_value;
        else
            for i in 0 to vec_MSB loop
                if (i > vec_MSB-shift_value) then
                    vec(i) := vec(vec_MSB);
                else
                    vec(i) := vec(i+shift_value);
                end if;
            end loop;
            --vec := vec srl shift_value;
        end if;
        result := vec(vec_MSB downto result_LSB);
        return result;
    end;


    function shift_op (inp: std_logic_vector;
                       result_width, shift_value, shift_dir: INTEGER)
        return std_logic_vector
    is
        constant inp_width : integer := inp'length;
        constant vec_MSB : integer := inp_width-1;
        constant result_MSB : integer := result_width-1;
        constant result_LSB : integer := vec_MSB-result_MSB;
        variable vec : std_logic_vector(vec_MSB downto 0);
        variable result : std_logic_vector(result_MSB downto 0);
    begin
        vec := inp;
        if shift_dir = 1 then
            for i in vec_MSB downto 0 loop
                if (i < shift_value) then
                     vec(i) := '0';
                else
                    vec(i) := vec(i-shift_value);
                end if;
            end loop;
            --vec := vec sll shift_value;
        else
            for i in 0 to vec_MSB loop
                if (i > vec_MSB-shift_value) then
                    vec(i) := vec(vec_MSB);
                else
                    vec(i) := vec(i+shift_value);
                end if;
            end loop;
            --vec := vec srl shift_value;
        end if;
        result := vec(vec_MSB downto result_LSB);
        return result;
    end;


    -- vector slice
    function vec_slice (inp : std_logic_vector; upper, lower : INTEGER)
      return std_logic_vector
    is
    begin
        return inp(upper downto lower);
    end;

    -- signed slice
    function s2u_slice (inp : signed; upper, lower : INTEGER)
      return unsigned
    is
    begin
        return unsigned(vec_slice(std_logic_vector(inp), upper, lower));
    end;

    -- unsigned slice
    function u2u_slice (inp : unsigned; upper, lower : INTEGER)
      return unsigned
    is
    begin
        return unsigned(vec_slice(std_logic_vector(inp), upper, lower));
    end;

    -- Cast signed to signed
    function s2s_cast (inp : signed; old_bin_pt, new_width, new_bin_pt : INTEGER)
        return signed
    is
    begin
        return signed(cast(std_logic_vector(inp), old_bin_pt, new_width, new_bin_pt, xlSigned));
    end;

    -- Cast signed to unsigned
    function s2u_cast (inp : signed; old_bin_pt, new_width,
                   new_bin_pt : INTEGER)
        return unsigned
    is
    begin
        return unsigned(cast(std_logic_vector(inp), old_bin_pt, new_width, new_bin_pt, xlSigned));
    end;

    -- Cast unsigned to signed
    function u2s_cast (inp : unsigned; old_bin_pt, new_width,
                   new_bin_pt : INTEGER)
        return signed
    is
    begin
        return signed(cast(std_logic_vector(inp), old_bin_pt, new_width, new_bin_pt, xlUnsigned));
    end;

    -- Cast unsigned to unsigned
    function u2u_cast (inp : unsigned; old_bin_pt, new_width,
                   new_bin_pt : INTEGER)
        return unsigned
    is
    begin
        return unsigned(cast(std_logic_vector(inp), old_bin_pt, new_width, new_bin_pt, xlUnsigned));
    end;

    -- Cast unsigned to std_logic_vector
    function u2v_cast (inp : unsigned; old_bin_pt, new_width,
                   new_bin_pt : INTEGER)
        return std_logic_vector
    is
    begin
        return cast(std_logic_vector(inp), old_bin_pt, new_width, new_bin_pt, xlUnsigned);
    end;

    -- Cast signed to std_logic_vector
    function s2v_cast (inp : signed; old_bin_pt, new_width,
                   new_bin_pt : INTEGER)
        return std_logic_vector
    is
    begin
        return cast(std_logic_vector(inp), old_bin_pt, new_width, new_bin_pt, xlSigned);
    end;

    function boolean_to_signed (inp : boolean; width : integer)
        return signed
    is
        variable result : signed(width - 1 downto 0);
    begin
        result := (others => '0');
        if inp then
          result(0) := '1';
        else
          result(0) := '0';
        end if;
        return result;
    end;

    function boolean_to_unsigned (inp : boolean; width : integer)
        return unsigned
    is
        variable result : unsigned(width - 1 downto 0);
    begin
        result := (others => '0');
        if inp then
          result(0) := '1';
        else
          result(0) := '0';
        end if;
        return result;
    end;

    function boolean_to_vector (inp : boolean)
        return std_logic_vector
    is
        variable result : std_logic_vector(1 - 1 downto 0);
    begin
        result := (others => '0');
        if inp then
          result(0) := '1';
        else
          result(0) := '0';
        end if;
        return result;
    end;

    function std_logic_to_vector (inp : std_logic)
        return std_logic_vector
    is
        variable result : std_logic_vector(1 - 1 downto 0);
    begin
        result(0) := inp;
        return result;
    end;

    ---------------------------------------------------------------------------
    -- Quantization Functions
    ---------------------------------------------------------------------------

    -- Truncate LSB bits
    function trunc (inp : std_logic_vector; old_width, old_bin_pt, old_arith,
                                new_width, new_bin_pt, new_arith : INTEGER)
        return std_logic_vector
    is
        -- Number of binary digits to add/subract to the right of the decimal
        -- point
        constant right_of_dp : integer := (old_bin_pt - new_bin_pt);
        variable vec : std_logic_vector(old_width-1 downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
    begin
        vec := inp;

        if right_of_dp >= 0 then
            -- Sign Extent or zero extend if necessary
            if new_arith = xlUnsigned then
                result := zero_ext(vec(old_width-1 downto right_of_dp), new_width);
            else
                result := sign_ext(vec(old_width-1 downto right_of_dp), new_width);
            end if;
        else
            -- Pad LSB with zeros and sign extend by one bit
            if new_arith = xlUnsigned then
                result := zero_ext(pad_LSB(vec, old_width +
                                           abs(right_of_dp)), new_width);
            else
                result := sign_ext(pad_LSB(vec, old_width +
                                           abs(right_of_dp)), new_width);
            end if;
        end if;
        return result;
    end;


    -- Round towards infinity
    function round_towards_inf (inp : std_logic_vector; old_width, old_bin_pt,
                                old_arith, new_width, new_bin_pt, new_arith
                                : INTEGER)
        return std_logic_vector
    is
        -- Number of binary digits to add/subract to the right of the decimal
        -- point
        constant right_of_dp : integer := (old_bin_pt - new_bin_pt);

        constant expected_new_width : integer :=  old_width - right_of_dp  + 1;
        variable vec : std_logic_vector(old_width-1 downto 0);
        variable one_or_zero : std_logic_vector(new_width-1 downto 0);
        variable truncated_val : std_logic_vector(new_width-1 downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
    begin
        vec := inp;


        if right_of_dp >= 0 then
            -- Sign extend or zero extend to size of output
            if new_arith = xlUnsigned then
                truncated_val := zero_ext(vec(old_width-1 downto right_of_dp),
                                          new_width);
            else
                truncated_val := sign_ext(vec(old_width-1 downto right_of_dp),
                                          new_width);
            end if;
        else
            -- Pad LSB with zeros and sign extend by one bit
            if new_arith = xlUnsigned then
                truncated_val := zero_ext(pad_LSB(vec, old_width +
                                                  abs(right_of_dp)), new_width);
            else
                truncated_val := sign_ext(pad_LSB(vec, old_width +
                                                  abs(right_of_dp)), new_width);
            end if;
        end if;


        -- Figure out if '1' should be added to the truncated number
        one_or_zero := (others => '0');

        if (new_arith = xlSigned) then
            -- Roundeing logic for signed numbers
            --   Example:
            --                 Fix(5,-2) = 101.11 (bin) -2.25 (dec)
            --   Converted to: Fix(4,-1) = 101.1  (bin) -2.5  (dec)
            --   Note: same algorithm used for unsigned numbers can't be used.

            -- 1st check the sign bit of the input to see if it is a positive
            -- number
            if (vec(old_width-1) = '0') then
                one_or_zero(0) := '1';
            end if;

            -- 2nd check if digits being truncated are all zeros
            --  (in example it is bit zero)
            if (right_of_dp >= 2) and (right_of_dp <= old_width) then
                if (all_zeros(vec(right_of_dp-2 downto 0)) = false) then
                    one_or_zero(0) := '1';
                end if;
            end if;

            -- 3rd check if the bit right before the truncation point is '1'
            -- or '0' (in example it is bit one)
            if (right_of_dp >= 1) and (right_of_dp <= old_width) then
                if vec(right_of_dp-1) = '0' then
                    one_or_zero(0) := '0';
                end if;
            else
                -- No rounding to be performed
                one_or_zero(0) := '0';
            end if;
        else
            -- For an unsigned number just check if the bit right before the
            -- truncation point is '1' or '0'
            if (right_of_dp >= 1) and (right_of_dp <= old_width) then
                one_or_zero(0) :=  vec(right_of_dp-1);
            end if;
        end if;


        if new_arith = xlSigned then
            result := signed_to_std_logic_vector(std_logic_vector_to_signed(truncated_val) +
                                                 std_logic_vector_to_signed(one_or_zero));
        else
            result := unsigned_to_std_logic_vector(std_logic_vector_to_unsigned(truncated_val) +
                                                  std_logic_vector_to_unsigned(one_or_zero));
        end if;

        return result;
    end;

    -- Round towards even values
    function round_towards_even (inp : std_logic_vector; old_width, old_bin_pt,
                                old_arith, new_width, new_bin_pt, new_arith
                                : INTEGER)
        return std_logic_vector
    is
        -- Number of binary digits to add/subract to the right of the decimal
        -- point
        constant right_of_dp : integer := (old_bin_pt - new_bin_pt);

        constant expected_new_width : integer :=  old_width - right_of_dp  + 1;
        variable vec : std_logic_vector(old_width-1 downto 0);
        variable one_or_zero : std_logic_vector(new_width-1 downto 0);
        variable truncated_val : std_logic_vector(new_width-1 downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
    begin
        vec := inp;

        if right_of_dp >= 0 then
            -- Sign extend or zero extend to size of output
            if new_arith = xlUnsigned then
                truncated_val := zero_ext(vec(old_width-1 downto right_of_dp),
                                          new_width);
            else
                truncated_val := sign_ext(vec(old_width-1 downto right_of_dp),
                                          new_width);
            end if;

        else
            -- Pad LSB with zeros and sign extend by one bit
            if new_arith = xlUnsigned then
                truncated_val := zero_ext(pad_LSB(vec, old_width +
                                                  abs(right_of_dp)), new_width);
            else
                truncated_val := sign_ext(pad_LSB(vec, old_width +
                                                  abs(right_of_dp)), new_width);
            end if;
        end if;

        -- Figure out if '1' should be added to the truncated number
        one_or_zero := (others => '0');

        -- For the truncated bits just check if the bits after the
        -- truncation point are 0.5
        if (right_of_dp >= 1) and (right_of_dp <= old_width) then
            if (is_point_five(vec(right_of_dp-1 downto 0)) = false) then
                one_or_zero(0) :=  vec(right_of_dp-1);
            else
                one_or_zero(0) :=  vec(right_of_dp);
            end if;
        end if;

        if new_arith = xlSigned then
            result := signed_to_std_logic_vector(std_logic_vector_to_signed(truncated_val) +
                                                 std_logic_vector_to_signed(one_or_zero));
        else
            result := unsigned_to_std_logic_vector(std_logic_vector_to_unsigned(truncated_val) +
                                                  std_logic_vector_to_unsigned(one_or_zero));
        end if;

        return result;
    end;

    ---------------------------------------------------------------------------
    -- Overflow Functions
    ---------------------------------------------------------------------------

    -- Apply Saturation arithmetic.  The new_bin_pt and old bin_pt should be
    -- equal. The function chops bits off MSB bits.
    function saturation_arith(inp:  std_logic_vector;  old_width, old_bin_pt,
                              old_arith, new_width, new_bin_pt, new_arith
                              : INTEGER)
        return std_logic_vector
    is
        -- Number of digits to add/subract to the left of the decimal point
        constant left_of_dp : integer := (old_width - old_bin_pt) -
                                         (new_width - new_bin_pt);
        variable vec : std_logic_vector(old_width-1 downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
        variable overflow : boolean;
    begin
        vec := inp;
        overflow := true;
        result := (others => '0');

        -----------------------------------------------------------------------
        -- Check for cases when overflow does not occur
        -----------------------------------------------------------------------

        -- Output width is >= input width
        if (new_width >= old_width) then
            overflow := false;
        end if;

        -- Case #1:
        -- Both the input and output are signed and the bits that will
        -- be truncated plus the sign bit are all the same
        -- (i.e., number has been sign extended)
        if ((old_arith = xlSigned and new_arith = xlSigned) and (old_width > new_width)) then
            if all_same(vec(old_width-1 downto new_width-1)) then
                overflow := false;
            end if;
        end if;

        -- Case #2:
        -- If the input is converted to a unsigned from an signed then only
        -- check the bits that will be truncated are all zero
        if (old_arith = xlSigned and new_arith = xlUnsigned) then
            if (old_width > new_width) then
                if all_zeros(vec(old_width-1 downto new_width)) then
                    overflow := false;
                end if;
            else
                if (old_width = new_width) then
                    -- Check if input is positive
                    if (vec(new_width-1) = '0') then
                        overflow := false;
                    end if;
                end if;
            end if;
        end if;

        -- Case #3:
        -- Input is unsigned and the bits that will be truncated are all zero
        if (old_arith = xlUnsigned and new_arith = xlUnsigned) then
            if (old_width > new_width) then
                if all_zeros(vec(old_width-1 downto new_width)) then
                    overflow := false;
                end if;
            else
                if (old_width = new_width) then
                    overflow := false;
                end if;
            end if;
        end if;

        -- Case #4:
        -- Input is unsigned but output signed and the bits that will be
        -- truncated are all zero
        if ((old_arith = xlUnsigned and new_arith = xlSigned) and (old_width > new_width)) then
            if all_same(vec(old_width-1 downto new_width-1)) then
                overflow := false;
            end if;
        end if;


        if overflow then
            -- Overflow occured
            if new_arith = xlSigned then
                -- Check sign bit and set to max signed or min signed value
                if vec(old_width-1) = '0' then
                    result := max_signed(new_width);
                else
                    result := min_signed(new_width);
                end if;
            else
                -- Check sign bit and set to zero if negative
                if ((old_arith = xlSigned) and vec(old_width-1) = '1') then
                    result := (others => '0');
                else
                    -- Set to max unsigned positive value
                    result := (others => '1');
                end if;
            end if;
        else
            -- Overflow did not occur

            -- Check for case when input type is signed and output type
            -- unsigned
            if (old_arith = xlSigned) and (new_arith = xlUnsigned) then
                -- if negative number set vec to zero
                if (vec(old_width-1) = '1') then
                    vec := (others => '0');
                end if;
            end if;

            if new_width <= old_width then
                result := vec(new_width-1 downto 0);
            else
                -- Sign or zero extend number depending on arith of new number
                if new_arith = xlUnsigned then
                    result := zero_ext(vec, new_width);
                else
                    result := sign_ext(vec, new_width);
                end if;

            end if;
        end if;

        return result;
    end;

   function wrap_arith(inp:  std_logic_vector;  old_width, old_bin_pt,
                       old_arith, new_width, new_bin_pt, new_arith : INTEGER)
        return std_logic_vector
    is
        variable result : std_logic_vector(new_width-1 downto 0);
        variable result_arith : integer;
    begin
        -- Check for case when input type is signed and output type unsigned
        if (old_arith = xlSigned) and (new_arith = xlUnsigned) then
            result_arith := xlSigned;
        end if;

        result := cast(inp, old_bin_pt, new_width, new_bin_pt, result_arith);

        return result;
    end;


    -- Returns the number of fractional bits after alignment of fixed point num
    function fractional_bits(a_bin_pt, b_bin_pt: INTEGER) return INTEGER is
    begin
        return max(a_bin_pt, b_bin_pt);
    end;

    -- Returns the number of integer bits after alignment of fixed point num
    function integer_bits(a_width, a_bin_pt, b_width, b_bin_pt: INTEGER)
        return INTEGER is
    begin
        return  max(a_width - a_bin_pt, b_width - b_bin_pt);
    end;

    function pad_LSB(inp : std_logic_vector; new_width: integer)
        return STD_LOGIC_VECTOR
    is
        constant orig_width : integer := inp'length;
        variable vec : std_logic_vector(orig_width-1 downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
        variable pos : integer;
        -- Added for XST
        constant pad_pos : integer := new_width - orig_width - 1;

    begin
        vec := inp;
        pos := new_width-1;
        if (new_width >= orig_width) then
            for i in orig_width-1 downto 0 loop
                result(pos) := vec(i);
                pos := pos - 1;
            end loop;
            if pad_pos >= 0 then
                for i in pad_pos downto 0 loop
                    result(i) := '0';
                end loop;
            end if;
        end if;

        return result;
    end;


      -- sign extend the MSB
    function sign_ext(inp : std_logic_vector; new_width : INTEGER)
        return std_logic_vector
    is
        constant old_width : integer := inp'length;
        variable vec : std_logic_vector(old_width-1 downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
    begin
        vec := inp;
         -- sign extend
        if new_width >= old_width then
            result(old_width-1 downto 0) := vec;
            if new_width-1 >= old_width then
                for i in new_width-1 downto old_width loop
                    result(i) := vec(old_width-1);
                end loop;
            end if;
        else
            result(new_width-1 downto 0) := vec(new_width-1 downto 0);
        end if;

        return result;
    end;



    -- zero extend the MSB
    function zero_ext(inp : std_logic_vector; new_width : INTEGER)
        return std_logic_vector
    is
        constant old_width : integer := inp'length;
        variable vec : std_logic_vector(old_width-1 downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
    begin
        vec := inp;

        -- zero extend
        if new_width >= old_width then
            result(old_width-1 downto 0) := vec;
            if new_width-1 >= old_width then
                for i in new_width-1 downto old_width loop
                    result(i) := '0';
                end loop;
            end if;
        else
            result(new_width-1 downto 0) := vec(new_width-1 downto 0);
        end if;

        return result;
    end;

    -- zero extend the MSB
    function zero_ext(inp : std_logic; new_width : INTEGER)
        return std_logic_vector
    is
        variable result : std_logic_vector(new_width-1 downto 0);
    begin
        result(0) := inp;
        for i in new_width-1 downto 1 loop
            result(i) := '0';
        end loop;

        return result;
    end;

    -- zero or sign extend the MSB
    function extend_MSB(inp : std_logic_vector; new_width, arith : INTEGER)
        return std_logic_vector
    is
        constant orig_width : integer := inp'length;
        variable vec : std_logic_vector(orig_width-1 downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
    begin
        vec := inp;

        if arith = xlUnsigned then
            result := zero_ext(vec, new_width);
        else
            result := sign_ext(vec, new_width);
        end if;

        return result;
    end;

    -- Pad LSB with zeros and add a zero or sign extend the MSB
    function pad_LSB(inp : std_logic_vector; new_width, arith: integer)
        return STD_LOGIC_VECTOR
    is
        constant orig_width : integer := inp'length;
        variable vec : std_logic_vector(orig_width-1 downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
        variable pos : integer;
    begin
        vec := inp;
        pos := new_width-1;

        if (arith = xlUnsigned) then
            -- set MSB to zero
            result(pos) := '0';
            pos := pos - 1;
        else
            -- sign extend
            result(pos) := vec(orig_width-1);
            pos := pos - 1;
        end if;

        if (new_width >= orig_width) then
            for i in orig_width-1 downto 0 loop
                result(pos) := vec(i);
                pos := pos - 1;
            end loop;
            if pos >= 0 then
                for i in pos downto 0 loop
                    result(i) := '0';
                end loop;
            end if;
        end if;

        return result;
    end;

    -- Align input by padding LSB with zeros and sign or zero extening
    function align_input(inp : std_logic_vector; old_width, delta, new_arith,
                         new_width: INTEGER)
        return std_logic_vector
    is
        variable vec : std_logic_vector(old_width-1 downto 0);
        variable padded_inp : std_logic_vector((old_width + delta)-1  downto 0);
        variable result : std_logic_vector(new_width-1 downto 0);
    begin
        vec := inp;

        if delta > 0 then
            padded_inp := pad_LSB(vec, old_width+delta);

            -- sign or zero extend zero padded input depending on arith type
            result := extend_MSB(padded_inp, new_width, new_arith);
        else
            -- sign or zero extend input depending on arith type
            result := extend_MSB(vec, new_width, new_arith);
        end if;

        return result;
    end;

    function max(L, R: INTEGER) return INTEGER is
    begin
        if L > R then
            return L;
        else
            return R;
        end if;
    end;

    function min(L, R: INTEGER) return INTEGER is
    begin
        if L < R then
            return L;
        else
            return R;
        end if;
    end;

    -- Test is two strings are equal
    function "="(left,right: STRING) return boolean is
--      constant NULL_Str : string := "";
    begin
        if (left'length /= right'length) then
            return false;
        else
            -- Check for NULL string
            -- FPGA Express does not like empty strings
--          if (left'length = NULL_Str'length) or
--              (right'length = NULL_Str'length) then
--              return true;
--          end if;
            test : for i in 1 to left'length loop
                if left(i) /= right(i) then
                    return false;
                end if;
            end loop test;
            return true;
        end if;
    end;


    ---------------------------------------------------------------------------
    -- Debugging and Simulation only functions
    ---------------------------------------------------------------------------
    -- synthesis translate_off

    -- Check for all X's
    function is_binary_string_invalid (inp : string)
        return boolean
    is
        variable vec : string(1 to inp'length);
        variable result : boolean;
    begin
        vec := inp;
        result := false;

        for i in 1 to vec'length loop
            if ( vec(i) = 'X' ) then
                result := true;
            end if;
        end loop;
        return result;
    end;

    -- Check for all U's
    function is_binary_string_undefined (inp : string)
        return boolean
    is
        variable vec : string(1 to inp'length);
        variable result : boolean;
    begin
        vec := inp;
        result := false;

        for i in 1 to vec'length loop
            if ( vec(i) = 'U' ) then
                result := true;
            end if;
        end loop;
        return result;
    end;




    -- Check for Undefined values
    function is_XorU(inp : std_logic_vector)
        return boolean
    is
        constant width : integer := inp'length;
        variable vec : std_logic_vector(width-1 downto 0);
        variable result : boolean;
    begin
        vec := inp;
        result := false;
        for i in 0 to width-1 loop
            if (vec(i) = 'U') or (vec(i) = 'X') then
                result := true;
            end if;
        end loop;
        return result;
    end;

    -- Converts a std_logic_vector to a real
    function to_real(inp : std_logic_vector; bin_pt : integer; arith : integer)
        return real
    is
        variable  vec : std_logic_vector(inp'length-1 downto 0);
        variable result, shift_val, undefined_real : real;
        variable neg_num : boolean;
    begin
        vec := inp;
        result := 0.0;
        neg_num := false;
        if vec(inp'length-1) = '1' then
            neg_num := true;
        end if;

        for i in 0 to inp'length-1 loop
            if  vec(i) = 'U' or vec(i) = 'X' then
                return undefined_real;
            end if;
            if arith = xlSigned then
                if neg_num then
                    --  Perform 1's count if negative number
                    if vec(i) = '0' then
                        result := result + 2.0**i;
                    end if;
                else
                    if vec(i) = '1' then
                        result := result + 2.0**i;
                    end if;
                end if;
            else
                -- Unsigned numbers
                if vec(i) = '1' then
                    result := result + 2.0**i;
                end if;
            end if;
        end loop;

        if arith = xlSigned then
            if neg_num then
                -- Add one to 1's comp number to make 2's comp number
                result := result + 1.0;
                result := result * (-1.0);
            end if;
        end if;
        -- Realign based on binary point
        shift_val := 2.0**(-1*bin_pt);
        result := result * shift_val;
        return result;
    end;

    -- This function is just for consistancy
    -- bin_pt and arith not used.
    function std_logic_to_real(inp : std_logic; bin_pt : integer; arith : integer)
        return real
    is
        variable result : real := 0.0;
    begin
        if inp = '1' then
            result := 1.0;
        end if;

        if arith = xlSigned then
            assert false
                report "It doesn't make sense to convert a 1 bit number to a signed real.";
        end if;
        return result;
    end;

    -- synthesis translate_on
    -- Convert an integer into a std_logic_vector
    function integer_to_std_logic_vector (inp : integer;  width, arith : integer)
        return std_logic_vector
    is
        variable result : std_logic_vector(width-1 downto 0);
        variable unsigned_val : unsigned(width-1 downto 0);
        variable signed_val : signed(width-1 downto 0);
    begin

        if (arith = xlSigned) then
            signed_val := to_signed(inp, width);
            result := signed_to_std_logic_vector(signed_val);
        else
            unsigned_val := to_unsigned(inp, width);
            result := unsigned_to_std_logic_vector(unsigned_val);
        end if;

        return result;
    end;


    -- Convert an std_logic or std_logic_vector to an integer
    function std_logic_vector_to_integer (inp : std_logic_vector;  arith : integer)
        return integer
    is
        constant width : integer := inp'length;
        variable unsigned_val : unsigned(width-1 downto 0);
        variable signed_val : signed(width-1 downto 0);
        variable result : integer;
    begin

        if (arith = xlSigned) then
            signed_val := std_logic_vector_to_signed(inp);
            result := to_integer(signed_val);
        else
            unsigned_val := std_logic_vector_to_unsigned(inp);
            result := to_integer(unsigned_val);
        end if;

        return result;
    end;

    function std_logic_to_integer(constant inp : std_logic := '0')
        return integer
    is
    begin
        if inp = '1' then
            return 1;
        else
            return 0;
        end if;
    end;


    function makeZeroBinStr (width : integer) return STRING is
        variable result : string(1 to width+3);
    begin
        result(1) := '0';
        result(2) := 'b';
        for i in 3 to width+2 loop
            result(i) := '0';
        end loop;  -- i
        result(width+3) := '.';

        return result;
    end;



    -- synthesis translate_off
    -- Convert a real string into a std_logic_vector
    function real_string_to_std_logic_vector (inp : string;  width, bin_pt, arith : integer)
        return std_logic_vector
    is
        variable result : std_logic_vector(width-1 downto 0);
    begin
        --result := to_std_logic_vector(real'value(inp), width, bin_pt, arith);
        result := (others => '0');
        return result;
    end;

    -- Convert a real into a std_logic_vector
    function real_to_std_logic_vector (inp : real;  width, bin_pt, arith : integer)
        return std_logic_vector
    is
        variable real_val : real;
        variable int_val : integer;
        variable result : std_logic_vector(width-1 downto 0) := (others => '0');
        variable unsigned_val : unsigned(width-1 downto 0) := (others => '0');
        variable signed_val : signed(width-1 downto 0) := (others => '0');
    begin

        real_val := inp;

        -- Scale double and make it an integer
        int_val := integer(real_val * 2.0**(bin_pt));

        if (arith = xlSigned) then
            signed_val := to_signed(int_val, width);
            result := signed_to_std_logic_vector(signed_val);
        else
            unsigned_val := to_unsigned(int_val, width);
            result := unsigned_to_std_logic_vector(unsigned_val);
        end if;

        return result;
    end;


    -- synthesis translate_on
       -- Check of 0b and the beginning of a string
    function valid_bin_string (inp : string)
        return boolean
    is
        variable vec : string(1 to inp'length);
    begin
        vec := inp;
        if (vec(1) = '0' and vec(2) = 'b') then
            return true;
        else
            return false;
        end if;
    end;

    -- convert a hex string to a std_logic_vector
    function hex_string_to_std_logic_vector(inp: string; width : integer)
        return std_logic_vector is

        constant strlen       : integer := inp'LENGTH;
        variable result       : std_logic_vector(width-1 downto 0);
        variable bitval       : std_logic_vector((strlen*4)-1 downto 0);
        variable posn         : integer;
        variable ch           : character;
        variable vec          : string(1 to strlen);
    begin
        vec := inp;

        -- default value is zero
        result := (others => '0');
        posn := (strlen*4)-1;

        for i in 1 to strlen loop
            ch := vec(i);
            case ch is
                when '0' => bitval(posn downto posn-3) := "0000";
                when '1' => bitval(posn downto posn-3) := "0001";
                when '2' => bitval(posn downto posn-3) := "0010";
                when '3' => bitval(posn downto posn-3) := "0011";
                when '4' => bitval(posn downto posn-3) := "0100";
                when '5' => bitval(posn downto posn-3) := "0101";
                when '6' => bitval(posn downto posn-3) := "0110";
                when '7' => bitval(posn downto posn-3) := "0111";
                when '8' => bitval(posn downto posn-3) := "1000";
                when '9' => bitval(posn downto posn-3) := "1001";
                when 'A' | 'a' => bitval(posn downto posn-3) := "1010";
                when 'B' | 'b' => bitval(posn downto posn-3) := "1011";
                when 'C' | 'c' => bitval(posn downto posn-3) := "1100";
                when 'D' | 'd' => bitval(posn downto posn-3) := "1101";
                when 'E' | 'e' => bitval(posn downto posn-3) := "1110";
                when 'F' | 'f' => bitval(posn downto posn-3) := "1111";
                when others => bitval(posn downto posn-3) := "XXXX";
                               -- synthesis translate_off
                               ASSERT false
                                   REPORT "Invalid hex value" SEVERITY ERROR;
                               -- synthesis translate_on
            end case;
            posn := posn - 4;
        end loop;

        if (width <= strlen*4) then
            -- bitval larger than desired width
            result :=  bitval(width-1 downto 0);
        else
            -- bitval smaller than desired width
            -- MSB is padded with zeros since default value for result is all 0s
            result((strlen*4)-1 downto 0) := bitval;
        end if;
        return result;
    end;


    -- convert a binary string into a std_logic_vector (e.g., 0b10.1 = 101)
    function bin_string_to_std_logic_vector (inp : string)
        return std_logic_vector
    is
        variable pos : integer;
        variable vec : string(1 to inp'length);
        variable result : std_logic_vector(inp'length-1 downto 0);
    begin
        vec := inp;
        pos := inp'length-1;
        -- Set default value
        result := (others => '0');

        for i in 1 to vec'length loop
            -- synthesis translate_off
            if (pos < 0) and (vec(i) = '0' or vec(i) = '1' or vec(i) = 'X' or vec(i) = 'U')  then
                assert false
                    report "Input string is larger than output std_logic_vector. Truncating output.";
                return result;
            end if;
            -- synthesis translate_on

            if vec(i) = '0' then
                result(pos) := '0';
                pos := pos - 1;
            end if;
            if vec(i) = '1' then
                result(pos) := '1';
                pos := pos - 1;
            end if;
            -- synthesis translate_off
            if (vec(i) = 'X' or vec(i) = 'U') then
                result(pos) := 'U';
                pos := pos - 1;
            end if;
            -- synthesis translate_on
        end loop;
        return result;
    end;


    -- Convert a binary string array element into a std_logic_vector
    -- Example    "0b000.0000000 0b001.0000000"
    -- string_pos: 123456789111111111122222222
    --                      012345678901234567
    --
    --         "0b000.0000000" = inp(0)
    --         "0b001.0000000" = inp(1)
    function bin_string_element_to_std_logic_vector (inp : string;  width, index : integer)
        return std_logic_vector
    is
        constant str_width : integer := width + 4;  -- +4 for '0b' '.' & ' '
        constant inp_len : integer := inp'length;
        constant num_elements : integer := (inp_len + 1)/str_width;
        constant reverse_index : integer := (num_elements-1) - index;

        -- Calc position of desired str
        variable left_pos : integer;
        variable right_pos : integer;
        variable vec : string(1 to inp'length);
        variable result : std_logic_vector(width-1 downto 0);
    begin
        -- Can't pad input with a space (Synplicity crashes)
        vec := inp;

        -- Set default value
        result := (others => '0');

        -- Special Case for string like "0b01.0" without extra ' ' after string
        if (reverse_index = 0) and (reverse_index < num_elements) and (inp_len-3 >= width) then
            left_pos := 1;
            right_pos := width + 3;
            result := bin_string_to_std_logic_vector(vec(left_pos to right_pos));
        end if;

        if (reverse_index > 0) and (reverse_index < num_elements) and (inp_len-3 >= width) then
            left_pos := (reverse_index * str_width) + 1;
            right_pos := left_pos + width + 2;
            result := bin_string_to_std_logic_vector(vec(left_pos to right_pos));
        end if;

        return result;
    end;
   -- synthesis translate_off

    --
    -- convert a std_logic_vector to a string
    --
    function std_logic_vector_to_bin_string(inp : std_logic_vector)
        return string
    is
        variable vec : std_logic_vector(1 to inp'length);
        variable result : string(vec'range);
    begin
        vec := inp;
        for i in vec'range loop
            result(i) := to_char(vec(i));
        end loop;
        return result;
    end;

    --
    -- convert a std_logic to a string
    --
    function std_logic_to_bin_string(inp : std_logic)
        return string
    is
        variable result : string(1 to 3);
    begin
        -- Add 0b prefix
        result(1) := '0';
        result(2) := 'b';
        result(3) := to_char(inp);
        return result;
    end;

    --
    -- convert a std_logic_vector to a string and add a binary point
    --
    function std_logic_vector_to_bin_string_w_point(inp : std_logic_vector; bin_pt : integer)
        return string
    is
        variable width : integer := inp'length;
        variable vec : std_logic_vector(width-1 downto 0);
        variable str_pos : integer;
        variable result : string(1 to width+3);
    begin
        vec := inp;
        -- Add 0b prefeix
        str_pos := 1;
        result(str_pos) := '0';
        str_pos := 2;
        result(str_pos) := 'b';
        str_pos := 3;
        for i in width-1 downto 0  loop
            -- Insert decimal point
            -- if i = (width - bin_pt + 1) then
            if (((width+3) - bin_pt) = str_pos) then
                result(str_pos) := '.';
                str_pos := str_pos + 1;
            end if;
            result(str_pos) := to_char(vec(i));
            str_pos := str_pos + 1;
        end loop;
        -- Add binary point at end of string when bin_pt = 0
        if (bin_pt = 0) then
            result(str_pos) := '.';
        end if;

        return result;
    end;

    -- Convert a real to a binary string
    function real_to_bin_string(inp : real;  width, bin_pt, arith : integer)
        return string
    is
        variable result : string(1 to width);
        variable vec : std_logic_vector(width-1 downto 0);

    begin
        vec := real_to_std_logic_vector(inp, width, bin_pt, arith);
        result := std_logic_vector_to_bin_string(vec);

        return result;
    end;


    -- Convert a real to string
    --  Note:  the size of the string returned is 'display_precision' chars long
    function real_to_string (inp : real) return string
    is
        variable result : string(1 to display_precision) := (others => ' ');
    begin
        result(real'image(inp)'range) := real'image(inp);
        return result;
    end;

    -- synthesis translate_on


end conv_pkg;


library work;
use work.conv_pkg.all;

--$Header: /devl/xcs/repo/env/Jobs/sysgen/src/xbs/hdl_pkg/xlclk.vhd,v 1.1 2004/11/22 00:17:49 rosty Exp $
---------------------------------------------------------------------
--
--  Filename      : xlclk.vhd
--
--  Date          : 8/25/00
--
--  Description   : VHDL description of default system clock generator
--                  with a period of 100ns.  This block is instantiated
--                  in the testbench and is only for simulation.
--
--  Modified      : 8/12/01 - First clock edge now starts at 200 ns so
--                            that -rpw 40 does not have to be used
--                : 07/12/01 - Added a generic that inverts the clock edges
--
---------------------------------------------------------------------

-- synthesis translate_off

library IEEE;
use IEEE.std_logic_1164.all;

entity xlclk is
  generic (clk_period  : time := 100 ns;
           additional_transport_delay  : time := 0 ns);  -- Clock period in ns
  port (clk   : out std_logic := '0';
        clr   : out std_logic := '0';
        ce    : out std_logic := '1');
end xlclk;

architecture behavior of xlclk is

    signal internal_clk : std_logic := '0';

begin

----------------------------------------------------------------------------
--  System clock generation
----------------------------------------------------------------------------

    clk_gen : process(internal_clk)
    begin
        internal_clk <= not(internal_clk) after clk_period/2;

        --if clk_period > 400 ns then
            clk <= transport not(internal_clk) after (200 ns + additional_transport_delay);
        --else
        --    clk <= transport internal_clk after (200 ns - (clk_period/2) + additional_transport_delay);
        --end if;
    end process;

    clr <= '0';
    ce <= '1';

end behavior;

-- synthesis translate_on

library work;
use work.conv_pkg.all;

--------------------------------------------------------------------------
--
--  Filename      : xltbsource.vhd
--
--  Date          : 10/1/99
--  Modified      : 11/15/01 - removed shutters / added internal clock driver
--                : 9/10/03  - eliminated reliance on internal clock source
--
--  Description   : VHDL description of test point
--
--------------------------------------------------------------------------

-- synthesis translate_off

library IEEE;
use IEEE.std_logic_1164.all;
use std.textio.all ;

entity xltbsource is

    generic (o_width : integer := 4;
               -- Width of o output
             o_bin_pt : integer := 2;
               -- Binary point of output o
             o_arith : integer := xlSigned;
               -- Type of arith of o output
             latency : integer := 1;
               -- Tells whether block has a clk
             inputFile : string := "test.dat";
               -- Source file for output o
             periodMultiplier : integer := 1;
               -- Multiplier to transform system clk period into real period
             reqHoldTime : time := 1500 ps);
               -- Determines amount of delay from rising edge to data transition

    port (o       : out std_logic_vector (o_width-1 downto 0);
          clk     : in std_logic);

end xltbsource;


architecture behavior of xltbsource is

    file  inputFilePtr : text open read_mode is inputFile;
    procedure read_data_set(file inputFilePtr : text;
                            constant width : in integer;
                            signal data : out std_logic_vector) is
        variable new_line:line;
        variable data_str : string(1 to width) := (others => ' ');
    begin

        -- read data word
        if not endfile(inputFilePtr) then
            readline(inputFilePtr, new_line);
            read(new_line, data_str);
        end if;

        data <= bin_string_to_std_logic_vector(data_str);
    end procedure read_data_set;

    signal internal_o : std_logic_vector(o_width-1 downto 0);
    signal real_o : real;   -- For debugging info
    signal sys_clk : std_logic;

begin
   sys_clk <= clk;

   -- Delay the data transition by the specified hold time value
   o <= internal_o after reqHoldTime;
   real_o <= to_real(internal_o, o_bin_pt, o_arith);


   -- This process will read a data value on the rising edge of the read
   -- clk signal.
   xltbsource_Process : process(sys_clk)
      variable period_count  : integer := 0;
      variable positive_edge : boolean := true;
      variable triggered     : boolean := false;
      variable startup       : boolean := true;
   begin
      if (startup = true) then
         read_data_set(inputFilePtr, o_width, internal_o);
         startup := false;
      end if;

      if (rising_edge(sys_clk) or falling_edge(sys_clk)) then
        if (triggered = false) then
           if (falling_edge(sys_clk)) then
             positive_edge := false;
           end if;
           triggered := true;
        end if;
        if ((rising_edge(sys_clk) and (positive_edge = true)) or
            (falling_edge(sys_clk) and (positive_edge = false))) then
          period_count := period_count + 1;
        end if;
      end if;

      if (period_count = periodMultiplier) then
         read_data_set(inputFilePtr, o_width, internal_o);
         -- reset period counter
         period_count := 0;
      end if;
   end process xltbsource_Process;

end architecture behavior;

-- synthesis translate_on

library work;
use work.conv_pkg.all;

-------------------------------------------------------------------
-- System Generator version 8.1.01 VHDL source file.
--
-- Copyright(C) 2006 by Xilinx, Inc.  All rights reserved.  This
-- text/file contains proprietary, confidential information of Xilinx,
-- Inc., is distributed under license from Xilinx, Inc., and may be used,
-- copied and/or disclosed only pursuant to the terms of a valid license
-- agreement with Xilinx, Inc.  Xilinx hereby grants you a license to use
-- this text/file solely for design, simulation, implementation and
-- creation of design files limited to Xilinx devices or technologies.
-- Use with non-Xilinx devices or technologies is expressly prohibited
-- and immediately terminates your license unless covered by a separate
-- agreement.
--
-- Xilinx is providing this design, code, or information "as is" solely
-- for use in developing programs and solutions for Xilinx devices.  By
-- providing this design, code, or information as one possible
-- implementation of this feature, application or standard, Xilinx is
-- making no representation that this implementation is free from any
-- claims of infringement.  You are responsible for obtaining any rights
-- you may require for your implementation.  Xilinx expressly disclaims
-- any warranty whatsoever with respect to the adequacy of the
-- implementation, including but not limited to warranties of
-- merchantability or fitness for a particular purpose.
--
-- Xilinx products are not intended for use in life support appliances,
-- devices, or systems.  Use in such applications is expressly prohibited.
--
-- Any modifications that are made to the source code are done at the user's
-- sole risk and will be unsupported.
--
-- This copyright and support notice must be retained as part of this
-- text at all times.  (c) Copyright 1995-2006 Xilinx, Inc.  All rights
-- reserved.
-------------------------------------------------------------------
-- synthesis translate_off
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use std.textio.all;
entity xltbsink is
   generic (i_width    : integer := 4;
            i_bin_pt   : integer := 2;
            i_arith    : integer := xlSigned;
            latency    : integer := 1;
            inputFile  : string  := "test.dat";
            outputFile : string  := "";
            periodMultiplier : integer := 1);
   port (i : in std_logic_vector (i_width-1 downto 0);
         clk : in std_logic);
end xltbsink;
architecture behavior of xltbsink is
   constant entityName : string := inputFile(1 to (inputFile'length-4));
   file inputFilePtr   : text open read_mode is inputFile;
   procedure read_data_set(file inputFilePtr   : text;
                           constant width      : in integer;
                           signal valid_bit    : out std_logic;
                           signal data         : out std_logic_vector;
                           variable data_valid : out boolean)
   is
      constant inp_str_width : integer := width;
      variable inp_str       : string(1 to inp_str_width) := (others => ' ');
      variable data_str      : string(1 to width);
      variable new_line      : line;
      variable data_var      : std_logic_vector(width-1 downto 0);
      variable valid_bit_var : std_logic;
   begin
      if not endfile(inputFilePtr) then
         readline(inputFilePtr, new_line);
         read(new_line, inp_str);
      end if;
      valid_bit <= '1';
      data_str := inp_str(1 to inp_str_width);
      data_valid := not(is_binary_string_invalid(data_str) or
                        is_binary_string_undefined(data_str));
      data_var := bin_string_to_std_logic_vector(data_str);
      data <= data_var;
   end procedure read_data_set;
   procedure check_data(signal simulink_i              : in std_logic_vector;
                        signal i_minus_one             : in std_logic_vector;
                        signal real_simulink_i, real_i : in real;
                        constant data_valid            : in boolean;
                        variable found_error           : inout boolean;
                        variable sample_count          : inout integer;
                        variable valid_count           : inout integer;
                        variable dntcare_count         : inout integer;
                        variable error_count           : inout integer)
   is
      constant carriage_return : character := cr;
      variable log_line        : line;
   begin
      sample_count := sample_count + 1;
      if (sample_count = 1) then
         write(log_line, CR);
	 writeline(output, log_line);
         write(log_line, "Beginning comparisons for instance " &
                              entityName);
         writeline(output, log_line);
      end if;
      valid_count := valid_count + 1;
      if (not(data_valid)) then
         dntcare_count := dntcare_count + 1;
      end if;
      if ((i_minus_one /= simulink_i) and data_valid) then
	 write(log_line, CR);
	 writeline(output, log_line);
         write(log_line, "** Data mismatch on instance " & entityName &
                              " at time ");
         write(log_line, now, justified => left, unit => ns);
         write(log_line, string'("."));
         writeline(output, log_line);
         write(log_line, "   Simulink result: " &
                         std_logic_vector_to_bin_string_w_point(simulink_i, i_bin_pt) &
                         " (" & real'image(real_simulink_i) & ")");
         writeline(output, log_line);
         write(log_line, "   VHDL result:     " &
                         std_logic_vector_to_bin_string_w_point(i, i_bin_pt) &
                         " (" & real'image(real_i) & ")");
         writeline(output, log_line);
         found_error := true;
         error_count := error_count + 1;
      end if;
   end procedure check_data;
   signal real_i, real_simulink_i : real;
   signal simulink_i              : std_logic_vector(i_width-1 downto 0);
   signal simulink_i_valid        : std_logic;
   signal error                   : std_logic := '0';
   signal i_minus_one             : std_logic_vector(i_width-1 downto 0);
begin
   real_i <= to_real(i, i_bin_pt, i_arith);
   real_simulink_i <= to_real(simulink_i, i_bin_pt, i_arith);
   i_minus_one <= i;
   xltbsink_Process : process(clk)
      variable found_error    : boolean := false;
      variable error_count    : integer := 0;
      variable sample_count   : integer := 0;
      variable valid_count    : integer := 0;
      variable dntcare_count  : integer := 0;
      variable error_reported : boolean := false;
      variable data_valid     : boolean := false;
      variable log_line       : line;
      variable triggered      : boolean := false;
      variable positive_edge  : boolean := true;
      variable period_count   : integer := 0;
      variable startup        : boolean := true;
   begin
      if (startup = true) then
         read_data_set(inputFilePtr, i_width, simulink_i_valid, simulink_i, data_valid);
         startup := false;
      end if;
      if (rising_edge(clk) or
          falling_edge(clk)) then
         if (triggered = false) then
            if (falling_edge(clk)) then
               positive_edge := false;
            end if;
            triggered := true;
         end if;
         if ((rising_edge(clk) and (positive_edge = true))
             or (falling_edge(clk) and
             (positive_edge = false))) then
            period_count := period_count + 1;
         end if;
      end if;
      if (period_count = periodMultiplier) then
         if not endfile(inputFilePtr) then
            check_data(simulink_i, i_minus_one, real_simulink_i, real_i,
                       data_valid, found_error, sample_count, valid_count,
                       dntcare_count, error_count);
            if (found_error) then
               error <= '1';
            else
               error <= '0';
            end if;
            read_data_set(inputFilePtr, i_width, simulink_i_valid, simulink_i, data_valid);
         elsif error_reported = false then
            check_data(simulink_i, i_minus_one, real_simulink_i, real_i,
                       data_valid, found_error, sample_count, valid_count,
                       dntcare_count, error_count);
	    write(log_line, CR);
	    writeline(output,log_line);
            write(log_line, "** Simulation summary for instance " & entityName & ":");
	    writeline(output,log_line);
            write(log_line,      "   Samples Processed: " & integer'image(sample_count));
	    writeline(output,log_line);
            write(log_line,    "           - Checked: " & integer'image(valid_count-dntcare_count) & " (");
            write(log_line, real(valid_count-dntcare_count)/real(sample_count)*100.0,
                                           justified=>left,digits=>1);
            write(log_line, string'("%)"));
            writeline(output,log_line);
            write(log_line,    "           - Ignored: " & integer'image(dntcare_count) & " (");
            write(log_line, real(dntcare_count)/real(sample_count)*100.0,
                                 justified=>left,digits=>1);
            write(log_line, string'("%) Don't Cares"));
            writeline(output,log_line);
            if ((sample_count-valid_count) /= 0) then
               write(log_line,    "                      " & integer'image(sample_count-valid_count) & " (");
               write(log_line, real(sample_count-valid_count)/real(sample_count)*100.0,
                                    justified=>left,digits=>1);
               write(log_line, string'("%) Invalid"));
               writeline(output,log_line);
            end if;
            if (found_error) then
               write(log_line, "   There were " & integer'image(error_count) & " mismatches in the test.");
               writeline(output, log_line);
               write(output, "ERROR: There were " & integer'image(error_count) & " mismatches in the test.");
            else
               write(output, "   Test completed with no errors.");
            end if;
            error_reported := true;
         end if;
         period_count := 0;
      end if;
   end process xltbsink_Process;
end architecture behavior;
-- synthesis translate_on

use work.conv_pkg.all;
-- Generated from Simulink block 
library IEEE;
use IEEE.std_logic_1164.all;
library xil_defaultlib;
entity small_test_tb is
end small_test_tb;
architecture structural of small_test_tb is 
  signal clk_net : std_logic;
  signal inp_recv_re1_net : std_logic_vector( 16-1 downto 0 );
  signal out_recv_net : std_logic_vector( 1-1 downto 0 );
  signal inp_trans_net : std_logic_vector( 1-1 downto 0 );
  signal out_trans_im_net : std_logic_vector( 16-1 downto 0 );
  signal inp_recv_im1_net : std_logic_vector( 16-1 downto 0 );
  signal out_trans_re_net : std_logic_vector( 16-1 downto 0 );
begin
  clk_driver : entity xil_defaultlib.xlclk 
  generic map (
    clk_period => 4 ns
  )
  port map (
    clk => clk_net
  );
  inp_recv_im1_driver : entity xil_defaultlib.xltbsource 
  generic map (
    o_arith => xlSigned,
    o_bin_pt => 13,
    o_width => 16,
    inputFile => "small_test_inp_recv_im1.dat",
    periodMultiplier => 8
  )
  port map (
    clk => clk_net,
    o => inp_recv_im1_net
  );
  inp_recv_re1_driver : entity xil_defaultlib.xltbsource 
  generic map (
    o_arith => xlSigned,
    o_bin_pt => 13,
    o_width => 16,
    inputFile => "small_test_inp_recv_re1.dat",
    periodMultiplier => 8
  )
  port map (
    clk => clk_net,
    o => inp_recv_re1_net
  );
  inp_trans_driver : entity xil_defaultlib.xltbsource 
  generic map (
    o_arith => xlUnsigned,
    o_bin_pt => 0,
    o_width => 1,
    inputFile => "small_test_inp_trans.dat",
    periodMultiplier => 5
  )
  port map (
    clk => clk_net,
    o => inp_trans_net
  );
  out_recv_load : entity xil_defaultlib.xltbsink 
  generic map (
    i_arith => xlUnsigned,
    i_bin_pt => 0,
    i_width => 1,
    inputFile => "small_test_out_recv.dat",
    periodMultiplier => 5
  )
  port map (
    i => out_recv_net,
    clk => clk_net
  );
  out_trans_im_load : entity xil_defaultlib.xltbsink 
  generic map (
    i_arith => xlSigned,
    i_bin_pt => 13,
    i_width => 16,
    inputFile => "small_test_out_trans_im.dat",
    periodMultiplier => 8
  )
  port map (
    i => out_trans_im_net,
    clk => clk_net
  );
  out_trans_re_load : entity xil_defaultlib.xltbsink 
  generic map (
    i_arith => xlSigned,
    i_bin_pt => 13,
    i_width => 16,
    inputFile => "small_test_out_trans_re.dat",
    periodMultiplier => 8
  )
  port map (
    i => out_trans_re_net,
    clk => clk_net
  );
  sysgen_dut : entity xil_defaultlib.small_test 
  port map (
    inp_recv_im1 => inp_recv_im1_net,
    inp_recv_re1 => inp_recv_re1_net,
    inp_trans => inp_trans_net,
    clk => clk_net,
    out_recv => out_recv_net,
    out_trans_im => out_trans_im_net,
    out_trans_re => out_trans_re_net
  );
end structural;
