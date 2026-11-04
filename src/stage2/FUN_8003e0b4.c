/* FUN_8003e0b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003e0b4  body 0x8003e0b4..0x8003e3f3  size 832 B
 * body sha256 22b4d5e1b7dabf8eb2815dd0de470218dc60867f0fa2f46b3539ba1f3788d3a2
 * provider record sha256 10efea9998b409e8d7d737d1684b68239fcf147631c15c3084b3b1d8bc92b24a
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003e0b4(void)

{
  short *psVar1;
  short *psVar2;
  ushort uVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int unaff_s0;
  int local_28;
  int local_24;
  int local_20;
  
  if (DAT_800ebb94[0x21] == '\n') {
    DAT_800ebb94[0x21] = 6;
    DAT_800ebb94[0x20] =
         *(undefined1 *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)(byte)DAT_800ebb94[0x21] * 8 + 2);
  }
  iVar6 = FUN_8004d79c(DAT_800ebb94 + 0x34,0x96,
                       1 << (((int)*(short *)(DAT_800ebb94 + 0x36) / 0x708) * -0x10000 >> 0x10 &
                            0x1fU));
  if (iVar6 == 0) {
    psVar1 = (short *)(DAT_800ebb94 + 0x34);
    psVar2 = (short *)(DAT_800ebb94 + 0x38);
    *(short *)(DAT_800ebb94 + 6) = *(short *)(DAT_800ebb94 + 6) + 0x78;
    iVar6 = FUN_80074d64((int)*psVar1,(int)*psVar2);
    if ((iVar6 != 0) && (iVar6 < *(short *)(DAT_800ebb94 + 0x36))) {
      DAT_800ebb94[0x21] = 0xb;
      DAT_800ebb94[0x20] =
           *(undefined1 *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)(byte)DAT_800ebb94[0x21] * 8 + 2);
      puVar4 = DAT_800ebb94;
      DAT_800ebb94[1] = 0;
      *puVar4 = 0;
      puVar5 = DAT_800ebb94;
      *(undefined2 *)(puVar4 + 6) = 0x1000;
      *(undefined2 *)(puVar5 + 0xe) = 0;
      puVar5[9] = 0;
    }
    local_28 = (int)*(short *)(DAT_800ebb94 + 0x34);
    local_24 = (int)*(short *)(DAT_800ebb94 + 0x36);
    local_20 = (int)*(short *)(DAT_800ebb94 + 0x38);
    iVar6 = FUN_80069f1c(&local_28,2,0x2000,1);
    if (iVar6 < *(short *)(DAT_800ebb94 + 0x36)) {
      DAT_800ebb94[0x21] = 8;
      DAT_800ebb94[0x20] =
           *(undefined1 *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)(byte)DAT_800ebb94[0x21] * 8 + 2);
      puVar4 = DAT_800ebb94;
      DAT_800ebb94[1] = 0;
      *puVar4 = 0;
      puVar4 = DAT_800ebb94;
      DAT_800ebb94[9] = 0;
      puVar5 = DAT_800ebb94;
      *(undefined2 *)(puVar4 + 0xe) = 0;
      *(short *)(puVar5 + 0x36) = (short)iVar6;
    }
  }
  else {
    if (unaff_s0 == 2) {
      FUN_80052d10(4,0x78,0x14,0);
    }
    DAT_800ebb94[0x21] = 0xb;
    DAT_800ebb94[0x20] =
         *(undefined1 *)(*(int *)(DAT_800ebb94 + 0x70) + (uint)(byte)DAT_800ebb94[0x21] * 8 + 2);
    puVar4 = DAT_800ebb94;
    DAT_800ebb94[1] = 0;
    *puVar4 = 0;
    puVar5 = DAT_800ebb94;
    *(undefined2 *)(puVar4 + 6) = 0x1000;
    *(undefined2 *)(puVar5 + 0xe) = 0;
    puVar5[9] = 0;
    uVar7 = FUN_80033604();
    uVar3 = *(ushort *)(DAT_800ebb94 + 0x3a);
    uVar8 = FUN_80033604();
    FUN_80038a20((uint)uVar3 + (uVar7 & 7) * 0x80 | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) -
                       (((uVar8 & 0xff) % 10) * 0xc + -0x270)) * 0x10000) >> 0x10,&DAT_800e9028,
                 DAT_800ebb94 + 0x34);
    uVar7 = FUN_80033604();
    uVar3 = *(ushort *)(DAT_800ebb94 + 0x3a);
    uVar8 = FUN_80033604();
    FUN_80038a20((uint)uVar3 + (uVar7 & 7) * 0x80 | 0x1a000000,
                 (int)(((uint)*(ushort *)(DAT_800ebb94 + 0x22) + ((uVar8 & 0xff) % 10) * 0xc + 0xd90
                       ) * 0x10000) >> 0x10,&DAT_800e9028,DAT_800ebb94 + 0x34);
  }
  return;
}
