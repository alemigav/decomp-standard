/* FUN_8007f770
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f770  body 0x8007f770..0x8007f957  size 488 B
 * body sha256 44ded799d08f6d37160a746705024023efad1f0ece0eb1beb51a1b8d3c0d4f8b
 * provider record sha256 b19490c129bae2c5b0dd8fd6549c585a2bfecdc753869ffa281da67a3b176238
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f770(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  
  uVar2 = DAT_8011b560;
  iVar3 = DAT_8011b54c;
  iVar4 = FUN_80032e74(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),
                       0x400);
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 0x1ed) = 0;
    iVar6 = (int)*(short *)(param_1 + 0x1fe);
    iVar8 = (int)*(short *)(param_1 + 0x1f2) << 0xc;
    iVar9 = iVar8 / iVar6;
    if (iVar6 == 0) {
      trap(0x1c00);
    }
    if ((iVar6 == -1) && (iVar8 == -0x80000000)) {
      trap(0x1800);
    }
    if ((DAT_800e900f & 1) != 0) {
      *(undefined1 *)(param_1 + 0x1ed) = 1;
    }
    if (iVar9 < 2000) {
      *(undefined1 *)(param_1 + 0x1ed) = 1;
    }
    if (iVar9 < 800) {
      *(undefined1 *)(param_1 + 0x1ed) = 2;
    }
  }
  uVar1 = *(ushort *)(param_1 + 0x2b8);
  if ((uVar1 & 0x2000) != 0) {
    if ((iVar3 != 0) && (uVar2 < 6000)) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
    }
    if (2999 < *(ushort *)(param_1 + 0x2ba)) {
      return;
    }
    cVar7 = *(char *)(param_1 + 6);
    if (cVar7 == '\x05') {
      *(undefined1 *)(param_1 + 6) = 6;
      cVar7 = *(char *)(param_1 + 6);
    }
    if (cVar7 == '\x01') {
      *(undefined1 *)(param_1 + 6) = 0;
      *(ushort *)(param_1 + 0x2b8) = *(ushort *)(param_1 + 0x2b8) & 0xdfff;
      return;
    }
    return;
  }
  uVar2 = *(ushort *)(param_1 + 0x2ba);
  if (uVar2 < 8000) {
    if (0x5dc < uVar2) {
      uVar5 = 0x1010000;
      if (iVar4 != 0) {
        uVar5 = 0x10c0000;
      }
      goto LAB_8007f93c;
    }
    if (2000 < uVar2) {
      uVar5 = 0x1020000;
      if (iVar4 != 0) {
        uVar5 = 0x10d0000;
      }
      goto LAB_8007f93c;
    }
  }
  else {
    *(ushort *)(param_1 + 0x2b8) = uVar1 | 0x2000;
    *(undefined2 *)(param_1 + 500) = 0;
    *(ushort *)(param_1 + 0x2b8) = uVar1 & 0xefff | 0x2000;
  }
  if ((*(ushort *)(param_1 + 0x2ba) < 200) && (*(byte *)(param_1 + 6) < 2)) {
    *(undefined4 *)(param_1 + 4) = 0x1000200;
  }
  if (*(ushort *)(param_1 + 0x2ba) < 0x191) {
    return;
  }
  uVar5 = 0x1000000;
  if (*(byte *)(param_1 + 6) < 2) {
    return;
  }
LAB_8007f93c:
  *(undefined4 *)(param_1 + 4) = uVar5;
  return;
}
