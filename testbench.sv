`timescale 1ns / 1ps

module testbench();

    logic TbClk;
    logic TbReset;
    logic TbEn;
    logic TbD;
    logic TbLoad;
    logic [3:0] TbDataIn;

    logic OutD;
    logic OutEn;
    logic OutSync;
    logic [3:0] OutProj;
    logic OutPiso;

    initial begin
        TbClk = 0;
        forever #5 TbClk = ~TbClk;
    end

    dtrigger UnitD (.D(TbD), .CLK(TbClk), .Q(OutD));
    dtrigger_en UnitEn (.D(TbD), .CLK(TbClk), .EN(TbEn), .Q(OutEn));
    SyncRes UnitSync (.D(TbD), .CLK(TbClk), .reset(TbReset), .Q(OutSync));
    ProjVL UnitProj (.Clk(TbClk), .Reset(TbReset), .Q(OutProj));
    ParallelSerialRegister UnitPiso (.Clk(TbClk), .Reset(TbReset), .Load(TbLoad), .ParallelData(TbDataIn), .SerialOut(OutPiso));

    initial begin
        TbReset = 1; TbD = 0; TbEn = 0; TbLoad = 0; TbDataIn = 4'b0000;
        #15 TbReset = 0;
        
        #10 TbD = 1; TbEn = 1;
        #10 TbD = 0;
        #10 TbEn = 0; TbD = 1;
        
        #10 TbLoad = 1; TbDataIn = 4'b1011;
        #10 TbLoad = 0;
        
        repeat (6) @(posedge TbClk);
        $stop;
    end

    initial begin
        $monitor("Time=%0t | Rst=%b | D=%b | En=%b | Ld=%b | D_Trig=%b | En_Trig=%b | Sync_Trig=%b | Proj_Vec=%b | Parall_ser_Out=%b", 
                 $time, TbReset, TbD, TbEn, TbLoad, OutD, OutEn, OutSync, OutProj, OutPiso);
    end

endmodule