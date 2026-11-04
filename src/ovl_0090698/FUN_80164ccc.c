/* FUN_80164ccc
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164ccc  body 0x80164ccc..0x80164db7  size 236 B
 * body sha256 5a5861e664e80df510d388892274c8f92a6ecd022310a83fdcabe32a949645f9
 * provider record sha256 cd9e2d5dc734a801b3d147233ff514b2174a3555e1c783040a3fc3df277146fd
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164ccc(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  func_0x80032bd8(param_1,0,(int)*(short *)(param_1 + 0x7d));
  *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
  if (*(short *)(param_1 + 0x7d) != 0) {
    *(short *)(param_1 + 0x1a) = *(short *)(param_1 + 0x1a) + 0x200;
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + -0x200;
  }
  if ((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) {
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    *param_1 = *param_1 & 0xefffffff | 0xc000000;
    if (*(short *)(param_1 + 0x7d) == 0) {
      *(undefined1 *)((int)param_1 + 6) = 2;
      param_1[0x7a] = 0x9000300;
    }
    uVar1 = 5;
    if (*(char *)((int)param_1 + 0x2d6) < '\0') {
      uVar1 = 6;
    }
    func_0x80077d18(uVar1,param_1);
  }
  func_0x80089d54(param_1,param_2,param_3,0x400);
  return;
}
