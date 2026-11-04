/* FUN_8017ff0c
 * image   ovl_0078c0e (ovl), base 0x8017b410
 * address 0x8017ff0c  body 0x8017ff0c..0x8017ff7f  size 96 B
 * body sha256 3d6258c0f343379f3bb22b5835f16270398207665609e84119fed4b0b1c91be5
 * provider record sha256 2305b8d815ff40d4520263e647874773c89911e82fea26c9caa3cac9afa4475f
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8017ff0c(void)

{
  undefined4 unaff_s0;
  
  osRecvMesg(&DAT_80181f94,0,1);
  switch(DAT_80180ad8) {
  case 0:
    unaff_s0 = 0;
    break;
  case 1:
  case 3:
  case 4:
  case 10:
  case 0xb:
    unaff_s0 = 3;
    break;
  case 2:
    unaff_s0 = 2;
  }
  return unaff_s0;
}
