/* FUN_8003b780
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b780  body 0x8003b780..0x8003b8c7  size 328 B
 * body sha256 4ab4d0febadf4fc6c813ae4948e39f1a974fa7c0250edc18c928dd3c5d1c60b6
 * provider record sha256 84f6dccebe81228164e837a1d04492bbdf50f8449aa51fa5682f0147ec4bd46d
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003b780(void)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar3 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
  puVar2 = DAT_800ebb94;
  if ((iVar3 != 0) && (iVar3 < *(short *)(DAT_800ebb94 + 0x36))) {
    *DAT_800ebb94 = 0;
    *(undefined2 *)(puVar2 + 0x18) = 0;
  }
  puVar2 = DAT_800ebb94;
  if (*(short *)(DAT_800ebb94 + 0xc) < 0) {
    DAT_800ebb94[8] = 0;
    *(undefined2 *)(puVar2 + 0xc) = 0;
  }
  local_20 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_1c = *(short *)(DAT_800ebb94 + 0x36) + -900;
  local_18 = (int)*(short *)(DAT_800ebb94 + 0x38);
  iVar3 = FUN_80069f1c(&local_20,2,0x2000,0);
  local_1c = local_1c + 900;
  if (iVar3 < local_1c) {
    (*(code *)(&PTR_FUN_800eb9b0)[(byte)DAT_800ebb94[2]])();
  }
  else {
    if (DAT_8011270c != 0) {
      if (iVar3 == *(int *)(DAT_800ebb94 + 0x14)) {
        bVar1 = DAT_800ebb94[3];
      }
      else {
        bVar1 = DAT_800ebb94[2];
      }
      (*(code *)(&PTR_FUN_800eb9b0)[bVar1])();
    }
    *(int *)(DAT_800ebb94 + 0x14) = iVar3;
  }
  return;
}
