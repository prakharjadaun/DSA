/*
Step 0.
abcd efgh ijkl mnop qrst uvwx yzAB CDEF <-- n

Step 1.
                    abcd efgh ijkl mnop <-- n >> 16, same as (n & 0xffff0000) >> 16
qrst uvwx yzAB CDEF                     <-- n << 16, same as (n & 0x0000ffff) << 16
qrst uvwx yzAB CDEF abcd efgh ijkl mnop <-- after OR

Step 2.
          qrst uvwx           abcd efgh <-- (n & 0xff00ff00) >> 8
yzAB CDEF           ijkl mnop           <-- (n & 0x00ff00ff) << 8
yzAB CDEF qrst uvwx ijkl mnop abcd efgh <-- after OR

Step 3.
     yzAB      qrst      ijkl      abcd <-- (n & 0xf0f0f0f0) >> 4
CDEF      uvwx      mnop      efgh      <-- (n & 0x0f0f0f0f) << 4
CDEF yzAB uvwx qrst mnop ijkl efgh abcd <-- after OR

Step 4.
  CD   yz   uv   qr   mn   ij   ef   ab <-- (n & 0xcccccccc) >> 2
EF   AB   wx   st   op   kl   gh   cd   <-- (n & 0x33333333) << 2
EFCD AByz wxuv stqr opmn klij ghef cdab <-- after OR

Step 5.
 E C  A y  w u  s q  o m  k i  g e  c a <-- (n & 0xaaaaaaaa) >> 1
F D  B z  x v  t r  p n  l j  h f  d b  <-- (n & 0x55555555) << 1
FEDC BAzy xwvu tsrq ponm lkji hgfe dcba <-- after OR
*/
//performing left & right shift with 16, 8 , 4, 2 , 1 and applying OR operator at each shifting 
#include<stdint.h>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        n = (n>>16)|(n<<16);
        n = ((n & 0xff00ff00)>>8) | ((n & 0x00ff00ff)<<8);
        n = ((n & 0xf0f0f0f0)>>4) | ((n & 0x0f0f0f0f)<<4);
        n = ((n & 0xcccccccc)>>2) | ((n & 0x33333333)<<2);
        n = ((n & 0xaaaaaaaa)>>1) | ((n & 0x55555555)<<1);
        return n;
    }
};