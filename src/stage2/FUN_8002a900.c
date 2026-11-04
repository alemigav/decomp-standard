/* FUN_8002a900
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002a900  body 0x8002a900..0x8002aa2f  size 304 B
 * body sha256 5ae22442224335e5025432ede782992a2da25d0df9239c4b76cff7f2aeefcd03
 * provider record sha256 82047e7e98fa2266bad3c954dd8b8264feafd263bc6991c1ebe22ee7e4ae7116
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002a900(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = *(int *)(param_1 + 0x168);
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 0x20)) {
    puVar5 = (uint *)(*(int *)(param_1 + 0xb0) + 0x2c);
    do {
      uVar2 = puVar5[-8] * puVar5[-2];
      iVar1 = *(int *)(param_1 + 0x10c);
      iVar8 = (int)uVar2 / iVar1;
      if (iVar1 == 0) {
        trap(0x1c00);
      }
      if ((iVar1 == -1) && (uVar2 == 0x80000000)) {
        trap(0x1800);
      }
      if (uVar2 == 0) {
        trap(0x1c00);
      }
      uVar3 = *puVar5 % uVar2;
      if (*puVar5 % uVar2 == 0) {
        uVar3 = uVar2;
      }
      if (iVar6 == 0) {
        if (iVar8 == 0) {
          trap(0x1c00);
        }
        if ((iVar8 == -1) && (uVar3 - 1 == -0x80000000)) {
          trap(0x1800);
        }
        *(int *)(iVar7 + 0x4c) = (int)(uVar3 - 1) / iVar8 + 1;
      }
      iVar4 = *(int *)(iVar6 * 4 + *(int *)(iVar7 + *(int *)(iVar7 + 0x44) * 4 + 0x3c));
      iVar1 = 0;
      if (0 < iVar8 << 1) {
        uVar2 = uVar3;
        do {
          iVar1 = iVar1 + 1;
          *(undefined4 *)(uVar2 * 4 + iVar4) = *(undefined4 *)(uVar3 * 4 + iVar4 + -4);
          uVar2 = uVar3 + iVar1;
        } while (iVar1 < iVar8 << 1);
      }
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + 0x14;
    } while (iVar6 < *(int *)(param_1 + 0x20));
  }
  return;
}
