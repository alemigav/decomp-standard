/* FUN_80031050
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80031050  body 0x80031050..0x800310af  size 96 B
 * body sha256 3f041bdf7e349cbcc1f3062d74f2b52c8bd1142a289a1066c97b3aa78e9f4a69
 * provider record sha256 d5b00ff49adbd35112264e1185b35501ee3318e69cc239fbd153d3dd2f42af5c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80031050(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_80030fd0();
  iVar2 = FUN_80030fd0(param_1);
  for (iVar1 = iVar1 * 0x100 + iVar2 + -3; -1 < iVar1; iVar1 = iVar1 + -1) {
    FUN_80030fd0(param_1);
  }
  return 1;
}
