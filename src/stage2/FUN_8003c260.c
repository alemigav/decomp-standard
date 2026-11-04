/* FUN_8003c260
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c260  body 0x8003c260..0x8003c32b  size 204 B
 * body sha256 4540b7f0c8d669c90b657e8495b7bf9cb2c847e0edea9ce175646d9457d10c29
 * provider record sha256 cc2501920d2bf51d835de594b19113e15f016858e42dfefcd0b5b04042d00329
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c260(void)

{
  uint uVar1;
  
  uVar1 = FUN_80033604();
  FUN_80038a20((uint)(byte)DAT_800ebb94[2] << 0x10 | 0x9000800,(uVar1 & 0xff) << 4,
               *(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  uVar1 = FUN_80033604();
  FUN_80038a20(((byte)DAT_800ebb94[2] + 1) * 0x10000 | 0x9001000,(uVar1 & 0xff) << 4,
               *(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  uVar1 = FUN_80033604();
  FUN_80038a20(((byte)DAT_800ebb94[2] + 2) * 0x10000 | 0x9000c00,(uVar1 & 0xff) << 4,
               *(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  *DAT_800ebb94 = 0x2a;
  return;
}
