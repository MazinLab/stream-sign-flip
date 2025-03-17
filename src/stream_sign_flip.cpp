
#include "stream_sign_flip.hpp"

void stream_sign_flip(stream_t &stream_in, stream_t &stream_out){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE axis port=stream_in
#pragma HLS INTERFACE axis port=stream_out
#pragma HLS PIPELINE ii=1 // Need this to ensure TVALID / TREADY stay high

	stream_data_t stream_data;
	stream_in.read(stream_data);

	for (int i = 0; i < 16; i++)
	#pragma HLS UNROLL
		if (i%2) {
			stream_data.data.range(i*16+15, i*16) = -stream_data.data.range(i*16+15, i*16); // Negate Q values
		}

	stream_out.write(stream_data);

}
