/* FUN_8003b8c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b8c8  body 0x8003b8c8..0x8003ba1b  size 340 B
 * body sha256 aa6f08bcc4cb19036ffe67e9408063a4f37949560d6ff793ee0104fc97ed99b0
 * provider record sha256 2c86eeabcec2aa86c28b5d6c6399f5aac2cb84755462fc7d4c5e723453f5a870
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003b8c8(void)

{
  int iVar1;
  uint uVar2;
  int local_18;
  int local_14;
  int local_10;
  
  iVar1 = DAT_800ebb94;
  if (*(short *)(DAT_800ebb94 + 0xc) < 1) {
    *(undefined1 *)(DAT_800ebb94 + 8) = 0;
    *(undefined2 *)(iVar1 + 0xc) = 0;
  }
  else if ((0x3c < *(short *)(DAT_800ebb94 + 0xc)) && ((uint)*(byte *)(DAT_800ebb94 + 2) % 0xf == 0)
          ) {
    uVar2 = FUN_80038a20(((uint)*(ushort *)(DAT_800ebb94 + 0x3a) << 2) / 5 | 0x5040000,
                         (int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,DAT_800ebb94 + 0x34);
    if ((uVar2 & 0xff) < 0xff) {
      *(undefined2 *)(&DAT_800ebdf2 + (uVar2 & 0xff) * 0x7c) = 1;
    }
  }
  *(char *)(DAT_800ebb94 + 2) = *(char *)(DAT_800ebb94 + 2) + '\x01';
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_14 = *(short *)(DAT_800ebb94 + 0x36) + -100;
  local_10 = (int)*(short *)(DAT_800ebb94 + 0x38);
  FUN_80069f1c(&local_18,2,0x2000,0);
  if (DAT_8011270c != 0) {
    (*(code *)(&PTR_FUN_800eb9b0)[*(byte *)(DAT_800ebb94 + 3)])();
  }
  return;
}
