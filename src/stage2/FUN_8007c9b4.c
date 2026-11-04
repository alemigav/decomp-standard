/* FUN_8007c9b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c9b4  body 0x8007c9b4..0x8007caeb  size 312 B
 * body sha256 7b56afabe6c0aedfd2fcc2008a9fb0733b5ba163ae30bdfdaf36604318ecd64e
 * provider record sha256 3962d0b52309796f99f451acc0eb6aa3a5f4bb588604cfe8cd8acf83a166c83d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c9b4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = DAT_8011b54c;
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 0x1ed) = 0;
    iVar3 = (int)*(short *)(param_1 + 0x1fe);
    iVar4 = (int)*(short *)(param_1 + 0x1f2) << 0xc;
    iVar5 = iVar4 / iVar3;
    if (iVar3 == 0) {
      trap(0x1c00);
    }
    if ((iVar3 == -1) && (iVar4 == -0x80000000)) {
      trap(0x1800);
    }
    if ((DAT_800e900f & 1) != 0) {
      *(undefined1 *)(param_1 + 0x1ed) = 1;
    }
    if (iVar5 < 2000) {
      *(undefined1 *)(param_1 + 0x1ed) = 1;
    }
    if (iVar5 < 800) {
      *(undefined1 *)(param_1 + 0x1ed) = 2;
    }
  }
  if (iVar1 != 0) {
    (*(code *)(&PTR_LAB_8011b25c)[*(byte *)((int)&PTR_LAB_8011b210 + (uint)*(byte *)(iVar1 + 8))])
              (param_1,*(undefined2 *)(param_1 + 0x1aa));
  }
  iVar1 = FUN_80032e74(param_1,(int)*(short *)(param_1 + 0x2b4),(int)*(short *)(param_1 + 0x2b6),
                       0x400);
  if (*(ushort *)(param_1 + 0x2ba) < 0xbb9) {
    if (*(ushort *)(param_1 + 0x2ba) < 0x1771) {
      return;
    }
    uVar2 = 0x10d0000;
    if (iVar1 == 0) {
      uVar2 = 0x1020000;
    }
  }
  else {
    uVar2 = 0x1010000;
    if (iVar1 != 0) {
      uVar2 = 0x10c0000;
    }
  }
  *(undefined4 *)(param_1 + 4) = uVar2;
  return;
}
