/* FUN_80162144
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162144  body 0x80162144..0x801621c3  size 128 B
 * body sha256 ceb6a7d130b97073312a95c71904cffa0e43595de3fe6773c3774a7aba918a22
 * provider record sha256 fd5b5a678dbee5b5265740e6135fac7cbf337cc83d5e9bf101e516c9b5f39e95
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_80162144(uint param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  
  if ((0x20 < *param_2) || (uVar1 = *param_2 - 1, *param_2 = uVar1, uVar1 == 0)) {
    param_1 = param_1 & 0xff;
    *param_2 = param_1;
    uVar1 = func_0x80033604();
    if (param_1 == 0) {
      trap(0x1c00);
    }
    *param_3 = 0x80000000 >> ((uVar1 & 0xff) % param_1 & 0x1f);
  }
  uVar1 = *param_3;
  *param_3 = uVar1 << 1;
  return uVar1 >> 0x1f;
}
