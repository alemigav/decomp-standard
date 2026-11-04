/* FUN_8006cda8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006cda8  body 0x8006cda8..0x8006cdef  size 72 B
 * body sha256 90c5354b3d0549376efaa9cefc2d49687eaefab7e223eb49d64c2574685a8913
 * provider record sha256 6cdd6f2650316bd89162d59f1e85bdc9cbe4293ffdfdd9e28374771785f127e8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006cda8(undefined4 param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    FUN_8006cc58();
  }
  if (param_3 != 0) {
    FUN_8006cccc(param_1,param_3);
  }
  return;
}
