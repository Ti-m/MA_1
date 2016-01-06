function [y1]= Demod_16QAM(I,Q)
%Some ideas from UG958 and OFDM-FPGA.zip
 one  = xfix({xlUnsigned,1,0}, 1);
zero = xfix({xlUnsigned,1,0}, 0);

 if (I > 0)
        B0 = one;
        if (I > 2)
            B1 = zero;
        else
            B1 = one;
        end;
    else
        B0 = zero;
        if (I > -2)
            B1 = one;
        else
            B1 = zero;
        end;
    end;
    if (Q > 0)
        B2 = zero;
        if (Q > 2)
            B3 = zero;
        else
            B3 = one;
        end;
    else
        B2 = one;
        if (Q > -2)
            B3 = one;
        else
            B3 = zero;
        end;
    end;        
    
   % y1 = xl_concat(B3, B2, B1, B0);
    y1 = xl_concat(B0, B1, B2, B3);
  end
