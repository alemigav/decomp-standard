/* FUN_8016472c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016472c  body 0x8016472c..0x80164837  size 268 B
 * body sha256 cff25f250a10c9a7e69fc1189d3a61f83d19109d511e9643cafaa6f59f37197a
 * provider record sha256 2fc4ee03f7c6944742e95255172ad85bd289a89c21fa263dd0d0282b26a19e05
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016472c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 == 1) {
    *(undefined1 *)(param_1 + 7) = 2;
    FUN_80162f54(param_1,0x41,0xfffffec0);
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        *(undefined1 *)(param_1 + 0x2b5) = 0;
        *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
        *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 2;
        return;
      }
      return;
    }
    if (bVar1 != 2) {
      return;
    }
  }
  func_0x80032b5c(param_1,0);
  func_0x80089d54(param_1,param_2,param_3,0x200);
  sVar2 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar2 + -1;
  if (sVar2 == 1) {
    *(undefined2 *)(param_1 + 6) = 0x100;
    *(undefined2 *)(param_1 + 0x1e0) = 0x118;
    *(undefined1 *)(param_1 + 0x2b5) = 1;
    func_0x80077d18(3);
  }
  return;
}
