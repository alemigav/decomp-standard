/* FUN_8009ce40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ce40  body 0x8009ce40..0x8009ced7  size 152 B
 * body sha256 171d52cf7ad44ebe6d45755177af32dc3b8b899302e4894bdb4cbc9180c46485
 * provider record sha256 78a6e5611b4a030aff1353a9f8494f24f77838b4c0dff42ef9af8ff087fc2c74
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009ce40(void)

{
  int iVar1;
  
  if ((DAT_80132728 & 1) == 0) {
    FUN_800274f8(DAT_8013272b | 0x200,0xffffff00,7,1);
    DAT_8013272a = 0;
    DAT_80132728 = DAT_80132728 | 1;
    FUN_800274e4(5,0);
  }
  else {
    iVar1 = FUN_8002767c(DAT_8013272b);
    if (iVar1 != 0) {
      DAT_8013272a = 1;
      DAT_80132728 = DAT_80132728 ^ 1;
    }
  }
  return;
}
