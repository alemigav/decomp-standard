/* FUN_8017b5a0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b5a0  body 0x8017b5a0..0x8017b5e7  size 72 B
 * body sha256 95cb2a8c308463acd663d931ae0934bebf27ca52ef7623de6c41e08813491d36
 * provider record sha256 9bdcf12fab61128489c5b78fa5a1301fa6b2504c7a1076150c9ffb0607e911ed
 * callees 1 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017b5a0(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 >> 3 != 0) {
    do {
      *param_1 = 0;
      param_1[1] = param_3;
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 2;
    } while (uVar1 < param_2 >> 3);
  }
  func_0x8000f020();
  return;
}
