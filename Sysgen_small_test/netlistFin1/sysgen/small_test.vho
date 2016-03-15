  sysgen_dut : entity xil_defaultlib.small_test 
  port map (
    inp_recv_im1 => inp_recv_im1,
    inp_recv_re1 => inp_recv_re1,
    inp_trans => inp_trans,
    clk => clk,
    out_recv => out_recv,
    out_trans_im => out_trans_im,
    out_trans_re => out_trans_re
  );
