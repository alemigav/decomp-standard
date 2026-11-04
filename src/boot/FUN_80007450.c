/* FUN_80007450
 * image   boot (boot), base 0x80000480
 * address 0x80007450  body 0x80007450..0x80007583  size 308 B
 * body sha256 61c32ec2b825709b96563d9d1b3bb76ff4d39f01139cfbf1ac422b4fbade5f3d
 * provider record sha256 b40203d6c447733beb7bb38e14d52348bb55977406d2f431f97fd4fb6f3d9328
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80007450(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = FUN_800072e0();
  if ((int)param_1[4] <= (int)param_1[2]) {
    do {
      if (param_3 != 1) {
        FUN_80007300(uVar1);
        return 0xffffffff;
      }
      *(undefined2 *)(_DAT_80012950 + 0x10) = 8;
      FUN_80000dd4(param_1 + 1);
    } while ((int)param_1[4] <= (int)param_1[2]);
  }
  iVar4 = param_1[4];
  iVar2 = param_1[3] + iVar4 + -1;
  iVar5 = iVar2 % iVar4;
  if (iVar4 == 0) {
    trap(0x1c00);
  }
  if ((iVar4 == -1) && (iVar2 == -0x80000000)) {
    trap(0x1800);
  }
  param_1[3] = iVar5;
  *(undefined4 *)(iVar5 * 4 + param_1[5]) = param_2;
  param_1[2] = param_1[2] + 1;
  if (*(int *)*param_1 != 0) {
    uVar3 = FUN_80000f50(param_1);
    osStartThread(uVar3);
  }
  FUN_80007300(uVar1);
  return 0;
}
