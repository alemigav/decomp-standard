/* FUN_800258d8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800258d8  body 0x800258d8..0x80025a5f  size 392 B
 * body sha256 5a0af92ffc7d3c9ebb074903457809ce579a6b1fdca7c68bf8b6198d5e0ef0ca
 * provider record sha256 5f6602d44228cd3b3cf831a2fd0aa93283a9b3d0e915b8d569b8a760a4146116
 * callees 15 direct (15 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800258d8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  func_0x80004954();
  FUN_80026980(0xc);
  DAT_800e910c = 0xffffffff;
  DAT_800c56e8 = DAT_8010b6e8;
  FUN_80025ba8(0xc);
  FUN_8006be10();
  func_0x8000e350(1);
  iVar3 = DAT_801137f0 * DAT_801137f4 * 2;
  puVar1 = DAT_8010b6e0;
  if (DAT_8010b6e4 < DAT_8010b6e0) {
    puVar1 = DAT_8010b6e4;
  }
  while (iVar3 = iVar3 + -1, iVar3 != -1) {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  }
  FUN_8008af50(3);
  DAT_800c4ea0 = FUN_8008b0ec(15000);
  DAT_800c56e4 = DAT_800c4ea0 + 15000;
  FUN_8008af50(1);
  FUN_80025474(param_1);
  FUN_800254f4(param_2);
  FUN_80025574(param_3);
  FUN_8002584c(param_4);
  FUN_800850e0();
  uVar2 = FUN_8008b048(1);
  DAT_8010b6d0 = FUN_8004cfcc(uVar2);
  FUN_8008af50(3);
  DAT_800c52d8 = FUN_8008af80(0xaf800);
  DAT_800c52dc = FUN_8008af80(0x5c000);
  FUN_8008af50(1);
  return;
}
