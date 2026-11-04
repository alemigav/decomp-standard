/* FUN_8002ffec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002ffec  body 0x8002ffec..0x8003011b  size 304 B
 * body sha256 9fedf0d2872dcedb819c1f7d2c5e2a24191fa9b1337868996a28c2161eb18e5c
 * provider record sha256 cdddd9348018c24eebe79894cd4f2bb0cc87db51aa2eeffc833ad631ec8077e1
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
int FUN_8002ffec(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = 0x3b9ac9f0 / param_3;
  if (param_3 == 0) {
    trap(0x1c00);
  }
  iVar6 = param_1[1];
  if (uVar7 == 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x3e;
    (**(code **)*param_1)();
  }
  uVar4 = param_4;
  if ((int)uVar7 < (int)param_4) {
    uVar4 = uVar7;
  }
  *(uint *)(iVar6 + 0x4c) = uVar4;
  iVar6 = FUN_8002fd38(param_1,param_2,param_4 << 2);
  uVar7 = 0;
  if (param_4 != 0) {
    uVar5 = param_4;
    while( true ) {
      uVar3 = uVar5;
      if (uVar4 < uVar5) {
        uVar3 = uVar4;
      }
      iVar1 = FUN_8002fef4(param_1,param_2,uVar3 * param_3);
      if (uVar3 != 0) {
        piVar2 = (int *)(uVar7 * 4 + iVar6);
        uVar4 = uVar3;
        do {
          *piVar2 = iVar1;
          piVar2 = piVar2 + 1;
          uVar7 = uVar7 + 1;
          uVar4 = uVar4 - 1;
          iVar1 = iVar1 + param_3;
        } while (uVar4 != 0);
      }
      if (param_4 <= uVar7) break;
      uVar5 = param_4 - uVar7;
      uVar4 = uVar3;
    }
  }
  return iVar6;
}
