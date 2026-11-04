/* FUN_80039da4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039da4  body 0x80039da4..0x80039f07  size 356 B
 * body sha256 f821d22d2f4dcfbb7e7646cc4f5f67d5a79b2c5da52009694463ac868058137a
 * provider record sha256 c46f9989c508c209c1bbd7309b3639c1ac818174685b4b43d1867dc0b039050a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039da4(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  int local_18;
  int local_14;
  int local_10;
  
  iVar3 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
  if ((iVar3 == 0) || (*(short *)(DAT_800ebb94 + 0x36) <= iVar3)) {
    local_18 = (int)*(short *)(DAT_800ebb94 + 0x34);
    local_14 = (int)*(short *)(DAT_800ebb94 + 0x36);
    local_10 = (int)*(short *)(DAT_800ebb94 + 0x38);
    iVar3 = FUN_80069f1c(&local_18,2,0x2000,0);
    if (iVar3 < local_14) {
      (*(code *)(&PTR_FUN_800eb9b0)[(byte)DAT_800ebb94[2]])();
      return;
    }
    if (DAT_8011270c == 0) {
      *(int *)(DAT_800ebb94 + 0x14) = iVar3;
      return;
    }
    if (iVar3 == *(int *)(DAT_800ebb94 + 0x14)) {
      uVar4 = (uint)(byte)DAT_800ebb94[3];
    }
    else {
      uVar4 = (uint)(byte)DAT_800ebb94[2];
    }
  }
  else {
    FUN_80038a20(*(ushort *)(DAT_800ebb94 + 0x3a) | 0x1a010000,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
    puVar1 = DAT_800ebb94;
    DAT_800ebb94[1] = 0;
    *puVar1 = 0;
    puVar2 = DAT_800ebb94;
    *(undefined2 *)(puVar1 + 0x18) = 0;
    if (puVar2[0x1c] != '\x1d') {
      return;
    }
    uVar4 = (uint)(byte)puVar2[2];
  }
  (*(code *)(&PTR_FUN_800eb9b0)[uVar4])();
  return;
}
