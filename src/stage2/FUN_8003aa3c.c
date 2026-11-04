/* FUN_8003aa3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003aa3c  body 0x8003aa3c..0x8003ad93  size 856 B
 * body sha256 cec0c057e76568f7e91d994bebb8bf57d42861414c59a94391847d0cd12e3e0e
 * provider record sha256 c8dbe5c2a79a517f4b0ef01d3beca49ae043ac049256e71a3f2054544c757c71
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003aa3c(void)

{
  short *psVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0xfa880000;
  local_1c = 0x15e00fa;
  iVar7 = FUN_80074d64((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38));
  if ((iVar7 == 0) || (*(short *)(DAT_800ebb94 + 0x36) <= iVar7)) {
    *(char *)(DAT_800ebb94 + 0xb) = *(char *)(DAT_800ebb94 + 0xb) + -1;
    local_30 = (int)*(short *)(DAT_800ebb94 + 0x34);
    local_2c = (int)*(short *)(DAT_800ebb94 + 0x36);
    local_28 = (int)*(short *)(DAT_800ebb94 + 0x38);
    FUN_80039b5c(0xa0,0x82,0x3c);
    iVar9 = FUN_80069f1c(&local_30,2,0x2000,0);
    iVar7 = DAT_800ebb94;
    *(int *)(DAT_800ebb94 + 0x14) = iVar9 + -10;
    local_2c = local_2c + 1000;
    iVar9 = FUN_800609e0(&local_30,(int)*(short *)(iVar7 + 0x22),&local_20,
                         *(char *)(iVar7 + 0x1b) + 0x30009);
    local_2c = local_2c + -2000;
    iVar10 = FUN_800609e0(&local_30,(int)*(short *)(DAT_800ebb94 + 0x22),&local_20,
                          *(char *)(DAT_800ebb94 + 0x1b) + 0x30009);
    iVar7 = DAT_800ebb94;
    if ((iVar9 + iVar10 == 0) && (*(char *)(DAT_800ebb94 + 0xb) != '\0')) {
      if (DAT_8011270c == 0) {
        return;
      }
      pcVar2 = (char *)(DAT_800ebb94 + 9);
      cVar3 = *(char *)(DAT_800ebb94 + 10);
      cVar4 = *(char *)(DAT_800ebb94 + 8);
      cVar5 = *(char *)(DAT_800ebb94 + 9);
      cVar6 = *(char *)(DAT_800ebb94 + 10);
      *(short *)(DAT_800ebb94 + 0xc) =
           *(short *)(DAT_800ebb94 + 0xc) - (short)*(char *)(DAT_800ebb94 + 8);
      *(short *)(iVar7 + 0xe) = *(short *)(iVar7 + 0xe) - (short)*pcVar2;
      *(short *)(iVar7 + 0x10) = *(short *)(iVar7 + 0x10) - (short)cVar3;
      *(short *)(iVar7 + 0x24) = *(short *)(iVar7 + 0x24) - *(short *)(iVar7 + 0xc);
      *(short *)(iVar7 + 0x26) = *(short *)(iVar7 + 0x26) - *(short *)(iVar7 + 0xe);
      iVar9 = (uint)*(ushort *)(iVar7 + 0xc) - (int)cVar4;
      *(short *)(iVar7 + 0x28) = *(short *)(iVar7 + 0x28) - *(short *)(iVar7 + 0x10);
      *(short *)(iVar7 + 0xc) = (short)iVar9;
      *(short *)(iVar7 + 0xe) = *(short *)(iVar7 + 0xe) - (short)cVar5;
      *(short *)(iVar7 + 0x10) = *(short *)(iVar7 + 0x10) - (short)cVar6;
      *(short *)(iVar7 + 0x24) = *(short *)(iVar7 + 0x24) - (short)((iVar9 * 0x10000 >> 0x10) / 3);
      *(short *)(iVar7 + 0x26) = *(short *)(iVar7 + 0x26) - *(short *)(iVar7 + 0xe) / 3;
      *(short *)(iVar7 + 0x28) = *(short *)(iVar7 + 0x28) - *(short *)(iVar7 + 0x10) / 3;
      FUN_80039738();
      uVar8 = (uint)*(byte *)(DAT_800ebb94 + 3);
      iVar7 = DAT_800ebb94;
    }
    else {
      DAT_800e10fc = (int)*(short *)(DAT_800ebb94 + 0x34);
      *(ushort *)(DAT_800ebb94 + 0x18) = *(ushort *)(DAT_800ebb94 + 0x18) | 0x80;
      DAT_800e1100 = (int)*(short *)(iVar7 + 0x36);
      DAT_800e1104 = (int)*(short *)(iVar7 + 0x38);
      uVar8 = (uint)*(byte *)(iVar7 + 2);
    }
  }
  else {
    iVar7 = DAT_800ebb94 + 0x34;
    psVar1 = (short *)(DAT_800ebb94 + 0x22);
    *(short *)(DAT_800ebb94 + 0x36) = *(short *)(DAT_800ebb94 + 0x36) + 500;
    FUN_80038a20(0x1a051c00,(int)*psVar1,&DAT_800e9028,iVar7);
    uVar8 = (uint)*(byte *)(DAT_800ebb94 + 2);
    iVar7 = DAT_800ebb94;
  }
  (*(code *)(&PTR_FUN_800eb9b0)[uVar8 + (int)*(char *)(iVar7 + 0x1b)])();
  return;
}
