/* FUN_8003c864
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c864  body 0x8003c864..0x8003c8d3  size 112 B
 * body sha256 80d1cc4913fe843852b802fbab2ad7ceb48f307d7fcb874dccc0705552abad57
 * provider record sha256 a55f35fc17191a2aa48d3f0af4e2dd9c62e57b82ed2a947139092eb578777542
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8003c6a4::caseD_4(void)

{
  undefined1 *puVar1;
  
  if (DAT_800ebb94[0xb] == -1) {
    *(short *)(DAT_800ebb94 + 0x36) = *(short *)(DAT_800ebb94 + 0x36) + -600;
  }
  FUN_80038a20(0x4152700,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
  puVar1 = DAT_800ebb94;
  DAT_800ebb94[1] = 0;
  *puVar1 = 0;
  *(undefined2 *)(puVar1 + 0x18) = 0;
  return;
}
