/* FUN_8003af10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003af10  body 0x8003af10..0x8003b14b  size 572 B
 * body sha256 113ad8df73463940a66843dbc28ef21454109f871e86d7ac8e3e17752db25575
 * provider record sha256 27d20bfd6d6aab99d639ebc9a4fd2d33ac3efe83b7371d86e28d7ecba1babea6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003af10(void)

{
  ushort *puVar1;
  char cVar2;
  undefined1 *puVar3;
  uint uVar4;
  ushort uVar5;
  short sVar6;
  undefined2 uVar7;
  
  if (*(short *)(DAT_800ebb94 + 0x4a) != 0) {
    if ((0xf < *(ushort *)(DAT_800ebb94 + 0x16)) && (0x1000 < *(ushort *)(DAT_800ebb94 + 4))) {
      FUN_8003c1d8();
    }
    *(short *)(DAT_800ebb94 + 0x16) = *(short *)(DAT_800ebb94 + 0x16) + 1;
  }
  puVar3 = DAT_800ebb94;
  cVar2 = DAT_800ebb94[0x1b];
  if (cVar2 == '\x01') {
    if (*(short *)(DAT_800ebb94 + 0x42) == 0) {
      DAT_800ebb94[0x1b] = 0;
      return;
    }
    puVar1 = (ushort *)(DAT_800ebb94 + 4);
    *(short *)(DAT_800ebb94 + 0x42) = *(short *)(DAT_800ebb94 + 0x42) + -1;
    *(short *)(puVar3 + 4) = (short)(((uint)*puVar1 * 0x3de) / 1000);
    uVar7 = (undefined2)(((uint)*(ushort *)(puVar3 + 6) * 0x3d4) / 1000);
LAB_8003b0bc:
    *(undefined2 *)(puVar3 + 6) = uVar7;
  }
  else {
    if (cVar2 < '\x02') {
      if (cVar2 == '\0') {
        *DAT_800ebb94 = 0;
        *(undefined2 *)(puVar3 + 0x18) = 0;
        return;
      }
      return;
    }
    if (cVar2 == '\x02') {
      if (*(short *)(DAT_800ebb94 + 0x42) != 0) {
        puVar1 = (ushort *)(DAT_800ebb94 + 4);
        uVar5 = *(ushort *)(DAT_800ebb94 + 6);
        *(short *)(DAT_800ebb94 + 0x42) = *(short *)(DAT_800ebb94 + 0x42) + -1;
        *(short *)(puVar3 + 4) = (short)(((uint)*puVar1 * 0x3f1) / 1000);
        uVar7 = (undefined2)(((uint)uVar5 * 0x3ea) / 1000);
        goto LAB_8003b0bc;
      }
      DAT_800ebb94[0x1b] = 1;
      uVar4 = FUN_80033604();
      sVar6 = (short)((uVar4 & 0xff) % 0xb) + 0x5a;
    }
    else {
      if (cVar2 != '\x03') {
        return;
      }
      if (*(short *)(DAT_800ebb94 + 0x42) != 0) {
        *(short *)(DAT_800ebb94 + 0x42) = *(short *)(DAT_800ebb94 + 0x42) + -1;
        return;
      }
      DAT_800ebb94[0x1b] = 2;
      uVar5 = FUN_80033604();
      sVar6 = (uVar5 & 7) + 0x1e;
    }
    *(short *)(DAT_800ebb94 + 0x42) = sVar6;
  }
  return;
}
