  sysgen_dut : entity xil_defaultlib.basic_dmt 
  port map (
    inp_recv_im => inp_recv_im,
    inp_recv_re => inp_recv_re,
    inp_trans => inp_trans,
    clk => clk,
    out_recv => out_recv,
    out_trans_im => out_trans_im,
    out_trans_re => out_trans_re
  );
