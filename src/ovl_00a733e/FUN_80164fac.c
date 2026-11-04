/* FUN_80164fac
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80164fac  body 0x80164fac..0x80165093  size 232 B
 * body sha256 4a8162279b71c5d57b63d1239854a06b4237bc44908e12b6780905b4e33233e6
 * provider record sha256 923c130e506119806b8144ba92015fca8cf5070646ecd154c12eeaabc70aab4c
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164fac(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x2b4) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0x6000f00;
    func_0x800334c8();
    func_0x80089d54(param_1,param_2,param_3,0x100);
    func_0x80077d18(0xb,param_1);
  }
  else {
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1020000;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
      *(undefined1 *)(param_1 + 0x2d0) = 0;
    }
    func_0x80032b5c(param_1,0);
  }
  return;
}
