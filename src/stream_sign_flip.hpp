#include "ap_axi_sdata.h"
#include <ap_int.h>
#include "hls_stream.h"

using stream_data_t = ap_axiu<256,0,0,0>; // Stream data format
using tdata_val_t = ap_int<256>; // Data sample
using stream_t = hls::stream<stream_data_t>; // Stream type

void stream_sign_flip(stream_t &stream_in, stream_t &stream_out);
