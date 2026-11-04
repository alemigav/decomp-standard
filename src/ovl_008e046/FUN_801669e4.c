/* FUN_801669e4
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x801669e4  body 0x801669e4..0x80166a53  size 112 B
 * body sha256 f27f3e2da40b9ca6f041763eac6e358d56ab4ef5823ae61628863cfb3984b2c2
 * provider record sha256 a698e1229a89e0923d157a7d8c209efca54b99eae68209cf2f9fab2641957d60
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801669e4(int param_1)

{
  char cVar1;
  
  if ((*(int *)(param_1 + 700) == 0) &&
     ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c))) {
    cVar1 = func_0x80033144(param_1,0x800e1130);
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 0x26e) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x26e) = 1;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x26e) = 5;
  }
  return;
}
