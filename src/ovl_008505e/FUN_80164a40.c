/* FUN_80164a40
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164a40  body 0x80164a40..0x80164b6f  size 304 B
 * body sha256 b816c8618a5a6af031eea526536c9e5b0c14b6c7fc25e226ae25b3aef8331b65
 * provider record sha256 da648d3851e08030bc85e7ef3c3378440dc169691dcc25ec106bb51e67404996
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164a40(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)((int)param_1 + 7) == '\0') {
    func_0x80032bd8(param_1,0x800,0);
    *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
    if ((int)*(short *)((int)param_1 + 0x25e) <= (int)param_1[0xb]) {
      *(undefined1 *)((int)param_1 + 7) = 1;
      *(undefined1 *)((int)param_1 + 0x2b5) = 0;
      param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
      *param_1 = *param_1 & 0xefffffff | 0x4000000;
      func_0x80077d18(10,param_1);
    }
    if (*(byte *)((int)param_1 + 0x1e9) < 0x11) {
      func_0x80089d54(param_1,param_2,param_3,0x100);
    }
    else {
      *(undefined2 *)(param_1 + 0x78) = 0;
    }
  }
  else {
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar1 != 0) {
      *(undefined1 *)((int)param_1 + 5) = 0xd;
      *(undefined2 *)((int)param_1 + 6) = 0x100;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    }
  }
  if (*(short *)(param_1 + 0x7d) < 0x400) {
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x100;
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 0x100;
  }
  return;
}
