/* FUN_80164ba4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164ba4  body 0x80164ba4..0x80164c7b  size 216 B
 * body sha256 469ab4262cbe50f82c818b4085cbeac44add7b56bf9b288d947815cfa9490e72
 * provider record sha256 0ac1ac04ed92b24ea7fe3be754610a2a08dade6df82fec075051e59b983db43b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164ba4(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  
  if ((*(byte *)((int)param_1 + 7) & 0xf) == 0) {
    *(undefined1 *)((int)param_1 + 7) = 1;
    FUN_80162f54(param_1,0x41,0xfffffec0);
    *(undefined1 *)((int)param_1 + 0x2ca) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *param_1 = *param_1 | 8;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xfd;
  }
  func_0x80032b5c(param_1,0);
  func_0x80089d54(param_1,param_2,param_3,0x200);
  sVar1 = *(short *)(param_1 + 0x7d);
  *(short *)(param_1 + 0x7d) = sVar1 + -1;
  if (sVar1 == 1) {
    *(undefined2 *)((int)param_1 + 6) = 0x100;
    *(undefined2 *)(param_1 + 0x78) = 0x118;
    *(undefined1 *)((int)param_1 + 0x2b5) = 1;
    func_0x80077d18(3);
  }
  return;
}
