/* FUN_801652e4
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801652e4  body 0x801652e4..0x80165363  size 128 B
 * body sha256 349330fdc2b61132455bdb6348303c4cc95fc854b62c566dd3dabc69b8efa594
 * provider record sha256 09407bfbc391a4c3243bf54ae588fae60c9112097bfe8538499866dd612b8e1c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_801652e4(uint param_1,uint *param_2,uint *param_3)

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
