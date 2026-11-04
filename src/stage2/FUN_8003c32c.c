/* FUN_8003c32c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c32c  body 0x8003c32c..0x8003c3bf  size 148 B
 * body sha256 7a3fb08e87f2f6129b8830acdaba278cad2df2d811782fa6cf05239171d19fb1
 * provider record sha256 e392a24aa41c62a43a16c16c3691556cde84a4acab5f080d7c8eb59f59c3dcf9
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c32c(void)

{
  uint uVar1;
  
  uVar1 = FUN_80033604();
  FUN_80038a20(((byte)DAT_800ebb94[2] + 3) * 0x10000 | 0x9000c00,(uVar1 & 0xff) << 4,
               *(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  uVar1 = FUN_80033604();
  FUN_80038a20(((byte)DAT_800ebb94[2] + 4) * 0x10000 | 0x9000a00,(uVar1 & 0xff) << 4,
               *(undefined4 *)(DAT_800ebb94 + 0x6c),DAT_800ebb94 + 0x2c);
  *DAT_800ebb94 = 0;
  return;
}
