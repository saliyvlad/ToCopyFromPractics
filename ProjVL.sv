//module dtrigger_EN(
module dtrigger_en(
    input  logic D,
    input  logic CLK,
    input  logic EN,
    output logic Q
);
always_ff @(posedge CLK) begin
    if (EN) begin
        Q <= D;
    end
end
endmodule

module dtrigger(
    input logic D,
    input logic CLK,
    output logic Q
);
    always_ff @(posedge CLK) begin
        Q <= D;
    end
endmodule

module SyncRes(
    input logic D,
    input logic CLK,
	 input logic reset,
    output logic Q
);
always_ff @(posedge CLK) begin
	if (reset)
		Q <= 1'b0;
	else
		Q <= D;
	end
endmodule

module ProjVL (
    input logic Clk,       // тактовый сигнал
    input logic Reset,     // сигнал сброса
    output logic [3:0] Q    // выходы триггеров
);
    always_ff @(posedge Clk or posedge Reset) begin
        if (Reset) begin
            Q <=4'b0000;
        end else begin
            Q[0]<= ~(Q[0] | Q[1] | Q[2] | Q[3]); 
            Q[1]<= Q[0];
            Q[2]<= Q[1];
            Q[3]<= Q[2];
        end
    end

endmodule

module ParallelSerialRegister(
    input logic Clk,          // тактовый сигнал
    input logic Reset,        // сигнал сброса
    input logic Load,         // 1= загрузка данных | 0=сдвиг
    input logic [3:0] ParallelData, // параллельный вход
    output logic SerialOut     // последовательный выход
);
    logic [3:0] ShiftReg;
    always_ff @(posedge Clk or posedge Reset) begin
        if (Reset) begin
            ShiftReg <= 4'b0000;
        end else begin
            if (Load) begin
                ShiftReg <=ParallelData;
            end else begin
                ShiftReg <={ShiftReg[2:0],1'b0};
            end
        end
    end
    assign SerialOut = ShiftReg[3];

endmodule