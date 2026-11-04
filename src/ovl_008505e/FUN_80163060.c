/* FUN_80163060
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163060  body 0x80163060..0x801630ff  size 160 B
 * body sha256 76779ee3528d27b5aeccb556eddb923e9e6abbe0b7da233744342813797343e6
 * provider record sha256 b14f8c0c8f2ebc92ec87c4a9b09ce21034cc4033f97217f7a935ea5b1234af87
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80163060(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  func_0x80032bd8(param_1,0,0);
  *(short *)(param_1 + 0x1e2) = *(short *)(param_1 + 0x1e2) + 0x28;
  iVar1 = FUN_801668fc(param_1);
  uVar2 = (uint)(iVar1 == 1);
  if ((*(short *)(param_1 + 0x1e2) < 0) || (uVar2 != 0)) {
    if (*(char *)(param_1 + 0x1e9) != '\0') {
      func_0x80089d54(param_1,param_2,param_3,0x200);
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
