/* FUN_8003ba1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003ba1c  body 0x8003ba1c..0x8003bac7  size 172 B
 * body sha256 2d79a35d9f2f4b3e13962351f0ae808f6658115a36e22db6bc5e63910c7fb58e
 * provider record sha256 a8d20f714383392d958478de0ce3bf8a5f7fd65cb063a683be83369eb9bf00b4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003ba1c(void)

{
  ushort uVar2;
  uint uVar1;
  
  FUN_80039c34();
  if (*(char *)(DAT_800ebb94 + 0x1e) == '\x04') {
    *(undefined1 *)(DAT_800ebb94 + 0x1b) = 2;
    uVar2 = FUN_80033604();
    *(ushort *)(DAT_800ebb94 + 0x42) = (uVar2 & 7) + 2;
  }
  else {
    *(undefined1 *)(DAT_800ebb94 + 0x1b) = 3;
    uVar1 = FUN_80033604();
    *(short *)(DAT_800ebb94 + 0x42) = (short)((uVar1 & 0xff) % 6) * 0x32 + 700;
  }
  return;
}
