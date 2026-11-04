/* FUN_80163608
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80163608  body 0x80163608..0x801636e7  size 224 B
 * body sha256 52d95ee76785fed5c072d95c7b373e2ceebd7168e8191f91821bbef6e2fb495f
 * provider record sha256 5b4e4a2b6362952b03bab9efabc3f0b4cfcb86789148c83d0e36bd9e34737775
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163608(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 uVar2;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(uint *)(param_1 + 0x1e8) = ((uint)*(byte *)(param_1 + 0x2cd) * 0xd + 6) * 0x1000000 + 0x3f00;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar1 != 0) {
    FUN_80163564(param_1);
  }
  func_0x80032b5c(param_1,0);
  if (((**(uint **)(param_1 + 0x214) & 0x10000) != 0) && (*(char *)(param_1 + 0x206) == '\0')) {
    uVar2 = FUN_80166838(param_1);
    *(undefined1 *)(param_1 + 0x206) = uVar2;
  }
  return;
}
