function [y1]= Demod_16QAM(I,Q)
%Some ideas from UG958
 one  = xfix({xlUnsigned,1,0}, 1);
zero = xfix({xlUnsigned,1,0}, 0);

 if (I >= 0)
        Y0 = one;
        if (I > 2)
            Y1 = zero;
        else
            Y1 = one;
        end;
    else
        Y0 = zero;
        if (I > -2)
            Y1 = one;
        else
            Y1 = zero;
        end;
 end;
    if (Q >= 0)
        Y2 = zero;
        if (Q > 2)
            Y3 = zero;
        else
            Y3 = one;
        end;
    else
        Y2 = one;
        if (Q > -2)
            Y3 = one;
        else
            Y3 = zero;
        end;
    end;        
    
    y1 = xl_concat(Y0, Y1, Y2, Y3);
  end
