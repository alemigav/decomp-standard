/* FUN_801661b8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801661b8  body 0x801661b8..0x80166247  size 144 B
 * body sha256 be27e8fdb6ca655ab78bd750b55b48403ddbeadd4a571256ee5887b2186181b3
 * provider record sha256 a30b0ec6b9c4afe6c6b30b51953e59500b3f93fe7149767215db6a893c7d50eb
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801661b8(uint *param_1)

{
  uint uVar1;
  
  param_1[0x7a] = 0xd000700;
  func_0x80089d54();
  uVar1 = func_0x80033604();
  FUN_80167688(param_1,0x2002,(uVar1 & 3) + 6);
  FUN_8016703c(param_1,0x13,1);
  FUN_80166248(param_1);
  param_1[1] = 0x7000000;
  *param_1 = *param_1 | 0x42;
  if (*(char *)((int)param_1 + 0x2d6) < '\0') {
    param_1[0xb] = (int)*(short *)(param_1 + 0x6a) + 0x46;
  }
  return;
}
