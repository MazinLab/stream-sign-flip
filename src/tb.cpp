#include <stdio.h>
#include <iostream>
#include "stream_sign_flip.hpp"
using namespace std;

int main() {

	bool fail=0;

	stream_t stream_input, stream_output;
	stream_data_t stream_data_in, stream_data_out;


    printf("HLS Negate AXI-Stream Data\n");
    printf("Beginning tests: \n\n");

    for (int x = 0; x < 16; x++) {
    	stream_data_in.data.range(x*16+15, x*16) = ap_int<16>(x+123); // Generate some data
      }

    stream_input.write(stream_data_in); // Load input HLS stream

    stream_sign_flip(stream_input, stream_output); // Run IP core

	stream_output.read(stream_data_out); // Read output stream values into usable data type

	// Run checks
    for (int i = 0; i < 16; i++) {
    	ap_int<16> input_data_val = stream_data_in.data.range(i*16+15, i*16);
    	ap_int<16> output_data_val = stream_data_out.data.range(i*16+15, i*16);
    	printf("Input data vec %d Path %d bits %d:%d\n |input value: %d output value: %d| \n", i/2, i%2, i*16+15, i*16, (int)input_data_val, (int)output_data_val);

    	// Check even values
    	if (i % 2 == 0) {
    		if ((int)input_data_val == (int)output_data_val) {
    			printf("  ** PASS ** \n");
    		}
    	    else {
    			printf("  ** FAIL ** \n");
    			fail = 1;
    	    }
        }

    	// Check odd values
    	else {
    		if ((int)input_data_val == -(int)output_data_val) {
    			printf("  ** PASS **\n");
    		}
    		else {
    			printf("  ** FAIL **\n");
    			fail = 1;
    		}
    	}
    }

    if (!fail) cout<<"*** ALL TESTS PASSED ***" << endl;
    return fail;
}
