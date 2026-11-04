/* FUN_8003f814
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003f814  body 0x8003f814..0x8003f977  size 356 B
 * body sha256 430f8ce6617781680239d550c99595c553bede764cc3aa69aae7d74e3b46e5a3
 * provider record sha256 344fd545be7e65da9e3b046710842300d7a5978de5da3a00c2713f580641f4dc
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003f814(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  byte bVar5;
  int local_28;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  int iStack_10;
  
  iVar2 = DAT_800ebb94;
  *(undefined1 *)(DAT_800ebb94 + 0x21) = 10;
  iVar3 = DAT_800ebb94;
  *(undefined2 *)(iVar2 + 4) = 0x1000;
  *(undefined2 *)(iVar2 + 6) = 0x1000;
  *(undefined1 *)(iVar3 + 0x20) =
       *(undefined1 *)(*(int *)(iVar3 + 0x70) + (uint)*(byte *)(iVar3 + 0x21) * 8 + 2);
  iVar2 = DAT_800ebb94;
  *(undefined1 *)(DAT_800ebb94 + 8) = 0;
  iVar3 = DAT_800ebb94;
  *(undefined2 *)(iVar2 + 0xc) = 0;
  *(undefined1 *)(iVar3 + 9) = 0;
  iVar2 = DAT_800ebb94;
  *(undefined2 *)(iVar3 + 0xe) = 0;
  *(undefined1 *)(iVar2 + 1) = 0;
  bVar5 = *(byte *)(DAT_800ebb94 + 0x1b) & 0x7f;
  if (bVar5 == 1) {
    *(undefined1 *)(DAT_800ebb94 + 0x1b) = 3;
    uVar4 = 0x400;
  }
  else {
    if (bVar5 < 2) {
      if ((*(byte *)(DAT_800ebb94 + 0x1b) & 0x7f) != 0) {
        return;
      }
      *(undefined1 *)(DAT_800ebb94 + 0x1b) = 3;
      iVar2 = DAT_800ebb94;
      pcVar1 = (char *)(DAT_800ebb94 + 0x1b);
      *(undefined2 *)(DAT_800ebb94 + 0x48) = 0;
      if (((int)*pcVar1 & 0x80U) == 0) {
        local_28 = (int)*(short *)(iVar2 + 0x34);
        local_24 = (int)*(short *)(iVar2 + 0x36);
        local_20 = (int)*(short *)(iVar2 + 0x38);
        local_18 = (int)*(short *)(iVar2 + 0x24);
        local_14 = (int)*(short *)(iVar2 + 0x26);
        iStack_10 = (int)*(short *)(iVar2 + 0x28);
        FUN_80077adc(0x31d0001,&local_28);
        FUN_80038a20(0x4091800,(int)*(short *)(DAT_800ebb94 + 0x22),&DAT_800e9028,
                     DAT_800ebb94 + 0x34);
        return;
      }
      return;
    }
    if (bVar5 != 2) {
      return;
    }
    *(undefined1 *)(DAT_800ebb94 + 0x1b) = 3;
    uVar4 = 0xc00;
  }
  iVar2 = DAT_800ebb94;
  *(undefined2 *)(DAT_800ebb94 + 0x44) = uVar4;
  *(undefined2 *)(iVar2 + 0x46) = 0x800;
  *(undefined2 *)(iVar2 + 0x48) = 0;
  return;
}
