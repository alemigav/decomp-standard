/* FUN_80165e40
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165e40  body 0x80165e40..0x80165ec7  size 136 B
 * body sha256 d2a2394f176dcf84d0947e267a1817c7c4964061f2899afd8ebf813348b623bc
 * provider record sha256 71872372922d5636cbed95f6d0a7a6cc86b9a2fd4af4f637210c74611f43c4a5
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165e40(uint *param_1)

{
  uint uVar1;
  
  param_1[0x7a] = 0xd000700;
  func_0x80089d54();
  uVar1 = func_0x80033604();
  FUN_80167688(param_1,0x2002,(uVar1 & 3) + 1);
  FUN_8016703c(param_1,0,0);
  param_1[1] = 0x7000000;
  *param_1 = *param_1 | 0x42;
  if (*(char *)((int)param_1 + 0x2d6) < '\0') {
    param_1[0xb] = (int)*(short *)(param_1 + 0x6a) + 0x46;
  }
  return;
}
