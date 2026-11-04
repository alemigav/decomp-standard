/* osSendMesg
 * image   boot (boot), base 0x80000480
 * address 0x8000cb60  body 0x8000cb60..0x8000cc8f  size 304 B
 * body sha256 c162728f19f116815f5e16918d7c2697e5d4992ff8044a7ed6e9e0ac96842dd7
 * provider record sha256 5bb23bf4c0f0b5ef021a6606cd8c03048287a1a31b2c9832e7442998be5e9e38
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 osSendMesg(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
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
  iVar2 = param_1[4];
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (param_1[3] + param_1[2] == -0x80000000)) {
    trap(0x1800);
  }
  *(undefined4 *)(((int)(param_1[3] + param_1[2]) % iVar2) * 4 + param_1[5]) = param_2;
  param_1[2] = param_1[2] + 1;
  if (*(int *)*param_1 != 0) {
    uVar3 = FUN_80000f50(param_1);
    osStartThread(uVar3);
  }
  FUN_80007300(uVar1);
  return 0;
}
