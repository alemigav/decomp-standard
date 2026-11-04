/* FUN_8004b728
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004b728  body 0x8004b728..0x8004bad7  size 944 B
 * body sha256 634b6be1daf3a8ef9305b15259f256616e336d44bdd9789786202ee0f599d1ff
 * provider record sha256 eb3e1649a2fad472bb2a6bf2d4085c3843c63ececb8f215aa1b3f9b9db0cf6be
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004b728(int param_1,byte *param_2,uint param_3,int param_4)

{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  byte bVar7;
  int iVar6;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  DAT_800fe284 = 1;
  bVar2 = param_2[1];
  uVar12 = (uint)*param_2;
  uVar13 = (uint)param_2[2];
  uVar3 = *(ushort *)(param_1 + 0xd020);
  uVar4 = *(ushort *)(param_1 + 0xd022);
  uVar11 = *(byte *)(param_1 + 0xd00c) & 0xf;
  if (*(char *)(param_1 + 0xd02a) != '\0') {
    *(char *)(param_1 + 0xd02a) = *(char *)(param_1 + 0xd02a) + -1;
  }
  if ((DAT_800df918 & 0x1000) == 0) {
    if ((DAT_800df918 & 0x800) != 0) {
      FUN_80077adc(0x4040000,0);
      bVar1 = uVar12 - 1 == uVar11;
      uVar11 = uVar11 + 1;
      if (bVar1) {
        uVar11 = 0;
      }
      *(undefined1 *)(param_1 + 0xd011) = 0;
    }
    if ((DAT_800df918 & 0x400) != 0) {
      FUN_80077adc(0x4040000,0);
      if (uVar11 == 0) {
        uVar11 = uVar12;
      }
      uVar11 = uVar11 - 1;
      *(undefined1 *)(param_1 + 0xd011) = 0;
    }
  }
  else if (*(char *)(param_1 + 0xd02a) == '\0') {
    DAT_800df914 = 0xffff;
    DAT_800e1110 = *(undefined4 *)(param_1 + 0xd02c);
    *(byte *)(param_1 + 0xd00c) = *(byte *)(param_1 + 0xd00c) & 0x7f;
    if (((*(ushort *)(param_1 + 0xd028) & 0x2000) == 0) && ((param_3 & 0x60) == 0)) {
      return;
    }
    if ((*(byte *)(param_1 + 0xd00c) & 0xf) == 0) {
      uVar8 = 0x4060000;
      if ((param_3 & 0x20) != 0) {
        return;
      }
    }
    else {
      uVar8 = 0x4060000;
      if ((*(byte *)(param_1 + 0xd00c) & 0xf) == 1) {
        uVar8 = 0x4050000;
      }
    }
    FUN_80077adc(uVar8,0);
    return;
  }
  bVar7 = *(char *)(param_1 + 0xd011) - 1;
  *(byte *)(param_1 + 0xd011) = bVar7;
  if (DAT_800e9182 == '\0') {
    bVar7 = bVar7 & 0x30;
  }
  else {
    bVar7 = bVar7 & 0x18;
  }
  if (bVar7 != 0) {
    if ((param_3 & 0x80) == 0) {
      uVar10 = *(ushort *)(param_1 + 0xd026) + 0x10;
      uVar9 = (uint)bVar2;
    }
    else {
      uVar10 = (uint)uVar4;
      uVar9 = (uint)uVar3;
    }
    FUN_8004a7c8(uVar9 + uVar13 * uVar11 + -0xe,uVar10,0,0,&DAT_800b8a64,0);
  }
  iVar6 = (uint)*(ushort *)(param_2 + 4) << 1;
  if ((param_3 & 0x80) == 0) {
    uVar10 = 0;
    if (uVar12 != 0) {
      uVar9 = (uint)bVar2;
      do {
        uVar10 = uVar10 + 1;
        iVar5 = iVar6 + param_4;
        iVar6 = iVar6 + 2;
        FUN_8004c21c(uVar9,*(ushort *)(param_1 + 0xd026) + 0x10,
                     &UNK_800fe124 + *(ushort *)(&DAT_800fe200 + iVar5 * 2),param_4 << 0xe | 3);
        uVar9 = uVar9 + uVar13;
      } while (uVar10 < uVar12);
    }
  }
  else {
    uVar10 = 0;
    if (uVar12 != 0) {
      uVar9 = (uint)uVar3;
      do {
        uVar10 = uVar10 + 1;
        iVar5 = iVar6 + param_4;
        iVar6 = iVar6 + 2;
        FUN_8004c21c(uVar9,(uint)uVar4,&UNK_800fe124 + *(ushort *)(&DAT_800fe200 + iVar5 * 2),
                     param_4 << 0xe | 3);
        uVar9 = uVar9 + uVar13;
      } while (uVar10 < uVar12);
    }
  }
  *(byte *)(param_1 + 0xd00c) = *(byte *)(param_1 + 0xd00c) & 0xf0 | (byte)uVar11;
  return;
}
