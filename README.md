# stream-sign-flip
A simple Vitis HLS core to negate the Q values from a DDS to produce a waveform for downconversion.

The DDS waveform is generated from the Xilinx FIR core. The FIR core data output format is shown in the "Implementation Details" tab in the FIR compiler core GUI. The FIR outputs 256 samples per clock which constitute 8, 16-bit IQ samples. This core splices out the 8 Q samples, negates them according to twos complement rules, and spliced them back in. This forms a mirror waveform to the upconversion stream which can be used for downconversion.

See testbench output for details:
```
Input data vec 0 Path 0 bits 15:0
 |input value: 123 output value: 123| 
  ** PASS ** 
Input data vec 0 Path 1 bits 31:16
 |input value: 124 output value: -124| 
  ** PASS **
Input data vec 1 Path 0 bits 47:32
 |input value: 125 output value: 125| 
  ** PASS ** 
Input data vec 1 Path 1 bits 63:48
 |input value: 126 output value: -126| 
  ** PASS **
Input data vec 2 Path 0 bits 79:64
 |input value: 127 output value: 127| 
  ** PASS ** 
Input data vec 2 Path 1 bits 95:80
 |input value: 128 output value: -128| 
  ** PASS **
Input data vec 3 Path 0 bits 111:96
 |input value: 129 output value: 129| 
  ** PASS ** 
Input data vec 3 Path 1 bits 127:112
 |input value: 130 output value: -130| 
  ** PASS **
Input data vec 4 Path 0 bits 143:128
 |input value: 131 output value: 131| 
  ** PASS ** 
Input data vec 4 Path 1 bits 159:144
 |input value: 132 output value: -132| 
  ** PASS **
Input data vec 5 Path 0 bits 175:160
 |input value: 133 output value: 133| 
  ** PASS ** 
Input data vec 5 Path 1 bits 191:176
 |input value: 134 output value: -134| 
  ** PASS **
Input data vec 6 Path 0 bits 207:192
 |input value: 135 output value: 135| 
  ** PASS ** 
Input data vec 6 Path 1 bits 223:208
 |input value: 136 output value: -136| 
  ** PASS **
Input data vec 7 Path 0 bits 239:224
 |input value: 137 output value: 137| 
  ** PASS ** 
Input data vec 7 Path 1 bits 255:240
 |input value: 138 output value: -138| 
  ** PASS **
*** ALL TESTS PASSED ***
```
