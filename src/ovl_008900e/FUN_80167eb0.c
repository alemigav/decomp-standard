/* FUN_80167eb0
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80167eb0  body 0x80167eb0..0x80167f5f  size 176 B
 * body sha256 79cfbc280f449318b2eecafe8083298a38a3026532e832cee27a5cc93e36a271
 * provider record sha256 d30bca76d6951cbbffebf5739d547d5dd3ec67896035482659a55f5b9ef19459
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167eb0(int param_1)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = *(ushort *)(param_1 + 0x2c8);
  if ((uVar1 & 0x40) == 0) {
    if ((uVar1 & 0x200) == 0) {
      if ((*(int *)(param_1 + 700) == 0) &&
         ((int)*(short *)(param_1 + 0x25e) <= *(int *)(param_1 + 0x2c))) {
        cVar2 = func_0x80033144(param_1,0x800e1130);
        if (cVar2 == '\0') {
          *(undefined1 *)(param_1 + 0x26e) = 0;
        }
        else {
          *(undefined1 *)(param_1 + 0x26e) = 1;
        }
      }
      else if ((uVar1 & 0x80) == 0) {
        *(undefined1 *)(param_1 + 0x26e) = 2;
      }
      else {
        *(undefined1 *)(param_1 + 0x26e) = 4;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x26e) = 5;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x26e) = 3;
  }
  return;
}
