/* FUN_8003b2dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b2dc  body 0x8003b2dc..0x8003b5e3  size 776 B
 * body sha256 35140f36eaf12879fbab18ad1daacb731e8d7fbe87f9bbe9eec0fb6dc1589be3
 * provider record sha256 25412689f47dc98325bdabb3e777c51cc437c60b78f7e5a6a54c44f9298e2aca
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003b2dc(void)

{
  short *psVar1;
  char *pcVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  ushort uVar8;
  undefined1 *puVar9;
  int iVar10;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar9 = DAT_800ebb94;
  local_18 = 0xfce00000;
  local_14 = 0x19000c8;
  if (*(short *)(DAT_800ebb94 + 0x34) < 0x7d01) {
    if (32000 < *(short *)(DAT_800ebb94 + 0x38)) {
      *DAT_800ebb94 = 0;
      goto LAB_8003b340;
    }
  }
  else {
    *DAT_800ebb94 = 0;
LAB_8003b340:
    *(undefined2 *)(puVar9 + 0x18) = 0;
  }
  puVar9 = DAT_800ebb94;
  if (*(short *)(DAT_800ebb94 + 0x34) < -32000) {
    *DAT_800ebb94 = 0;
  }
  else {
    if (-0x7d01 < *(short *)(DAT_800ebb94 + 0x38)) goto LAB_8003b378;
    *DAT_800ebb94 = 0;
  }
  *(undefined2 *)(puVar9 + 0x18) = 0;
LAB_8003b378:
  local_28 = (int)*(short *)(DAT_800ebb94 + 0x34);
  local_24 = (int)*(short *)(DAT_800ebb94 + 0x36);
  local_20 = (int)*(short *)(DAT_800ebb94 + 0x38);
  FUN_80039b5c(0xa0,0x82,0x3c);
  iVar10 = FUN_800609e0(&local_28,(int)*(short *)(DAT_800ebb94 + 0x22),&local_18,0x30011);
  if (iVar10 == 0) {
    local_24 = FUN_80069f1c(&local_28,2,0x2000,0);
    psVar1 = (short *)(DAT_800ebb94 + 0x22);
    *(int *)(DAT_800ebb94 + 0x14) = local_24 + -10;
    iVar10 = FUN_800609e0(&local_28,(int)*psVar1,&local_18,0x20011);
    puVar9 = DAT_800ebb94;
    if (iVar10 == 0) {
      if (DAT_8011270c == 0) {
        return;
      }
      pcVar2 = DAT_800ebb94 + 9;
      cVar4 = DAT_800ebb94[10];
      cVar5 = DAT_800ebb94[8];
      cVar6 = DAT_800ebb94[9];
      cVar7 = DAT_800ebb94[10];
      *(short *)(DAT_800ebb94 + 0xc) = *(short *)(DAT_800ebb94 + 0xc) - (short)(char)DAT_800ebb94[8]
      ;
      *(short *)(puVar9 + 0xe) = *(short *)(puVar9 + 0xe) - (short)*pcVar2;
      *(short *)(puVar9 + 0x10) = *(short *)(puVar9 + 0x10) - (short)cVar4;
      *(short *)(puVar9 + 0x24) = *(short *)(puVar9 + 0x24) - *(short *)(puVar9 + 0xc);
      *(short *)(puVar9 + 0x26) = *(short *)(puVar9 + 0x26) - *(short *)(puVar9 + 0xe);
      uVar8 = *(ushort *)(puVar9 + 0xc);
      *(short *)(puVar9 + 0x28) = *(short *)(puVar9 + 0x28) - *(short *)(puVar9 + 0x10);
      *(short *)(puVar9 + 0xc) = (short)((uint)uVar8 - (int)cVar5);
      *(short *)(puVar9 + 0xe) = *(short *)(puVar9 + 0xe) - (short)cVar6;
      *(short *)(puVar9 + 0x10) = *(short *)(puVar9 + 0x10) - (short)cVar7;
      *(short *)(puVar9 + 0x24) =
           *(short *)(puVar9 + 0x24) -
           (short)(((int)(((uint)uVar8 - (int)cVar5) * 0x10000) >> 0x10) / 3);
      *(short *)(puVar9 + 0x26) = *(short *)(puVar9 + 0x26) - *(short *)(puVar9 + 0xe) / 3;
      *(short *)(puVar9 + 0x28) = *(short *)(puVar9 + 0x28) - *(short *)(puVar9 + 0x10) / 3;
      FUN_80039738();
      bVar3 = DAT_800ebb94[3];
    }
    else {
      bVar3 = DAT_800ebb94[2];
    }
  }
  else {
    DAT_800e10fc = (int)*(short *)(DAT_800ebb94 + 0x34);
    DAT_800e1100 = (int)*(short *)(DAT_800ebb94 + 0x36);
    DAT_800e1104 = (int)*(short *)(DAT_800ebb94 + 0x38);
    bVar3 = DAT_800ebb94[2];
  }
  (*(code *)(&PTR_FUN_800eb9b0)[bVar3])();
  return;
}
