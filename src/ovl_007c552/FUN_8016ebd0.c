/* FUN_8016ebd0
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8016ebd0  body 0x8016ebd0..0x8016ecb7  size 232 B
 * body sha256 b4dc3742379e382903682f8da59b56476652335717669001340d6436dceb3832
 * provider record sha256 10a88f8690d54fcb1a6df3db0e2cdde90652fb8c9d5e8d708719b7c9c5d80508
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016ebd0(void)

{
  int iVar1;
  
  if ((DAT_80171df4 & 1) == 0) {
    func_0x800274f8(0x200,0xffffff00,7,1);
    DAT_80171dd9 = 0;
    if ((DAT_80171df4 & 0x800) == 0) {
      DAT_80171df4 = DAT_80171df4 | 1;
      func_0x800274e4(2,1);
    }
    else {
      DAT_80171df4 = DAT_80171df4 | 1;
      func_0x800274e4(0,0);
      DAT_80171df4 = DAT_80171df4 ^ 0x800;
    }
    if ((DAT_80171df4 & 0x1000) != 0) {
      FUN_801700ac(DAT_80171dec,1,0);
      DAT_80171dec = 0;
      DAT_80171df4 = DAT_80171df4 ^ 0x1000;
    }
  }
  else {
    iVar1 = func_0x8002767c(0);
    if (iVar1 != 0) {
      DAT_80171dd9 = 1;
      DAT_80171df4 = DAT_80171df4 ^ 1;
    }
  }
  return;
}
