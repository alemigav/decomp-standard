/* FUN_8016622c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016622c  body 0x8016622c..0x8016626f  size 68 B
 * body sha256 4bbb0c9ef65682bf7bd168670f9dc19254bd1de2328a04930161107c0a766971
 * provider record sha256 66c395c39f58d7a588c4a69a511f3fc31c1126e7cebafad0b30fb73bf72d284b
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016622c(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = &DAT_800e1130;
  }
  else {
    puVar1 = _DAT_800e13ec;
  }
  puVar1[4] = 3;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  return;
}
